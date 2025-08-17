#include <func.h>
int sendfd(int sockfd, int fdtosend){
    struct msghdr hdr;
    bzero(&hdr,sizeof(hdr)); // name->NULL namelen->0 不可省略
    // 无论正文部分在业务中是否有用，必须要有正文
    char buf[] = "hello"; // 正文的数据
    struct iovec vec[1]; // 数组记录离散区域
    vec[0].iov_base = buf; // 第一个离散碎片的首地址
    vec[0].iov_len = 5;
    hdr.msg_iov = vec; // 将离散区域的信息放入hdr中
    hdr.msg_iovlen = 1;
    // 控制字段部分，记录要发送的内核数据结构
    struct cmsghdr * pcmsg = (struct cmsghdr *)malloc( /*data: fd --> int*/ CMSG_LEN(sizeof(int)));
    pcmsg->cmsg_len = CMSG_LEN(sizeof(int));
    pcmsg->cmsg_level = SOL_SOCKET;
    pcmsg->cmsg_type = SCM_RIGHTS;
    // 通过pcmsg得到data首地址，强转成int*，再解引用
    *(int *)CMSG_DATA(pcmsg) = fdtosend;
    hdr.msg_control = pcmsg; // 将控制字段的信息放入hdr中
    hdr.msg_controllen = CMSG_LEN(sizeof(int));
    int ret = sendmsg(sockfd,&hdr,0);
    ERROR_CHECK(ret,-1,"sendmsg");
    return 0;
}
int recvfd(int sockfd, int *pfdtorecv){
    // 接收和发送的区别， 接收方不知道buf和pcmsg->data的内容
    struct msghdr hdr;
    bzero(&hdr,sizeof(hdr)); // name->NULL namelen->0 不可省略
    // 无论正文部分在业务中是否有用，必须要有正文
    char buf[6] = {0}; // 正文的数据
    struct iovec vec[1]; // 数组记录离散区域
    vec[0].iov_base = buf; // 第一个离散碎片的首地址
    vec[0].iov_len = 5;
    hdr.msg_iov = vec; // 将离散区域的信息放入hdr中
    hdr.msg_iovlen = 1;
    // 控制字段部分，记录要发送的内核数据结构
    struct cmsghdr * pcmsg = (struct cmsghdr *)malloc( /*data: fd --> int*/ CMSG_LEN(sizeof(int)));
    pcmsg->cmsg_len = CMSG_LEN(sizeof(int));
    pcmsg->cmsg_level = SOL_SOCKET;
    pcmsg->cmsg_type = SCM_RIGHTS;
    hdr.msg_control = pcmsg; // 将控制字段的信息放入hdr中
    hdr.msg_controllen = CMSG_LEN(sizeof(int));
    int ret = recvmsg(sockfd,&hdr,0);
    ERROR_CHECK(ret,-1,"sendmsg");
    printf("buf = %s, fd = %d\n", buf, 
           *(int *)CMSG_DATA(pcmsg));
    *pfdtorecv = *(int *)CMSG_DATA(pcmsg);
    return 0;
}

int main(int argc,char*argv[])
{
    int fds[2];
    //pipe(fd);
    socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
    // fds[0] read <--- fds[1] write
    // fds[0] write ---> fds[1] read
    if(fork()){
        // 父进程
        close(fds[0]);
        int fdfile = open("file1",O_RDWR);
        printf("parent fdfile = %d\n", fdfile);
        write(fdfile,"hello",5);
        sendfd(fds[1],fdfile);

        wait(NULL);
    }
    else{
        // 子进程
        //close(fds[1]);
        int fdfile;
        recvfd(fds[0],&fdfile);
        printf("child fdfile = %d\n",fdfile);
        ssize_t sret = write(fdfile,"world",5);
        printf("sret = %ld\n", sret);
    }
    return 0;
}


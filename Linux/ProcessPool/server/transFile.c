#include "head.h"
// 1.0
//int transFile(int netfd){
//   char filename[] = "file1"; 
//   send(netfd,filename,5,0);
//   int fd = open(filename,O_RDWR);
//   char buf[1000] = {0};
//   ssize_t sret = read(fd,buf,sizeof(buf));
//   send(netfd,buf,sret,0);
//   return 0;
//}
// 2.0
typedef struct train_s {
    int length; // 火车头
    char data[1000]; // 火车车厢
    // char数组 不是表示字符串 可以保存任何数据
    // 1000 不是火车车厢实际大小，是上限
} train_t;
//int transFile(int netfd){
//    train_t train;
//    char filename[] = "file1"; 
//    // 组装小火车
//    train.length = strlen(filename);
//    memcpy(train.data,filename,train.length);
//    // 发送小火车 头长度+车厢长度
//    send(netfd,&train,sizeof(train.length)+train.length,0);
//
//    int fd = open(filename,O_RDWR);
//    ssize_t sret = read(fd,train.data,sizeof(train.data));
//    train.length = sret;
//    send(netfd,&train,sizeof(train.length)+train.length,0);
//    close(fd);
//    return 0;
//}
// 3.0
//int transFile(int netfd){
//    train_t train;
//    char filename[] = "file1"; 
//    // 组装小火车
//    train.length = strlen(filename);
//    memcpy(train.data,filename,train.length);
//    // 发送小火车 头长度+车厢长度
//    send(netfd,&train,sizeof(train.length)+train.length,MSG_NOSIGNAL);
//
//    int fd = open(filename,O_RDWR);
//    while(1){
//        ssize_t sret = read(fd,train.data,sizeof(train.data));
//        train.length = sret;
//        ssize_t sret1 = send(netfd,&train,sizeof(train.length)+train.length,MSG_NOSIGNAL);
//        if(sret == 0 || sret1 == -1){
//            break;
//        }
//        sleep(1);
//    }
//    close(fd);
//    return 0;
//}
// 4.0 加上进度条
//int transFile(int netfd){
//    train_t train;
//    char filename[] = "file1"; 
//    // 组装小火车
//    train.length = strlen(filename);
//    memcpy(train.data,filename,train.length);
//    // 发送小火车 头长度+车厢长度
//    send(netfd,&train,sizeof(train.length)+train.length,MSG_NOSIGNAL);
//
//    struct stat statbuf;
//    int fd = open(filename,O_RDWR);
//    fstat(fd,&statbuf);
//    train.length = sizeof(off_t);
//    memcpy(train.data,&statbuf.st_size,train.length);
//    send(netfd,&train,sizeof(train.length)+train.length,MSG_NOSIGNAL);
//
//    while(1){
//        ssize_t sret = read(fd,train.data,sizeof(train.data));
//        train.length = sret;
//        ssize_t sret1 = send(netfd,&train,sizeof(train.length)+train.length,MSG_NOSIGNAL);
//        if(sret == 0 || sret1 == -1){
//            break;
//        }
//    }
//    close(fd);
//    return 0;
//}
// 4.1 使用mmap而不是栈
//int transFile(int netfd){
//    train_t train;
//    char filename[] = "file1"; 
//    // 组装小火车
//    train.length = strlen(filename);
//    memcpy(train.data,filename,train.length);
//    // 发送小火车 头长度+车厢长度
//    send(netfd,&train,sizeof(train.length)+train.length,MSG_NOSIGNAL);
//
//    struct stat statbuf;
//    int fd = open(filename,O_RDWR); // open 必须用O_RDWR
//    fstat(fd,&statbuf);
//    train.length = sizeof(off_t);
//    memcpy(train.data,&statbuf.st_size,train.length);
//    send(netfd,&train,sizeof(train.length)+train.length,MSG_NOSIGNAL);
//
//    char *p = (char *)mmap(NULL,statbuf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
//    ERROR_CHECK(p,MAP_FAILED,"mmap");
//    off_t cursize = 0;
//    while(1){
//        if(cursize >= statbuf.st_size){
//            break;
//        }
//        if(statbuf.st_size - cursize >= 1000){
//            train.length = 1000;
//        }
//        else{
//            train.length = statbuf.st_size - cursize;
//        }
//
//        send(netfd,&train.length,sizeof(train.length),MSG_NOSIGNAL);
//        // 每一节车厢的数据从映射区发送过去的
//        send(netfd,p+cursize,train.length,MSG_NOSIGNAL);
//        cursize += train.length;
//    }
//    train.length = 0;
//    send(netfd,&train.length,sizeof(train.length),MSG_NOSIGNAL);
//    munmap(p,statbuf.st_size);
//    close(fd);
//    return 0;
//}
//5.0 使用大火车
int transFile(int netfd){
    train_t train;
    char filename[] = "file1"; 
    // 组装小火车
    train.length = strlen(filename);
    memcpy(train.data,filename,train.length);
    // 发送小火车 头长度+车厢长度
    send(netfd,&train,sizeof(train.length)+train.length,MSG_NOSIGNAL);

    struct stat statbuf;
    int fd = open(filename,O_RDWR); // open 必须用O_RDWR
    fstat(fd,&statbuf);
    train.length = sizeof(off_t);
    memcpy(train.data,&statbuf.st_size,train.length);
    send(netfd,&train,sizeof(train.length)+train.length,MSG_NOSIGNAL);

    //char *p = (char *)mmap(NULL,statbuf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    //ERROR_CHECK(p,MAP_FAILED,"mmap");
    //send(netfd,p,statbuf.st_size,MSG_NOSIGNAL);
    //munmap(p,statbuf.st_size);
    
    sleep(10);
    printf("done!\n");
    sendfile(netfd,fd,NULL,statbuf.st_size);
    close(fd);
    return 0;
}


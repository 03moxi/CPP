#include <func.h>
#include <openssl/sha.h>
int main(int argc, char *argv[])
{
    SHA_CTX ctx;
    SHA1_Init(&ctx);
    int fd = open("file1",O_RDWR);
    char buf[4096] = {0};
    while(1){
        bzero(buf,4096);
        ssize_t sret = read(fd,buf,4096);
        if(sret == 0){
            break;
        }
        SHA1_Update(&ctx,buf,sret);
    }
    unsigned char md[20] = {0};
    // md将要存储哈希值的二进制形式
    SHA1_Final(md,&ctx);
    for(int i = 0; i < 20; ++i){
        printf("%02x", md[i]);
    }
    printf("\n");
    return 0;

}

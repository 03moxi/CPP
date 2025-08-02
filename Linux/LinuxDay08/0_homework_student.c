#include <func.h>
typedef struct student_s {
    int num;
    char name[30]; // char *name;
    float score;
} student_t;
int main(int argc, char *argv[])
{
    // ./0_homework_student file1
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");

    student_t stu[3] = {
        {1,"Caixukun",88.8},
        {2,"Wuyifan",59.9},
        {3,"Liyifeng",77.7}
    };

    write(fd,stu,sizeof(stu));

    student_t arr[3];
    lseek(fd,0,SEEK_SET);
    read(fd,arr,sizeof(stu));
    for(int i = 0; i < 3; ++i){
        printf("num = %d,score = %f,name = %s\n",
               arr[i].num,arr[i].score,arr[i].name);
    }
    return 0;
}

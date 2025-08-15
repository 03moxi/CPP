#include <func.h>
#include <mysql/mysql.h>

int main(int argc, char *argv[])
{
    MYSQL* mysql = mysql_init(NULL);
    MYSQL* cret = mysql_real_connect(mysql,"localhost","root","123456","54test",0,NULL,0);
    if(cret == NULL){
        fprintf(stderr,"mysql_real_connect:%s\n",mysql_error(mysql));
        return -1;
    }
    //char sql[4096] = "insert into star (name,product) values ('Baijingting','shangchunshan');";
    // strcat sprintf
    char name[] = "'Inned'";
    // SQL 注入
    char sex[] = "'f'";
    char sql[4096] = {0};
    sprintf(sql,"insert into owner (name,sex) values (%s,%s);",name, sex);
    int qret = mysql_query(mysql,sql);
    if(qret != 0){
        fprintf(stderr,"mysql_query:%s\n", mysql_error(mysql));
        return -1;
    }
    mysql_close(mysql);
    return 0;
}


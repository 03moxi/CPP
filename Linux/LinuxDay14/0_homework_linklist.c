#include <func.h>

typedef struct node_s{
    int data;
    struct node_s* nextNode;
}node_t;

typedef struct list_s{
    node_t* Head;
    node_t* Tail;
}list_t;

void headInsert(list_t* Node,int ret){
    node_t* newNode = (node_t *)calloc(1,sizeof(node_t));
    newNode->data = ret;
    if(Node->Head == NULL){
        Node->Head = newNode;
        Node->Tail = newNode;
    }
    else{
        newNode->nextNode = Node->Head;
        Node->Head = newNode;
    }
}

void tailInsert(list_t* Node,int ret){
    node_t* newNode = (node_t *)calloc(1,sizeof(node_t));
    newNode->data = ret;
    if(Node->Tail == NULL){
        Node->Head = newNode;
        Node->Tail = newNode;
    }
    else{
        Node->Tail->nextNode = newNode;
        Node->Tail = newNode;
    }
}

void visitList(list_t* Node){
    node_t* curr = Node->Head;
    while(curr){
        printf("%d ",curr->data);
        curr = curr->nextNode;
    }
    printf("\n");
}

//int main(int argc,char*argv[])
//{   
//    list_t* newNode = (list_t *)calloc(1,sizeof(list_t));
//
//    for(int i = 0;i < 10;i++){
//        headInsert(newNode,i);
//        tailInsert(newNode,i);
//        visitList(newNode);
//    }
//
//    return 0;
//}

void *threadFunc(void *arg){
    list_t* list = (list_t *)arg;
    printf("I am child!\n");
    visitList(list);
    return NULL;
}

int main()
{
    list_t* list = (list_t *)calloc(1,sizeof(1));
    for(int i = 0; i < 9; ++i){
        tailInsert(list,i);
    }
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,list);
    sleep(1);
    return 0;
}

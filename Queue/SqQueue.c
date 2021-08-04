#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h"

void InitQueue(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
}

int QueueEmpty(SqQueue *Q){
    if(Q->front == Q->rear)
        return 1;//empty
    else
        return 0;
}

int EnQueue(SqQueue *Q, int x){
    if(Q->rear-Q->front == MaxSize){
        printf("队列已满，无法入队\n");
        return 0;
    }
    Q->data[Q->rear] = x;
    Q->rear++;
    printf("插入 %d 成功！\n", x);
    return 1;
}

int DeQueue(SqQueue *Q){
    if(QueueEmpty(Q)==1){
        printf("队列已空，无法出队\n");
        return 0;
    }
    int x;
    x = Q->data[Q->front];
    Q->front++;
    printf("%d 出队成功！\n", x);
    return x;
}

int GetHead(SqQueue *Q){
    return Q->data[Q->front];
}
int ShowQueue(SqQueue *Q){
    if(QueueEmpty(Q)==1){
        printf("队列已空\n");
        return 0;
    }
    int i;
    int num = Q->rear - Q->front;
    printf("|---|\n");
    for ( i = 0; i < num; i++)
    {
        printf("| %d |\n", Q->data[Q->rear-1-i]);
    printf("|---|\n");
    }
    return 1;
    
}

void main(){
    SqQueue *S = (SqQueue*)malloc(sizeof(SqQueue));
    InitQueue(S);
    EnQueue(S,1);
    EnQueue(S,2);
    EnQueue(S,3);
    EnQueue(S,4);
    EnQueue(S,5);
    ShowQueue(S);

    DeQueue(S);
    DeQueue(S);
    ShowQueue(S);
    DeQueue(S);
    ShowQueue(S);
    DeQueue(S);
}
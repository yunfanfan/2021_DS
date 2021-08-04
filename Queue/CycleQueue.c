#include <stdio.h>
#include <stdlib.h>
#include "CycleQueue.h"

void InitQueue(CycleQueue *Q){
    Q->front = Q->rear = 0;
}

int QueueEmpty(CycleQueue *Q){
    if(Q->front == Q->rear)
        return 1;//empty
    else
        return 0;// not empty
}
int QueueFull(CycleQueue *Q){
    if ((Q->rear+1)%MaxSize == Q->front)
    {
        return 1;// Full
    }
    else
        return 0;// Not Full
}

int EnQueue(CycleQueue *Q, int x){
    if (QueueFull(Q) == 1)
    {
        printf("Queue is Full, EnQueue fail!\n");
        return 0;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    printf("Enqueue Success!\n");
    return 1;
}

int DeQueue(CycleQueue *Q){
    if (QueueEmpty(Q) == 1)
    {
        printf("Queue is empty, DeQueue fail!\n");
        return 0;
    }
    int x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    printf("DeQueue Success!\n");
    return 1;
}

int GetHead(CycleQueue *Q){
    return Q->data[Q->front];   
}
int GetLength(CycleQueue *Q){
    return (Q->rear - Q->front + MaxSize) % MaxSize;
}

int ShowQueue(CycleQueue *Q){
    if(QueueEmpty(Q)==1){
        printf("队列已空\n");
        return 0;
    }
    int i;
    int num = GetLength(Q);
    printf("The length of Queue is %d\n", num);
    printf("|---|\n");
    for ( i = 0; i < num; i++)
    {
        printf("| %d |\n", Q->data[Q->rear-1-i]);
    printf("|---|\n");
    }
    return 1;
    
}

void main(){
    CycleQueue *Q = (CycleQueue*)malloc(sizeof(CycleQueue));
    InitQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 1);
    EnQueue(Q, 1);
    EnQueue(Q, 1);
    EnQueue(Q, 1);

    ShowQueue(Q);

    DeQueue(Q);
    DeQueue(Q);
    DeQueue(Q);
    ShowQueue(Q);

    DeQueue(Q);
    ShowQueue(Q);
    DeQueue(Q);
    ShowQueue(Q);

    DeQueue(Q);
}
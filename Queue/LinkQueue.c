#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

void InitQueue(LinkQueue *Q){
    Q->front = Q->rear = (LinkNode*)malloc(sizeof(LinkNode));//建立头结点
    Q->front->next = NULL;
}

int QueueEmpty(LinkQueue *Q){
    if (Q->front == Q->rear)
    {
        printf("The Queue is Empty!");
        return 1;//empty
    }
    else
    {
        return 0;//not empty
    }
}

int EnQueue(LinkQueue *Q, int x){
    LinkNode *new = (LinkNode*)malloc(sizeof(LinkNode));
    new->data = x;
    new->next = NULL;
    Q->rear->next = new;
    Q->rear = new;
    printf("Enqueue Success!\n");
    return 1;
}

int DeQueue(LinkQueue *Q){
    //判断队空
    if (QueueEmpty(Q) == 1)
    {
        return 0;
    }
    LinkNode *DeNode = Q->front->next;
    int x = DeNode->data;
    Q->front->next = DeNode->next;
    //如果仅有一个节点，出队后，队列为空
    if (DeNode == Q->rear)
    {
        Q->rear = Q->front;
    }
    free(DeNode);
    printf("Enqueue Success!\n");
    return x;
}

int GetLength(LinkQueue *Q){
    if (QueueEmpty(Q) == 1)
    {
        return 0;
    }
    LinkNode *p = Q->front->next;
    int num = 1;
    while (p!=Q->rear)
    {
        p = p->next;
        num++;
    }
    printf("The length of Queue is %d\n", num);
    return num;
}

int ShowQueue(LinkQueue *Q){
    if (QueueEmpty(Q) == 1)
    {
        return 0;
    }
    LinkNode *p = Q->front->next;
    printf("%d", p->data);
    while (p!=Q->rear)
    {
        printf(" -> ");
        p = p->next;
        printf("%d", p->data);
    }
    printf("\n");
    GetLength(Q);
    return 1;
}

void main(){
    LinkQueue *Q = (LinkQueue*)malloc(sizeof(LinkQueue));
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
    DeQueue(Q);
    DeQueue(Q);
    ShowQueue(Q);


}
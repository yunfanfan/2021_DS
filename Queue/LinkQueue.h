#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

typedef struct 
{
    int data;
    struct LinkNode *next;
}LinkNode;
typedef struct
{
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue *Q);

int QueueEmpty(LinkQueue *Q);

int EnQueue(LinkQueue *Q, int x);

//返回出队的节点值
int DeQueue(LinkQueue *Q);

int GetLength(LinkQueue *Q);

int ShowQueue(LinkQueue *Q);

#endif
#ifndef SQQUEUE_H
#define SQQUEUE_H
#define MaxSize 4

typedef struct
{
    /* data */
    int data[MaxSize];
    int front, rear;
}SqQueue;

void InitQueue(SqQueue *Q);

int QueueEmpty(SqQueue *Q);

int EnQueue(SqQueue *Q, int x);

int DeQueue(SqQueue *Q);

int GetHead(SqQueue *Q);

int ShowQueue(SqQueue *Q);
#endif

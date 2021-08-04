#ifndef CYCLEQUEUE_H
#define CYCLEQUEUE_H
#define MaxSize 5 
//实际大小为 MaxSize-1，最后一个作为队满的标志

typedef struct
{
    /* data */
    int data[MaxSize];
    int front, rear;
}CycleQueue;

void InitQueue(CycleQueue *Q);

int QueueEmpty(CycleQueue *Q);

int QueueFull(CycleQueue *Q);

int EnQueue(CycleQueue *Q, int x);

int DeQueue(CycleQueue *Q);

int GetHead(CycleQueue *Q);

int GetLength(CycleQueue *Q);

int ShowQueue(CycleQueue *Q);
#endif

#ifndef SQSTACK_H
#define SQSTACK_H
#define MaxSize 10

typedef struct SqStack
{
    /* data */
    int data[MaxSize];
    int top;
}SqStack;
//初始化空栈S
void InitStack(SqStack *S);

//判空，为空返回0，否则返回1
int StackEmpty(SqStack *S);

//进栈，若栈未满，直接加入x使之成为新栈顶
int Push(SqStack *S, int x);

//出栈，若栈非空，则弹出栈顶元素，并用x返回
int Pop(SqStack *S);

//读栈顶元素，若栈非空，则用x返回栈顶元素
int GetTop(SqStack *S);

//销毁栈，释放栈所占用的存储空间
int DestroyStack(SqStack *S);

#endif
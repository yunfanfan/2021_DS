#include <stdlib.h>
#include <stdio.h>
#include "SqStack.h"
/*
1: True
0: False
*/

void InitStack(SqStack *S){
    S->top = -1;
}

//判空，为空返回1，否则返回0
int StackEmpty(SqStack *S){
    if(S->top == -1)
        return 1;
    else   
        return 0;
}

//进栈，若栈未满，直接加入x使之成为新栈顶
int Push(SqStack *S, int x){
    if(S->top == MaxSize - 1)
        return 0;
    S->data[++S->top] = x;
    return 1;
}

//出栈，若栈非空，则弹出栈顶元素，并且返回该元素
int Pop(SqStack *S){
    if(StackEmpty(S) == 1)
        return 0;
    return S->data[S->top--];
}

//读栈顶元素，若栈非空，则返回该元素
int GetTop(SqStack *S){
    if(StackEmpty(S) == 1)
        return 0;
    return S->data[S->top];
}
void ShowStack(SqStack *S){
    int i;
    printf("-------------------------\n");
    for(i=0;i<=S->top;i++){
        printf("%d\n", S->data[S->top-i]);
    }
    printf("-------------------------\n");
}

int main(){
    SqStack *p = (SqStack*)malloc(sizeof(SqStack));
    InitStack(p);
    Push(p,1);
    Push(p,2);
    Push(p,3);
    ShowStack(p);
    printf("input finish!\n\n");
    printf("Pop value:%d\n", Pop(p));
    printf("Pop value:%d\n", Pop(p));
    printf("Pop value:%d\n", Pop(p));
    ShowStack(p);

}
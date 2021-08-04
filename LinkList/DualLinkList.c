#include <stdio.h>
#include <stdlib.h>
#include "DualLinkList.h"



//1. 初始化双链表
DLinklist InitDLinklist(DLinklist L){
    DNode *Tail = NULL;
    L = (DLinklist)malloc(sizeof(DNode));
    if(NULL == L){
        printf("fail\n");
    }
    L->prior = NULL;
    L->next = NULL;
    Tail = L;
    int length = 0, i = 1, data = 0;
    printf("请输入想要创建链表的长度：");
    scanf("%d", &length);

    for(;i<=length;i++){
        DNode *new = (DNode*)malloc(sizeof(DNode));
        printf("请输入第%d个元素的值：", i);
        scanf("%d", &data);

        new->data = data;
        new->next = NULL;
        new->prior = Tail;
        Tail->next = new;
        Tail = new;
    }
    printf("Init Success!\n");
    return L;
}
//4. 按位查找节点
DNode *GetNode(DLinklist L, int pos){
    if(pos==0)
        return L;
    if(pos<0)
        return NULL;
    DNode *p = L->next;
    int i = 1; //标识查找指针p的位置
    while(p!=NULL && i<pos){
        p = p->next;
        i++;
    }
    printf("Find Success!\n");
    return p;
}
//2. 插入节点
int InsertNode(DLinklist L, int pos, int e){
    DNode *p = GetNode(L, pos-1);
    DNode *new = (DNode*)malloc(sizeof(DNode));
    new->data = e;
    int num = GetLinkLength(L);
    if(pos>num+1 || pos<1){
        printf("插入位置非法！");
        return 1;
    }

    printf("Strat to insert...\n");
    new->next = p->next;
    if(pos != num + 1)
        p->next->prior = new;
    new->prior = p;
    p->next = new;
    printf("Insert Success!\n");
    return 0;
}
//3. 删除节点
int DeleteDLinklist(DLinklist L, int pos){
    DNode *p = GetNode(L, pos-1);
    DNode *q = p->next;
    if(pos>GetLinkLength(L) || pos<0){
        printf("删除位置非法！");
        return 1;
    }

    p->next = q->next;
    q->next->prior = p;
    free(q);
    return 0;

}

//4. 判断链表是否为空
int IsEmptyDLinklist(DLinklist L){
    DNode *p = L->next;
    if(p == NULL)
        return 1;
    else
        return 0;
}
int GetLinkLength(DLinklist L){
    DNode *p = L->next;
    int num = 0;
    while(p){
        num++;//节点数+1
        p = p->next;
    }
    return num;

}

//8. 打印所有节点值
int ShowAllValue(DLinklist L){
    DNode *p = L->next;
    printf("%d", p->data);
    //打印下一个节点
    while(p->next != NULL && GetLinkLength(L)>1){
        printf("-> ");
        p = p->next;
        printf("%d", p->data);
    }
    printf("\n");
    return 0;
}

void main(){
    DLinklist L = InitDLinklist(L);
    InsertNode(L,1,1);
    ShowAllValue(L);
    InsertNode(L,2,1);
    ShowAllValue(L);
    InsertNode(L,2,2);
    InsertNode(L,2,0);
    InsertNode(L,2,0);
    InsertNode(L,2,0);
    InsertNode(L,2,0);
    ShowAllValue(L);
    DeleteDLinklist(L,1);
    ShowAllValue(L);
    DeleteDLinklist(L,1);
    ShowAllValue(L);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

//1. 头插法建立单链表
LinkList List_HeadInsert(LinkList L){
    LNode *new;
    int x;
    L = (LinkList)malloc(sizeof(LNode));//创建头节点
    if(NULL == L){
        printf("fail\n");
    }
    L->next = NULL;//初始为空链表
    printf("Please input value of point:");
    scanf("%d",&x);
    while(x!=9999){
        //由系统生成一个LNode型的节点，
        //同时将该节点的起始位置赋给指针变量s
        new = (LNode*)malloc(sizeof(LNode));
        new->data = x;
        new->next = L->next;//new first
        L->next = new;//L second
        scanf("%d",&x);
    }
    return L;

}
//2. 尾插法建立单链表
LinkList List_TailInsert(LinkList L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *new,*tail = L;
    printf("Please input value of point:");
    scanf("%d",&x);
    while(x!=9999){
        new = (LNode*)malloc(sizeof(LNode));
        new->data = x;
        tail->next = new; //先把新节点连在之前链表的尾巴上
        tail = new; //令新节点成为表尾节点
        scanf("%d",&x);
    }
    tail->next = NULL;
    return L;

}
//3. 按序号查找节点值
LNode *GetElem(LinkList L, int pos){
    int j=1;
    LNode *p=L->next;
    if(pos==0)
        return L;
    if(pos<1)
        return NULL;
    while(p&&j<pos){
        p=p->next;
        j++;
    }
    return p;
}
//4. 按值查找表节点
LNode *LocateElem(LinkList L, int e){
    LNode *p = L->next;
    while(p!=NULL){
        p = p->next;
        if(p->data==e){
            return p;
        }
    }
}
//5.插入节点操作
int InsertNode(LinkList L, int pos, int e){
    LNode *p = GetElem(L,pos-1);
    LNode *new = (LNode*)malloc(sizeof(LNode));
    new->data = e;
    if(p!=NULL){
        new->next = p->next;
        p->next = new;
        printf("Insert Success!");
        return 0;
    }
    else
        return 1;
}
//6.删除节点操作
int DeleteNode(LinkList L, int pos){
    LNode *p = GetElem(L, pos-1);
    if(p!=NULL){
        LNode *q = p->next;
        p->next = q->next;
        free(q);
        printf("Delete Success!");
        return 0;
    }else
        return 1;
}
//7.求表长操作
int GetLength(LinkList L){
    LNode *p = L->next;
    int num = 0;
    while(p){
        num++;
        p = p->next;
    }
    printf("表长为:%d\n", num);
    return num;
}
//8. 打印所有节点值
void ShowAllValue(LinkList L){
    LNode *p = L->next;
    int num = 0;
    while(p){
        num++;//节点数+1
        printf("%d. %d\n", num, p->data);
        p = p->next;
    }
}

void main(){
    LinkList L;
    L = List_HeadInsert(L);
    //L = List_TailInsert(L);
    //LNode *p = GetElem(L, 3);
    //printf("GetElem(3):%d\n",p->data);
    printf("before Insert:\n");
    ShowAllValue(L);
    InsertNode(L, 2, 3);
    printf("after Insert:\n");

    ShowAllValue(L);
    DeleteNode(L, 2);
    ShowAllValue(L);
    GetLength(L);
}

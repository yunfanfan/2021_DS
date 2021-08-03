#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DNode{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinklist;

//1. 初始化双链表
DLinklist InitDLinklist(DLinklist L);
//4. 按位查找节点
DNode *GetNode(DLinklist L, int pos);
//2. 插入节点
int InsertNode(DLinklist L, int pos, int e);
//3. 删除节点
int DeleteNode(DLinklist L, int pos);

//4. 判断链表是否为空
int IsEmptyDLinklist(DLinklist L);
//8. 打印所有节点值
int ShowAllValue(DLinklist L);
int GetLinkLength(DLinklist L);
#endif
#include <stdio.h>
#include <stdlib.h>
#define ValueNum 10
//二叉排序树BST

//树节点
typedef struct
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
}BSTNode, *BSTree;
//树根

BSTNode *BST_Search(BSTree T, int value){
    while (T!=NULL && value!=T->data)
    {
        if (value < T->data)
        {
            T = T->left;
        }
        else
        {
            T = T->right;
        }
    }
    return T;
}
BSTNode *BST_SearchParent(BSTree T, int value){
    BSTNode *parentTree = T;
    while (T!=NULL && value!=T->data)
    {
        if (value < T->data)
        {
            parentTree = T;
            T = T->left;
        }
        else
        {
            parentTree = T;
            T = T->right;
        }
    }
    return parentTree;
}

BSTree BST_Insert(BSTree T, int value){
    /*若原树为空，新插入的记录为根节点*/
    if (T == NULL)
    {
        T = (BSTNode*)malloc(sizeof(BSTNode));
        T->data = value;
        T->left = T->right = NULL;
        printf("插入成功！！！\n\n");
        return T;
    }
    else if (value == T->data){
        printf("树中已有相同节点，插入失败!\n");
        return T;//树中已有相同节点，插入失败
    }
    else if (value < T->data){
        printf("插入值小于节点值，转入左子树：\n");
        T->left = BST_Insert(T->left, value);
        return T;
    }
    else{
        printf("插入值大于节点值，转入右子树：\n");
        T->right = BST_Insert(T->right, value);
        return T;
    }
}
/*构造二叉树*/
BSTree BST_Creat(BSTree T, int value[], int n){
    T = NULL;
    int i = 0;
    while (i < n)
    {
        printf("准备插入的值为：%d\n", value[i]);
        T = BST_Insert(T, value[i]);
        i++;
    }
    printf("构造二叉树成功，共 %d 个节点\n", i);
    return T;
}
/*中序遍历：左根右*/
void Traverse(BSTree T){
    if (T != NULL)
    {
        Traverse(T->left);
        printf("%d ", T->data);
        Traverse(T->right);
    }
}
BSTree BST_Delete(BSTree T, int value){
    BSTNode *DeleteNode = (BSTNode*)malloc(sizeof(BSTNode));
    DeleteNode = BST_Search(T, value);
    BSTNode *ParentOfDN = BST_SearchParent(T, value);
    BSTNode *LeftOfDN = DeleteNode->left;
    BSTNode *RightOfDN = DeleteNode->right;
    if (DeleteNode == NULL)
    {
        printf("无此节点，删除失败！\n");
    }
    else if (LeftOfDN==NULL && RightOfDN == NULL)
    {
        printf("节点为叶节点，直接删除！\n");
        if (DeleteNode->data < ParentOfDN->data)
        {
            ParentOfDN->left = NULL;
        }
        else
        {
            ParentOfDN->right = NULL;
        }
        free(DeleteNode);
    }
    else if (LeftOfDN==NULL || RightOfDN == NULL)
    {
        if (LeftOfDN != NULL)
        {
            printf("被删除节点有左子树，让其替代被删除节点。\n");
            DeleteNode->data = LeftOfDN->data;
            DeleteNode->left = NULL;
            LeftOfDN = NULL;
        }
        else
        {
            printf("被删除节点有右子树，让其替代被删除节点。\n");
            DeleteNode->data = RightOfDN->data;
            DeleteNode->right = NULL;
            RightOfDN = NULL;
        }
    }
    else
    {
        BSTNode *p = RightOfDN;
        BSTNode *q = DeleteNode;
        while (p->left != NULL)
        {
            q = p;//q是p的父节点
            p = p->left;
        }
        printf("%d 的直接后继为：%d，%d 是其父节点。\n", DeleteNode->data, p->data, q->data);
        DeleteNode->data = p->data;
        q->left = p->right;
        free(p);
        p = NULL;
    }
    return T;
}
void main(){
    BSTree T;
    int value[ValueNum] = {53, 17, 9, 45, 23, 78, 65, 94, 81, 88};
    T = BST_Creat(T,value, ValueNum);
    Traverse(T);
    printf("\n");
    //printf("%d\n", BST_SearchParent(T, 9)->data);
    BST_Delete(T, 9);
    Traverse(T);
    BST_Delete(T, 45);
    Traverse(T);
    BST_Delete(T, 78);
    Traverse(T);
}
#include <stdio.h>
#include <stdlib.h>
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
    BSTNode *DeleteNode = BST_Search(T, value);
    BSTNode *LeftOfDN = DeleteNode->left;
    BSTNode *RightOfDN = DeleteNode->right;
    if (DeleteNode == NULL)
    {
        printf("无此节点，删除失败！\n");
    }
    else if (LeftOfDN==NULL && RightOfDN == NULL)
    {
        printf("节点为叶节点，直接删除！\n");
        free(DeleteNode);
    }
    else if (LeftOfDN==NULL || RightOfDN == NULL)
    {
        if (LeftOfDN != NULL)
        {
            printf("被删除节点有左子树，让其替代被删除节点。\n");
            DeleteNode->data = LeftOfDN->data;
            LeftOfDN = NULL;
            free(LeftOfDN);
        }
        else
        {
            printf("被删除节点有右子树，让其替代被删除节点。\n");
            DeleteNode->data = RightOfDN->data;
            RightOfDN = NULL;
            free(RightOfDN);
        }
    }
    else
    {
        BSTNode *p;
        for(p = RightOfDN; p->left; p->left);
        printf("%d 的直接后继为：%d\n", DeleteNode->data, p->data);
        DeleteNode->data = p->data;
        BST_Delete(p, p->data);
    }
    return T;
}
void main(){
    BSTree T;
    int value[8] = {53, 17, 9, 45, 23, 78, 65, 87};
    T = BST_Creat(T,value,8);
    Traverse(T);
    printf("\n");
    BST_Delete(T, 9);
    Traverse(T);
}
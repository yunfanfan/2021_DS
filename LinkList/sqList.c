#include <stdio.h>
#define MaxSize 10

typedef struct{
    int data[MaxSize];
    int length;
}Sqlist;

//1.创建线性表
void InitList(Sqlist *L){
    int i;
    for(i = 0;i<MaxSize;i++){
        L->data[i] = 0;
    }
    L->length = 0;
}
//2. 查找元素
int LocateElem(Sqlist L, int e){
    int pos = -1;
    int i;
    for(i = 0; i<L.length; i++){
        if(L.data[i]==e)
            pos = i+1;
    }
    return pos;
}
//3. 插入元素
int ListInsert(Sqlist *L, int i, int e){
    if(L->length==MaxSize || i<1 || i>L->length+1)
        return 1;
    int j;
    for(j=L->length; j>i; j--){
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=e;
    L->length++;
    return 0;
}
//4. 删除元素
int ListDelete(Sqlist *L, int i){
    if(L->length == 0)
        return 1;
    if(i<1 || i>L->length+1)
        return 1;
    for(; i<=L->length; i++){
        L->data[i-1]=L->data[i];
    }
    L->length--;
    return 0;
}
//5. 打印所有元素
void printAll(Sqlist L){
    printf("-----------------------\n");
    int i;
    for(i=0;i<MaxSize;i++){
        printf("%d. %d\n", i+1, L.data[i]);
    }
    printf("length = %d\n",L.length);

}
void main(){
    Sqlist L, *p;
    p = &L;
    InitList(p);

    ListInsert(p,1,1);
    ListInsert(p,2,2);
    ListInsert(p,3,3);
    ListInsert(p,4,4);
    ListInsert(p,5,5);
    ListInsert(p,6,6);

    printf("pos=%d\n", LocateElem(L,3));

    ListDelete(p,1);
    ListDelete(p,4);
    /*
    int *e;
    GetElem(L,2,e);
    printf("%d\n", e);
    */
    printAll(L);
}

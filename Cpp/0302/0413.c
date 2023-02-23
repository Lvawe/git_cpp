#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 )
{
    List L,p,q,r;
    L=(List)malloc(sizeof(struct Node));
    r=L;
    p=L1->Next;
    q=L2->Next;
    
    while(p!=NULL&&q!=NULL)
    {
        if(p->Data<=q->Data)
        {
            r->Next=p;
            p=p->Next;
            r=r->Next;
        }else
        {
            r->Next=q;
            q=q->Next;
            r=r->Next;
        }
    }
    if(p==NULL)r->Next=q;
    if(q==NULL)r->Next=p;
    L1=NULL;
    L2=NULL;
    return L;
}
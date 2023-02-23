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
    PtrToNode pa=L1->Next,pb = L2->Next,pc;
    List head =(List)malloc(sizeof(struct Node));
    head->Next=NULL;
    pc=head;
    while (pa&&pb){// La和Lb均未到达表尾，依次摘取两表中值较小的结点插入到Lc的最后
     		if (pa->Data <= pb->Data){
       		pc->Next = pa;  pc = pa;  pa = pa->Next;
     		}
     		else{
       		pc->Next = pb;  pc = pb;  pb = pb->Next;
     		}
	    }
    pc->Next = (pa ? pa : pb); // 插入剩余段
   	L1->Next=NULL;
    L2->Next=NULL;  
    return head;

}
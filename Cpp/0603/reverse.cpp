#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *reverse( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *head;

    head = createlist();
    head = reverse(head);
    printlist(head);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *reverse( struct ListNode *head )
{
    struct ListNode *p,*q;
    struct ListNode *L=(struct ListNode *)malloc(sizeof(struct ListNode));
    L->next=NULL;
    p=head;
    while(head!=NULL)
    {
        head=head->next;
        p->next=L->next;
        L->next=p;
        p=head;
    }
    
    return L->next;

}

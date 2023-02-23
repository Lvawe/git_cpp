#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
     char   name[20];
     double    yuan;
     struct book *next;
};
int main()
{
    struct book *head, *tail;
    int n,i=0;
    scanf("%d",&n);
    getchar();
    head = tail = NULL;
    struct book *newNode=(struct book *)malloc(sizeof(struct book));
    newNode->next=NULL;
    while(i<n){
        gets(newNode->name);
        scanf("%lf",&newNode->yuan);
        getchar();
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        tail->next=newNode;
        tail=newNode;
        tail->next=NULL;
        i++;
        newNode=(struct book *)malloc(sizeof(struct book));
    }

    i=0;
    struct book *p,*q,*r;
    p=r=head;
    q=p->next;
    while(p!=NULL&&q!=NULL){
        if(p->yuan<q->yuan){
            p=q;
            q=q->next;
        }else
            q=q->next;
    }
    q=r->next;
    while(r!=NULL&&q!=NULL){
        if(r->yuan>q->yuan){
            r=q;
            q=q->next;
        }else
            q=q->next;
    }
    printf("%.2lf,%s\n", p->yuan, p->name);
    printf("%.2lf,%s\n", r->yuan, r->name);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu {
    char   id[6];
    char   name[30];
    int    sum;
    struct stu *next;
};
int main()
{
    struct stu *head, *tail;
    int n,i=0;
    scanf("%d",&n);
    struct stu *newNode=(struct stu *)malloc(sizeof(struct stu));
    newNode->next=NULL;
    head=newNode;
    tail=newNode;
    while(i<n){
        scanf("%s",&newNode->id);
        scanf("%s",&newNode->name);
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        newNode->sum=a+b+c;
        newNode->next=NULL;
        tail->next=newNode;
        tail=newNode;
        tail->next=NULL;
        i++;
        newNode=(struct stu *)malloc(sizeof(struct stu));
    }

    struct stu *p,*q;
    p=head;
    q=p->next;
    while(p!=NULL&&q!=NULL){
        if(p->sum<q->sum){
            p=q;
            q=q->next;
        }else
            q=q->next;
    }
    printf("%s %s %d\n", p->name, p->id,p->sum);
    return 0;
}

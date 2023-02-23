#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list *next;
}listtype;
typedef listtype* plisttype;

int main()
{
    int x,n,m,k,d,i,a,y,j=0;
    plisttype top,p0,p,q,l,l1,l2,l3;
    scanf("%d",&n);
    top=(plisttype)malloc(sizeof(listtype));
    top->next=NULL;
    p0=top;
    for(i=0;i<n;i++)
    {
    p=(plisttype)malloc(sizeof(listtype));
    scanf("%d",&p->data);
    p0->next=p;//gai
    p0=p;
    }
    p->next=NULL;

    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&a);
    if(a==0)
    {
        scanf("%d %d",&k,&d);
        q=(plisttype)malloc(sizeof(listtype));
        q->data=d;
        l=top->next;
        if(k==0)
        {
            q->next=l;//gai'
            top->next=q;
            j++;
        }
        if(k>0&&k<=n+j)
        {
            for(y=1;y<k;y++)l=l->next;
            q->next=l->next;
            l->next=q;
            j++; 
        }
    }
    if(a==1)
    {
        scanf("%d",&k);
        l2=top;l3=top->next;
        if(k>0&&k<=n+j)
        {    for(x=0;x<k-1;x++)//gai
            {l2=l2->next;
            l3=l3->next;}
            l2->next=l3->next;
            free(l3);
            n--;

        }else ;
    }
}
    q=top->next;
    while(q!=NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    return 0;
}

#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*List;
void printList(List L);
void CreateList(List &L,int m)
{
    L=new LNode;
    L->next=NULL;
    L->data=1;
    LNode* p=L;
    for(int i=1;i<m;i++)
    {
        LNode*q=new LNode;
        q->data=i+1;
        q->next=NULL;
        p->next=q;
        p=p->next;
    }
    p->next=L;

}

void yuesefu(List L,int n,int m)
{
    LNode *p=L;
    while(m){
        int i=1;
        while(p!=NULL&&i<n-1)
        {
            p=p->next;
            ++i;
        }
        LNode *q=p->next;
        cout<<q->data<<" ";
        p->next=q->next;
        free(q);
        --m;
        i=1;
        p=p->next;
    }
    
    

}


int main()
{
    List L;
    int m,n;
    cin>>m>>n;
    CreateList(L,m);
    //printList(L);
    yuesefu(L,n,m);
    return 0;
}

void printList(List L)
{
    LNode *p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
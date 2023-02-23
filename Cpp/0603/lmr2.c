//
// Created by David Lv on 2022/10/25.
//
#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    char data;
    struct list*next;
    struct list*pre;
}listtype;
typedef listtype *plisttype;
void forward(plisttype q,plisttype p,char x){
    if(x=='<'){
        q=q->pre;
        q->next=p;
    }
    if(x=='>'){
        delete(q,p,x);
    }

}
void delete(plisttype q,plisttype p,char x){
plisttype l;
l=p;
q->next=p->next;
p->next->pre=q;
p=p->next;
free(l);
}
int main(){
    plisttype top,q,p,l,l2;
    char m[50000],*ptr;
    ptr=m;
    gets(m);
    top=(plisttype)malloc(sizeof(listtype));
    q=top;
    top->next=NULL;
    top->pre=NULL;
    while(*ptr!='\0')
    {
        p=(plisttype)malloc(sizeof(listtype));
        p->data=*ptr;
        if(*ptr=='{')
        {
            l=p;
            p->next=q->next;
            p->pre=q;
            q->pre->next=p;
            q->next=p;
            q=p;
            p=p->next;
            ptr++;
            while(*ptr!='}'){
                p=(plisttype)malloc(sizeof(listtype));
                p->data=*ptr;
                forward(q,p,*ptr);
                q=p;
                p=p->next;
                ptr++;
            }
            p=l;p->pre=q;

        }
        if(*ptr=='<'||'>'){
            forward(q,p,*ptr);
            ptr++;
        }
        if(*ptr=='#'){
            delete(q,p,*ptr);
        }
        q=p;
        p=p->next;
        ptr++;
    }
    l2=top->next;
    while(l2!=NULL){
        printf("%c",l2);
        l2=l2->next;
    }
    return 0;
}

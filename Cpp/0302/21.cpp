#include <iostream>
#include <string>
using namespace std;

typedef struct List{
    int sno;    
    char sname[10];
    List *next;
};

List * CreateList();  //键盘输入若干学生学号和姓名，学号与姓名以空格符间隔，当输入的学号为-1时，输入结束，创建学生信息链表函数，返回学生链表的头指针。
List * Find(List *head, int no); //在学生信息链表（头指针为head）中查询学号为no的学生，返回该学生结点的指针。

int main(void){
    List *list=NULL,*p;
    int no;
    list=CreateList();
    while(~scanf("%d", &no))
    {
        p=Find(list,no);
        if( p ) printf("%s\n", p->sname);
        else printf("Not Found!\n");
    }
    return 0;
}
/* 请在这里填写答案 */
List * CreateList()
{
    List *head,*tail,*pos;
    int cno;
    char cname[10];
    head=(List*)malloc(sizeof(List));
    tail=head;
    scanf("%d",&cno);
    while(cno!=-1){
        pos=(List*)malloc(sizeof(List));
        pos->next=NULL;
        pos->sno=cno;
        scanf("%s",pos->sname);
        scanf("%d",&cno);
        tail->next=pos;
        tail=pos;
    }
    scanf("%s",cname);
    return head;
}
List * Find(List *head, int no)
{
    List *p;
    p=head->next;
    while(p->sno!=no){
        if(p->next==NULL)
            return NULL;
        else
            p=p->next;
    }
    return p;
}

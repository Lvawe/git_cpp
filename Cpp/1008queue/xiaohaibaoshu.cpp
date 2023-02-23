#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 11
#define N 10

typedef char ElemType;
typedef struct   // 顺序循环队列结点定义
{
    ElemType *name[MaxSize];   //小孩姓名
    int front,rear;        //队首和队尾指针
} SqQueue;
void InitQueue(SqQueue *&q);   //初始化队列；
void DestroyQueue(SqQueue *&q);  //销毁队列；
bool QueueEmpty(SqQueue *q);  //判定队列为空时返回true; 否则返回false;
bool enQueue(SqQueue *&q,ElemType *e);  // e 入队；成功入队返回true; 否则返回false;
bool deQueue(SqQueue *&q,ElemType *&e);  //出队，返回出队元素e，且成功出队返回true,否则返回false;

int main()
{
    ElemType *e;
    int n,i;
    SqQueue *q;
    InitQueue(q);    
    scanf("%d",&n);
    while(1)
    {
        char *name=(char *)malloc(sizeof(char)*N);
        scanf("%s",name);
        if( (strcmp("-1",name)==0)||!enQueue(q,name))
            break;
    }
    i=n-1;
    while(!QueueEmpty(q))
    {
        deQueue(q,e);
        if(i-->0) 
            enQueue(q,e);
        else
        {
            printf("%s\n",e);
            i=n-1;
            free(e);            
        }        
    }
    DestroyQueue(q);
}


/* 请在这里填写答案 */
void InitQueue(SqQueue *&q)  //初始化队列；
{
    q=new SqQueue();
    q->rear=q->front=0;
}
void DestroyQueue(SqQueue *&q) //销毁队列；
{
    q=NULL;
    free(q);
}
bool QueueEmpty(SqQueue *q)  //判定队列为空时返回true; 否则返回false;
{
    if(q->front==q->rear)return true ;
    else return false;
}
bool enQueue(SqQueue *&q,ElemType *e)  // e 入队；成功入队返回true; 否则返回false;
{
    if((q->rear+1)%MaxSize==q->front)return false;
    q->name[q->rear]=e;
    ++q->rear;
    q->rear=(q->rear)%MaxSize;//这两句特别有必要,否者会溢出!!!段错误!
    return true;
}
bool deQueue(SqQueue *&q,ElemType *&e) //出队，返回出队元素e，且成功出队返回true,否则返回false;
{
    if(QueueEmpty(q))return false;
    e=q->name[q->front];
    ++q->front;
    q->front=(q->front)%MaxSize;//这两句特别有必要,否者会溢出!!!段错误!
    return true;
}
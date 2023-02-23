#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define Size 100
#define ERROR 'NO';//为通过调试
typedef int Position;
typedef char ElementType;
typedef struct SNode *PtrToSNode;
struct SNode
{
	ElementType *Data;
	Position Top;
	int MaxSize;
};
typedef PtrToSNode Stack;
Stack CreatStack(int MaxSize)
{
	Stack S=(Stack)malloc(sizeof(struct SNode));
	S->Data=(ElementType*)malloc(MaxSize*sizeof(ElementType));
	S->Top=-1;
	S->MaxSize=MaxSize;
	return S;
}
bool IsFull(Stack S)
{
	return (S->Top==S->MaxSize-1);
}
bool Push(Stack S,ElementType X)
{
	if(IsFull(S))
	{//栈满
		return false;
	}
	else
	{
		S->Data[++(S->Top)]=X;
		return true;
	}
}
bool IsEmpty(Stack S)
{
	return(S->Top==-1);
}
ElementType Pop(Stack S)
{
	if(IsEmpty(S))
	{//栈空
		return ERROR;
	}
	else
		return(S->Data[(S->Top)--]);
}
char getTop(Stack S)
{
	return S->Data[S->Top];
}

int main()
{
    Stack S=CreatStack(100);
    char c[100];
    int i;
    //scanf("%s",&c);
    gets(c);
    for(i=0;c[i]!='\0';i++){}
    
    int j;
    if(i%2)
    {
        j=(i-1)/2;
        for(i=0;i<j;i++){
            Push(S,c[i]);
        }
        for(i=0;i<j;i++){
            if(c[j+1+i]!=getTop(S)){
                printf("%s不是回文。",&c);
                return 0;
            }else{
                Pop(S);
            }
        }
    }else {
        j=i/2;
        for(i=0;i<j;i++){
            Push(S,c[i]);
        }
        for(i=0;i<j;i++){
            if(c[j+i]!=getTop(S)){
                printf("%s不是回文。",&c);
                return 0;
            }else{
                Pop(S);
            }
        }
    }

    printf("%s是回文。",&c);
    return 0;
}
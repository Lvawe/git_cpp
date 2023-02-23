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
	char c[120];
	char t;
	int i=0;
	int flag=1;
	Stack S=CreatStack(120);
	while(gets(c))
	{
		if(c[0]=='.'&&c[1]=='\0')break;
		for(i=0;c[i]!='\0';i++)
		{
			if(c[i]=='/'&&c[i+1]=='*'){
				Push(S,c[i]);
				Push(S,c[i+1]);
				i++;
			}
			else if(c[i]=='{'||c[i]=='('||c[i]=='['){
				Push(S,c[i]);
			}
			else if(c[i]=='*'&&c[i+1]=='/'){
				if(!IsEmpty(S)&&getTop(S)=='*'){
					Pop(S);
					if(!IsEmpty(S)&&getTop(S)=='/'){
						Pop(S);
					}else{
						flag=0;
						t=c[i];
						break;
					}
				}else{
					flag=0;
					t=c[i];
					break;
				}
			}
			else if(c[i]=='}'){
				if(!IsEmpty(S)&&getTop(S)=='{'){
					Pop(S);
				}else{
					flag=0;
					t=c[i];
					break;
				}
			}
			else if(c[i]==']'){
				if(!IsEmpty(S)&&getTop(S)=='['){
					Pop(S);
				}else{
					flag=0;
					t=c[i];
					break;
				}
			}
			else if(c[i]==')'){
				if(!IsEmpty(S)&&getTop(S)=='('){
					Pop(S);
				}else{
					flag=0;
					t=c[i];
					break;
				}
			}
		}
	}
	if(IsEmpty(S)&&flag==1)printf("YES\n");
	else
	{
		printf("NO\n");
		if(IsEmpty(S)){
			if(t=='}')printf("?-}");
			else if(t==']')printf("?-]");
			else if(t==')')printf("?-)");
			else printf("?-*/");
		}else{
			if(getTop(S)=='{')printf("{-?");
			else if(getTop(S)=='[')printf("[-?");
			else if(getTop(S)=='(')printf("(-?");
			else printf("/*-?");
		}
	}
}

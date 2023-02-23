#include <iostream>
using namespace std;

#define ERROR -1
typedef char ElementType;
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType *Data;  /* 存储元素的数组 */
    Position Top;       /* 栈顶指针       */
    int MaxSize;        /* 堆栈最大容量   */
};
typedef PtrToSNode Stack;

Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool Push( Stack S, ElementType X )
{
    if(S->Top>=S->MaxSize){
        //printf("Stack Full\n");
        return false;
    }
    ++(S->Top);
    S->Data[S->Top]=X;
    return true;
}
ElementType Pop( Stack S )
{
    if(S->Top<=-1)
    {
        //printf("Stack Empty\n");
        return ERROR;
    }
    //printf("%d is out\n",&S->Data[S->Top-1]);
    --(S->Top);
    return S->Data[S->Top+1];
}
ElementType Top(Stack s){
    return s->Data[s->Top];
}
int Empty(Stack s){
    if(s->Top == -1) return 1;
    else return 0;
}
bool Matching();
int main()
{
    bool what=Matching();
    if(what)printf("YES\n");
    else printf("NO\n");
}
bool Matching()  // 检验表达式中所含括号是否正确匹配，如果匹配返回true，否则返回false
{ // 表达式以‘#’作为结束
    Stack S=CreateStack(100);  // 初始化空栈
    char ch, x;
    int flag = 1;     // 标记匹配结果以控制循环及返回结果
    ch=getchar(); // 读入第一个字符
    while (ch != '.' && flag) {// 假设表达式以“#”结尾 
        switch (ch) {
        case '[':
        case '/*':
        case '(':      // 若是左括号，则将其压入栈
            Push(S, ch);
            break;
        case ')':  // 若是“)”，则根据当前栈顶元素的值分情况考虑
            if (!Empty(S) && Top(S) == '(') // 若栈非空且栈顶元素是“(”，则正确匹配                       
                Pop(S);
            else
                flag = 0;    // 若栈空或栈顶元素不是“(”，则错误失败
            break;
        case '*/':  // 若是“)”，则根据当前栈顶元素的值分情况考虑
            if (!Empty(S) && Top(S) == '/*') // 若栈非空且栈顶元素是“(”，则正确匹配                       
                Pop(S);
            else
                flag = 0;    // 若栈空或栈顶元素不是“(”，则错误失败
            break;
        case ']': //若是“]”，则根据当前栈顶元素的值分情况考虑
            if (!Empty(S) && Top(S) == '[') // 若栈非空且栈顶元素是“[”，则正确匹配                        
                Pop(S);
            else
                flag = 0;         //若栈空或栈顶元素不是“[”，则错误匹配
            break;
        }
        ch=getchar(); //继续读入下一个字符
    }
    if (Empty(S) && flag)
        return true;         // 匹配成功
    else
        return false;      // 匹配失败
}

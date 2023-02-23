#include <iostream>
using namespace std;

void DecimalToBinary(int n) 
{ // 打印输出10进制整数n对应的2进制数
    int stack[20], top=-1;
	while(n) {
       	stack[++top] = n % 2; // 将余数入栈
       	n /= 2;
   	}
	while (top != -1) { // 当栈非空
		cout<<stack[top--]; //弹出栈顶元素并输出
   	}
}
void DecimalToOctal(int n) 
{ // 打印输出10进制整数n对应的8进制数
   	int stack[20], top=-1;
	while(n) {
       	stack[++top] = n % 8; // 将余数入栈
       	n /= 8;
   	}
	while (top != -1) { // 当栈非空
		cout<<stack[top--]; //弹出栈顶元素并输出
   	}
}
void DecimalToHex(int n) 
{ // 打印输出10进制整数n对应的16进制数
   	int stack[20], top=-1;
	while(n) {
       	stack[++top] = n % 16; // 将余数入栈
       	n /= 16;
   	}
	while (top != -1) { // 当栈非空
        if(stack[top]==10)cout<<"A";
        if(stack[top]==11)cout<<"B";
        if(stack[top]==12)cout<<"C";
        if(stack[top]==13)cout<<"D";
        if(stack[top]==14)cout<<"E";
        if(stack[top]==15)cout<<"F";
		if(stack[top]<10)cout<<stack[top];
        --top;
   	}
}

int main()
{
    int m,n;
    cin>>m>>n;
    if(n==2)DecimalToBinary(m);
    else if(n==8)DecimalToOctal(m);
    else DecimalToHex(m);
    return 0;
}

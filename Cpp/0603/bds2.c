#include<stdio.h>
#include<string.h>


int in(char ch)
{
	if (ch <= '9' && ch >= '0')
		return 1;
	return 0;
}

int A(int a, char c, int b,int *flag) 
{
	if (c == '*')
		return a * b;
	else if (c == '/') {
		if (b == 0)
			*flag = 1;
		else
		return a / b;
	}
	else if (c == '-') 
		return a - b;
	else if (c == '+') 
		return a + b;
}

int B(char a, char b)
{
	int x = 0;
	int y = 0;
	if (a == '+' || a == '-')
		x = 1;
	else if (a == '*' || a == '/')
		x = 2;
	else if (a == '(')
		x = 3;
	if (b == '+' || b == '-')
		y = 1;
	else if (b == '*' || b == '/')
		y = 2;
	else if (b == '(')
		y = 3;
	if (x > y)return 1;
	return 0;
}
int main()
{

	char s[1000];
	int num[1000];
	char ch[1000];
	int flag=0;
	gets(s);
	int a=0, b=0;
	for (int i = 0; i < 1000; i++)
	{
		num[i] = 0;
		ch[i] = '0';
	}

	int i = 0;
	while (i < strlen(s))
	{
		if (in(s[i]))//如果是数字则入num
		{
			while (in(s[i]))
				num[a] = num[a] * 10 + s[i++] - '0';//多位数的情况
			a++;
			continue;
		}
		else//不是数字
		{
			if (s[i] == '(') //遇到左括号直接入ch【】
				ch[b++] = s[i];
			else if (s[i] == ')')//遇到右括号计算
			{
				while (ch[b - 1] != '(')
				{
					num[a - 2] = A(num[a - 2], ch[b - 1], num[a - 1],&flag);
					num[a - 1] = 0;
					b--;//改变符号栈栈顶
					a--;//改变数字栈栈顶
				}
				b--;
			}
			else {//遇到运算符
				if (b == 0) //符号栈为空，直接入
					ch[b++] = s[i];
				else if (B(s[i], ch[b - 1]))//判断当前符号与符号栈栈顶元素的优先级，如果当前元素优先级大直接入
					ch[b++] = s[i];
				else //栈顶元素优先级小，进行计算
				{
					while (!B(s[i], ch[b - 1])) {
						if (ch[b - 1] == '(')//多重括号的情况
							break;
						num[a - 2] = A(num[a - 2], ch[b - 1], num[a - 1],&flag);
						num[a - 1] = 0;
						b--;
						a--;
						if (b == 0)break;
					}
					ch[b++] = s[i];//计算完后将此符号入ch【】
				}
			}
		}
		i++;
	}
	while (a != 1 && b > 0)//数字栈数组中剩余两位，符号剩余一位
	{
		num[a - 2] = A(num[a - 2], ch[b - 1], num[a - 1],&flag);
		a--;
		b--;

	}
	if (flag == 1)
		printf("ILLEGAL");
	else
	printf("%d", num[0]);
}

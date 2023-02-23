#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

#define MAXSTRLEN 255         //用户可用的最大串长，超过则自动截断
typedef char SString[MAXSTRLEN+1];  // 0号单元存放串的长度

void get_next(SString T, int next[]);
int Index_KMP(SString S, SString T, int pos,int next[]);
int Index_BF(SString S, SString T, int pos);

int main()
{
    SString s1,s2;
    char c;
    int m,n1,n2;
    scanf("%s",s1+1);
    n1 = strlen(s1+1);
    s1[0]=n1;
    cin>>m;
    while(m--)
    {
        scanf("%s",s2+1);
        n2 = strlen(s2+1);
        s2[0]=n2;
        
        int next[255];
        get_next(s2,next);

        //int p=Index_BF(s1, s2, 1);
        int p=Index_KMP(s1, s2, 1, next);
        if(n2>n1){
            cout<<"Not Found"<<endl;
        }
        else if(p){
            printf("%s\n",s1+p);
        }else
            cout<<"Not Found"<<endl;

    }
}

void get_next(SString T, int next[])
{ // 求模式串T的next函数值并存入数组next，算法 4.7，O（m）
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T[0]) {
        if (j == 0 || T[i] == T[j]) {
	++i; ++j; next[i] = j;
        }
        else
            j = next[j];  // 精髓之处
    }
}

int Index_KMP(SString S, SString T, int pos,int next[])
{ // 利用模式串T的next函数求T在主串S中
  // 第pos个字符之后第一次出现的位置；否则返回０。
  // 其中T非空，1<=pos<=S.length
    int i = pos,j = 1;
    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) 
              { ++i; ++j; } // 继续比较后续字符
        else 
	 j = next[j]; // 模式串向后移
    }
    if (j > T[0]) 
	return i - T[0]; // 匹配成功
    else 
	return 0; // 匹配不成功
} // Index_KMP，算法4.6，O（m+n）



int Index_BF(SString S, SString T, int pos) {
//返回模式T在主串S中第pos个字符开始第一次出现的位置，若不存在则返回值为0
//其中，T非空，1<=pos<=S.length
    int i = pos, j = 1; // i指向主串待比较字符，j指向子串待比较字符
    while (i <= S[0] && j <= T[0]) { //两个串均未比较到串尾
    if (S[i] == T[j]) {//继续比较后继字符
        ++i; ++j;
    }
    else {
        i = i - j + 2;//指针后退重新匹配，主串从下一个字符开始匹配 
        j=1;
    }
}
if (j > T[0]) 
    return i - T[0];//匹配成功，返回匹配的子串在主串的起始位置 
else 
    return 0;//匹配失败 
    
}
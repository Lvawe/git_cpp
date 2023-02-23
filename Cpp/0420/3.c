#include<stdio.h>
#include<string.h>
int main()
{
    char s[90];

    gets(s);
    while(s[0]!='#'){
        printf("%c",s[0]);
        gets(s);
    }
    return 0;
}
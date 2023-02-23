#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char c;
    scanf("%d %c",&n,&c);
    char s[100];
    getchar();
    gets(s);
    if(strlen(s)<n)
    {
        for(int j=0;j<n-strlen(s);j++){
            printf("%c",c);
        }
        printf("%s",s);
    }else
    {
        for(int i=strlen(s)-n;i<strlen(s);i++){
			printf("%c",s[i]);
		}
    }
    
    // }else 
    // {
    //     printf("%s",(s+strlen(s)-n));
    // }
    
    return 0;
}
#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;
    
    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

char *match( char *s, char ch1, char ch2 )
{
	int i=0;
	while(s[i]!=ch1&&s[i]!='\0')
	    i++;
    int a=i;
	if(s[i]!='\0')
	{
		for(;s[i]!='\0'&&s[i]!=ch2;i++)
		{
			if(s[i]==ch2) break;
			printf("%c",s[i]);
		}
		if(s[i]!='\0') printf("%c",ch2);
		printf("\n");
	}
	else
	printf("\n");
	return s+a;
}

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

/* 你的代码将被嵌在这里 */
char *match( char *s, char ch1, char ch2 )
{
	int i=0;
	while(*s!=ch1&&*s!='\0')
	s=s+1;
	if(*s!='\0')
	{
		for(*s;*s!='\0'&&*s!=ch2;s++)
		{
			if(*s==ch2) break;
			printf("%c",*s);
			i++;
		}
		if(*s!='\0') printf("%c",ch2);
		printf("\n");
	}
	else
	printf("\n");
    
	return s-i;
}

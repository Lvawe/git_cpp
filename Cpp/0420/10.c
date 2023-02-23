#include <stdio.h>
#define N 5
void input(char **p, int n);
int main(void)
{
    char data[N][81], *ptr[N];
    int i;
    for(i=0;i<N;i++)
       *(ptr+i)=*(data+i);

    input(ptr,N);
    for(i=0;i<N;i++)
        printf("%s\n",*(ptr+i));
    return 0;
} 
void input(char **p, int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%s\n",*(p+i));

}
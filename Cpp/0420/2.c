#include<stdio.h>
void max_min(int *a,int n);
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    max_min(a,n);
    return 0;
}
void max_min(int *a,int n)
{
    int max=a[0],min=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
    printf("max=%d\n",max);
    printf("min=%d",min);
}
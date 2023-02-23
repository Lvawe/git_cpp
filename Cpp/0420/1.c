#include <stdio.h>

struct student{
    int sex;
    char name[20];
    int flag;
};
int main()
{
    int n;
    scanf("%d",&n);
    struct student stu[n];  
    for(int i=0;i<n;i++)
    {
        scanf("%d %s",&stu[i].sex,stu[i].name);
    }
    for(int i=0;i<n/2;i++)
    {
        for(int j=n-1;j>0;j--)
        {
            if((stu[i].sex!=stu[j].sex)&&stu[j].flag!=1){
                printf("%s %s\n",stu[i].name,stu[j].name);
                stu[j].flag=1;
                break;
            }
        }
    }
    return 0;
}
#include<iostream>
#include<queue>
using namespace std;

int f(int m)
{
    if(m==1||m==2)return 1;
    return f(m-1)+f(m-2);
}


int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        cin>>m;
        cout<<f(m)<<endl;
    }
    return 0;
}






#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int>s;
    int n,m;
    cin>>n>>m;
    int num;
    while(n--)
    {
        cin>>num;
        s.push(num);
    }
    num=1;
    while(m--)
    {
        num*=s.top();
        s.pop();        
    }
    cout<<num;
    return 0;
}
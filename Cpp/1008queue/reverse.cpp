#include<iostream>
using namespace std;

void reverse(int m)
{
    if(m<10)cout<<m;
    else {
        cout<<m%10;
        reverse(m/10);
    }
    return;
}
int main()
{
    int m;
    cin>>m;
    reverse(m);
    return 0;
}
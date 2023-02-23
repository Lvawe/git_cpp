#include<iostream>
using namespace std;

int f(int n, int m){
    return n == 1 ? n : (f(n - 1, m) + m - 1) % n + 1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(n!=0)
    {
        cout<<f(n,m);
        cin>>n>>m;
    }
}
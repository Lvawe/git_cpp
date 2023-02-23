#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<char> s;
    string a;
    int m,n;
    cin>>m>>n;

    int flag=0;
    for(int i=0;i<m;i++)
    {
        flag=0;
        cin>>a;
        for(int j=0;j<a.length();j++)
        {
            if(a[j]=='S'){
                if(s.size()<=n)s.push('S');
                else{
                    cout<<"NO"<<endl;
                    flag=1;
                    break;
                }
            }
            else if(a[j]=='X'){
                if(!s.empty())s.pop();
                else{
                    cout<<"NO"<<endl;
                    flag=1;
                    break;
                }
            }

        }
        if(flag==0){
            if(!s.empty()){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }
        flag=0;
        while(!s.empty())s.pop();
    }
    
}
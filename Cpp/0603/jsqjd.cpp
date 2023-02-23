#include<iostream>
#include<bits/stdc++.h>
using namespace std;




int main()
{
    int n,num;
    char ch; 
    cin>>n;
    stack<int> s1;
    stack<char> s2;
    for(int i=0;i<n;i++){
        cin>>num;
        s1.push(num);
    }
    for(int i=0;i<n-1;i++){
        cin>>ch;
        s2.push(ch);
    }
    int m1,m2;
    char c;
    while(!s2.empty())
    {
        m1=s1.top();s1.pop();
        m2=s1.top();s1.pop();
        c=s2.top();s2.pop();
        
        if(c=='+')s1.push(m2+m1);
        else if(c=='-')s1.push(m2-m1);
        else if(c=='*')s1.push(m2*m1);
        else if(c=='/'){
            if(m1==0){
                cout<<"ERROR: "<<m2<<"/0";
                return 0;
            }
            s1.push(m2/m1);
        }
    }
    cout<<s1.top();

}
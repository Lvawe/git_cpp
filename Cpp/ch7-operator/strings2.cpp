#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int n;
    string s;
    vector<string> v;
    while(cin>>n&&n)
    {
        cin.get();
        while( (n--) && getline(cin,s) && s!="stop" )
        {
             v.push_back(s);
        }
        for(int i=0;i<v.size()-1;i++){
            for(int j=0;j<v.size()-i-1;j++){
                if(v[j].length()>v[j+1].length()){
                    string s=v[j];
                    v[j]=v[j+1];
                    v[j+1]=s;
                }
            }
        }
        for(int i=0,n=v.size();i<n;++i)
            cout<<v[i]<<endl;
        v.clear();
    }
    return 0;
}

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    string s;
    vector<string>v;
    while(cin>>n)
    {
        cin.get();
        for(int i=0;i<n;i++)
        {
            getline(cin,s);
            if(s=="stop")break;
            else v.push_back(s);
        }
        for(int i=0;i<v.size()-1;i++){
            for(int j=0;j<v.size()-i-1;j++){
                if(v[j].length()>v[j+1].length()){
                    string t=v[j];
                    v[j]=v[j+1];
                    v[j+1]=t;
                }
            }
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<endl;
        }
        v.clear();
    }
    return 0;

}
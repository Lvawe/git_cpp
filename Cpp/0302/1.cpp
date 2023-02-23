#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
int prime(int x);

vector<int> sieve(int n); //函数声明,求n以内的质数
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> ans = sieve(n);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1)cout << " ";
    }
    cout << endl;
    return 0;
}

int prime(int x)
{
  int i;
  for(i=2;i<=sqrt(x);i++)
  {
    if(x%i==0)
        return 0;
  }
  return 1;
}
vector<int> sieve(int n) //函数声明, 求n以内的质数
{
    vector<int>a; 
    for(int i=2;i*i<=n;i++){
        if(prime(n)) 
            a.push_back(i);
    }
    return a;

}
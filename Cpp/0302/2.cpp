#include <iostream>

#include <vector>

using namespace std;



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



/* 请在这里填写答案 */
vector<int> sieve(int n)
{
    vector<int>a;                  //这用了vector容器来装素数，相当于一个自动扩充的数组
    int i,j,*flag=new int[n+1];    //这用动态分配好一点，静态分配能算的范围要小一些
    for(i=2; i<=n; i++)           //初始化，假设全是素数，0，1可以不用管，所以没初始化
        flag[i]=1;
    for(i=2; i*i<=n; i++)         //任何一个数，都可以拆成一个小数（除1外）和一个大数的乘积，极
                                  //限情况是两个平方根，比如25，所以用小于平方根（比如小于等于
                                  //5）的数去筛就行
    {
        if(flag[i])               //这就是欧拉筛法的精髓，不重复删去，去掉还不行会超时
        {
            for(j=i+i; j<=n; j+=i)  
                flag[j]=0;
        }
    }
    for(i=2;i<=n;i++)
        if(flag[i]) a.push_back(i);
    return a;
}
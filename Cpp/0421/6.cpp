#include <iostream>
#include <iomanip>
using namespace std;

/* 你提交的代码将被嵌在这里 */
class TIME
{
public:
    TIME(int h=0,int m=0,int s=0){
        hour=h;
        minute=m;
        second=s;
    }
    friend istream& operator>>(istream &in,TIME&t)
    {
        char c1,c2;
        in>>t.hour>>c1>>t.minute>>c2>>t.second;
        return in;
    }
    friend ostream& operator<<(ostream &out,TIME&t)
    {
        out<<setfill('0') << setw(2)<<t.hour<<":"<<setfill('0') << setw(2)<<t.minute<<":"<<setfill('0') << setw(2)<<t.second;
        return out;
    }
    friend bool operator>(const TIME &b,const TIME &a)
    {
        if(b.hour>a.hour)return true;
        else if(b.minute>a.minute)return true;
        else if(b.second>a.second)return true;
        else return false;
    }
private:
    int hour,minute,second;
};
int main()
{
TIME a(3, 4, 5), b(2), c, d(1, 59);
if (a > b && c > d)
{
    cout << "Yes\n";
}
else
{
    cout << "No\n";
}








    return 0;
}

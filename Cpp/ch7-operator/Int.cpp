#include <iostream>
using namespace std;
/**
 * 最新的编译器不能根据运算符表达式自动选择成员运算符函数还是友元运算符函数。
 * 所以运算符重载时，使用友元运算符函数，就不用成员运算符函数，或者相反。
 * 下面的例子，两种都写出来了。
 * */

class Int{
    friend ostream& operator<<(ostream& os, const Int& a);
    friend Int operator+(const Int& a, const Int& b);
    friend bool operator>(const Int& a, const Int& b);
private: 
    int cur = 0;
public:
    Int(int i):cur(i){}

    Int &operator++(){   //前缀
        cur++;
        return *this;
    }

    Int operator++(int){    //后缀
        Int t = *this;
        cur++;
        return t;
    }
    // Int operator++(int){    //后缀
    //     int t = cur;
    //     cur++;
    //     return Int(t);
    // }

    Int operator+(Int& i){
        return Int(cur+ i.cur);
    }

    Int& operator+=(Int& i){
        cur += i.cur;
        return *this;
    }

    bool operator>(const Int& b){
        return cur > b.cur;
    }

    operator int() const{   //转换为内置类型int————转换函数
        return cur;
    }
};

ostream& operator<<(ostream& os, const Int& a){
    os<<a.cur;
    return os;
}

Int operator+(const Int& a, const Int& b){
    return Int(a.cur + b.cur);
}

bool operator>(const Int& a, const Int& b){
    return a.cur > b.cur;
}

int main(){
    Int a(5);
    Int b(6);
    cout<<a<<b<<endl;
    cout<<(a++)++<<endl;
    cout<<a<<b<<endl;
    cout<<++(++a)<<endl;
    cout<<a<<b<<endl;
    
    // cout<<a.operator++(0)<<endl;
    // cout<<a<<endl;
    // cout<<++a<<endl;

    //cout<<a+b<<endl;  //报错
    // cout<<a.operator+(b)<<endl;
    // cout<<operator+(a, b)<<endl;

    //cout<<a>b<<endl;  //报错
    // cout<<a.operator>(b)<<endl;
    // cout<<operator>(a, b)<<endl;
    // a+=b;
    
    // int i = int(a);
    // cout<<i<<endl;
    return 0;
}
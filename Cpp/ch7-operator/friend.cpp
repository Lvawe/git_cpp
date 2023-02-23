#include <iostream>
using namespace std;
/**
 * 友元函数和友元类，加关键字friend，不受访问控制所控制，通常放在类体的开头
 * 友元函数和友元类，通常有一个类类型的形参，显然，因为要访问这个类类型的形参（对象）的私有成员（包括成员函数），
 * 所以设置为它们为该类类型的友元。
 **/

class A{
    friend void myfriend(const A& a);
    friend istream& input(istream& stm, A& a);
    friend istream& operator>>(istream& is, A& a);
    friend class B;
private:
    int t = 0;  //私有数据成员（成员变量）
public:
    A(int t):t(t){}
    void out(){ //成员方法
        cout<<t<<endl;
    }
};

void myfriend(const A& a){
    cout<<a.t<<endl;
}

istream& input(istream& is, A& a){
    is>>a.t;
    return is;
}

istream& operator>>(istream& is, A& a){
    is>>a.t;
    return is;
}

class B{
    A a{0};
public:
    B(int i):a(i){ }
    void print(){
        cout<<a.t<<endl;    //可以访问对象a的私有成员
    }

    void input(A& m){
        cin>>m.t;
        m.out();
    }
};

int main(){
    A a(100);
    myfriend(a);

    input(cin, a); a.out(); //input(istream& is, A& a)
    cin>>a; a.out();        //operator>>(istream& is, A& a)
    
    A b(20);
    input(input(cin, a), b);//友元函数input(istream& is, A& a)

    operator>>(operator>>(cin,a), b);//operator>>(istream& is, A& a)
    cin>>a>>b;          //友元函数中缀表达式，运算符>>放在中间


    void (A::*p)() = A::out;//成员函数指针
    (a.*p)();       //.*成员指针运算符
    A* q = &a;
    (q->*p)();      //->*成员指针运算符

    return 0;
}
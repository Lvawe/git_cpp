#include <iostream>
using namespace std;

class A{
public:
    void display(int n)const{
        cout<<n<<endl;
    }
};

class Ptr{  //Ptr的行为像一个指针，迭代器iterator就是一个例子
private:
    static A my;
public:
    A* operator->(){
        return &my;
    }
    A& operator*(){
        return my;
    }
};

A Ptr::my;

class B{
    Ptr p;
public:
    Ptr& operator->(){
        return p;
    }
};

int main(){
    Ptr p;/*
    p.operator->()->display(100);
    p->display(200);
    */
    (*p).display(200);
    B b;
    b->display(300);
    //b.operator->().operator->()->display(340);
    return 0;
}

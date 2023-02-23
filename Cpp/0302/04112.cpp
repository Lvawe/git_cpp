//包括构造函数、拷贝构造函数以及析构函数
#include<iostream>
using namespace std; 

class Circle
{
private:
    float m_r;
public:
    Circle(float r):m_r(r){
        cout<<"Constructor called"<<endl;
    }
    Circle(const Circle & c)
    {
        m_r=c.m_r;
        cout<<"Copy constructor called"<<endl;
    }
    ~Circle(){
        cout<<"Destructor called"<<endl;
    }
    float area(){
        return 3.14*m_r*m_r;
    }
    float perimeter(){
        return 2*3.14*m_r;
    }
};
int main()
{
    float r;
    cin>>r;
    Circle c1(r);
    Circle c2(c1);
    cout<<c1.area()<<endl;//计算圆面积
    cout<<c2.perimeter()<<endl;//计算圆周长
    return 0;
}

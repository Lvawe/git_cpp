#include<iostream>
using namespace std;

/* 请在这里填写答案 */
class Point
{
    double a, b;
public:
    Point(double a1, double b1):a(a1),b(b1){    }
    Point operator+(const Point& p)
    {
        return Point(a + p.a, b + p.b);
    }
    Point operator-(const Point& p)
    {
        return Point(a - p.a, b - p.b);
    }
    Point operator+=(const Point &p)
    {
        a += p.a;
        b += p.b;
        return *this;
    }
    bool operator==(Point& p)
    {
        if (a == p.a && b == p.b)
            return true;
        else
            return false;
    }
    friend ostream& operator<<(ostream &out,Point &p)  
    {
        out << p.a << "," << p.b;
        return out;
    }

//或者可以这样写
//friend ostream&operator<<(ostream &,Point &)；友元函数声明
};

//friend ostream&operator<<(ostream &out,Point &p)
// {
//         out<<p.a<<","<<p.b;
//        return out;
// }
int main(int argc, char const* argv[])
{
    Point p1(2, 3);
    cout << p1 << endl;
    Point p2(4, 5);
    cout << p2 << endl;
    Point p3 = p1 + p2;
    cout << p3 << endl;
    p3 = p2 - p1;
    cout << p3 << endl;
    p1 += p2;
    cout << p1 << endl;
    cout << (p1 == p2) << endl;
    return 0;
}
 

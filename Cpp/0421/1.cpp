#include <iostream>
using namespace std;

class Complex
{
    public:
        Complex(double r=0, double i=0):real(r), imag(i){    }
        Complex operator+( Complex & ) const;//重载双目运算符'+'
        Complex operator-=( Complex & ); //重载双目运算符'-='
        friend const Complex operator-( Complex &,Complex & ) ;//重载双目运算符'-'
        void Display() const;
    private:
        double real;
        double imag;
};

Complex Complex::operator + (Complex &C) const
{
    return Complex(real+C.real,imag+C.imag);        //重载 + 返回值为相加之后的结果
}
 
Complex Complex::operator-=(Complex &C)
{
    real=real-C.real;
    imag=imag-C.imag;
    return Complex(real,imag);          //重载 -= 返回值为减后结果，且对象本身数值也发生变化
}
 
Complex const operator - (Complex &C1,Complex &C2)   //重载 - 返回值为相减后的结果
{
    return Complex(C1.real-C2.real,C1.imag-C2.imag);
}
void Complex::Display() const
{
    cout << "(" << real << ", " << imag << ")" << endl;
}

int main()
{
    double r, m;
    cin >> r >> m;
    Complex c1(r, m);
    cin >> r >> m;
    Complex c2(r, m);
    Complex c3 = c1+c2;
    c3.Display();
    c3 = c1-c2;
    c3.Display();
    c3 -= c1;
    c3.Display();
    return 0;
}

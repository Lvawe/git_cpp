#include <iostream>
#include <iomanip>
using namespace std;

/* 你提交的代码将被嵌在这里 */
class COMPLEX {
private:
    float image,real;
public:
    COMPLEX(float a= 0,float b=0){
        real = a;
        image = b;
    }
     COMPLEX operator+( COMPLEX &a){
         return COMPLEX(a.real+real,a.image+image);
     }
    // COMPLEX operator-(COMPLEX &a){}
    // friend  COMPLEX operator+(float a,COMPLEX &b){
    //     COMPLEX p(a+b.real,b.image);
    //     return p;
    // }
    // friend  COMPLEX operator+(COMPLEX &b,float a){
    //     COMPLEX p(a+b.real,b.image);
    //     return p;
    // }
    friend ostream&operator<<(ostream&out,COMPLEX&a) {
        out<<a.real;
        if(a.image>=0) out<<'+';
        out<<a.image<<'i';
        return out; 
    }
    friend istream&operator>>(istream&in,COMPLEX&s) { 
        char sign;
        in>>s.real>>s.image;
        in>>sign;  
        return in;
    }
};

int main()
{
    COMPLEX a, b, c;
    cin >> a >> b;
    //c = a + b;
    cout << a << endl;
    return 0;
}

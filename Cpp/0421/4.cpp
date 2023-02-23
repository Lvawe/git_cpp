#include <iostream>
#include <iomanip>
using namespace std;

/* 你提交的代码将被嵌在这里 */
class COMPLEX
{
private:
    float r,i;
public:
    COMPLEX(float a=0,float b=0):r(a),i(b){
    }
    friend ostream&operator<<(ostream&out,COMPLEX&a) {
        
        out<<a.r<<"+"<<a.i<<'i';
        return out; 
    }
    friend istream&operator>>(istream&in,COMPLEX&s) { 
        char sign;
        in>>s.r>>s.i;
        in>>sign;  
        return in;
    }
    // COMPLEX operator+(const COMPLEX& p)
    // {
    //     return COMPLEX(r + p.r, i + p.i);
    // }
    // COMPLEX operator-(const COMPLEX& p)
    // {
    //     return COMPLEX(r - p.r, i - p.i);
    // }
};

int main()
{
    COMPLEX a, b, c;
    cin >> a >>b;
    //c = a + b;
    cout << a <<b<< endl;
    return 0;
}

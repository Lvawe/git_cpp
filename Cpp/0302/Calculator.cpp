#include<iostream>
using namespace std; 

class AbstractCalculator
{
    public:
    virtual int getResult()
    {
        return 0;
    }
    int m1,m2;
};
class SubCalculator:public AbstractCalculator
{
    int getResult()
    {
        return m1-m2;
    }
};
class AddCalculator:public AbstractCalculator
{
    int getResult()
    {
        return m1+m2;
    }
};
class MulCalculator:public AbstractCalculator
{
    int getResult()
    {
        return m1*m2;
    }
};
int main()
{
    AbstractCalculator *abc=new SubCalculator;
    abc->m1=10;
    abc->m2=20;
    cout<<abc->getResult();
    return 0;
}

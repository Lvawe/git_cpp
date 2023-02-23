#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Int
{
public:
	Int()
	{
		m_data=0;
	}
 
	Int(int data)
	{
		m_data=data;
	}
 
	~Int(){	}
 
	int getData() const
	{
		return m_data;
	}
 
	const Int operator + (const Int & l)
	{ 
        m_data += l.m_data;
		return *this;
    }
 
private:
	int m_data;
};
int main()
{
	Int a(1);
	Int b(2);
	Int c(3);
 
	cout<<a.getData()<<" "<<b.getData()
		<<" "<<c.getData()<<endl;
 
	a=b+c;
 
	cout<<"计算结果："<<endl;
	cout<<a.getData()<<" "<<b.getData()
		<<" "<<c.getData()<<endl;
 
	return 0;
}
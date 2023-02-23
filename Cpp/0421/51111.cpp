#include <iostream>
using namespace std;
 
int& test1()
{
	int n = 5;
	return n;
}
 
 
void test2()
{
	int b = 8;
}
 
 
  
int main()
{
 
	int &i = test1();
	cout << i << endl;  // 输出 5
 
	int &b = test1();
	 
	cout << b << endl;  // 输出 5
	test2();
	cout << b << endl;  // 输出 8
 
	int c = test1();
	test2();
	cout << c << endl;  // 输出 5
 
	return 0;
 
}
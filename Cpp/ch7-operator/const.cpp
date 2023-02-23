#include <iostream>
using namespace std;
Class class{

};
int main()
{
    const double e = 2.71828182845905;
    const char msg[] = "warning: ";

    void fun1(const int var);//var本身作为形参，就不会被修改
    void fun2(const int *var);//var所指的数据只读不会被改变
    void fun3(int *const var );//无意义，int *var作为形参
    void fun4(const int &var);//引用参数在函数内为常量不可变
    void fun5(const Class &var);//引用参数为类在函数内为常量不可变
    const int fun1() //参数返回本身就是赋值，无意义
    const int * fun2() //把fun2()看作成一个变量，指针所指内容不可变
    int* const fun3()   //把fun3()看作成一个变量，即指针本身不可变
}
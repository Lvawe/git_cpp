#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 已知表示点的类CPoint和表示线段的CLine类，
// 类CPoint包含：（1）表达点位置的私有数据成员x,y
// （2）构造函数及复制构造函数
class CPoint
{
    friend class CLine;
private:
    int m_x,m_y;
public:
    CPoint(){}
    CPoint(int x,int y):m_x(x),m_y(y){}
    CPoint(const CPoint &p){
        m_x=p.m_x;
        m_y=p.m_y;
    }
};
// 类CLine包含：
// （1）两个CPoint的点对象（该两点分别为线段的两个端点）
// （2）构造函数（提示：构造函数中用初始化列表对内嵌对象进行初始化）
// （3）公有成员函数GetLen，其功能为返回线段的长度，返回值类型为整型
// （4）类属性成员count用于记录创建的CLine类对象的个数，及用于显示count值的ShowCount函数；
class CLine
{
private:
    CPoint p1,p2;
    static int count;
public:
    CLine(CPoint q,CPoint r):p1(q),p2(r){count++;}
    CLine(const CLine &line){
		count++;
		p1=line.p1;
		p2=line.p2;
	}
    int GetLen()
    {
        int m=(p1.m_x-p2.m_x)*(p1.m_x-p2.m_x)+(p1.m_y-p2.m_y)*(p1.m_y-p2.m_y);
        return sqrt(m);
    }
    static int ShowCount()
    {
        return count;
    }
};
int CLine::count=0;
// 要求：
// （1）实现满足上述属性和行为的CPoint类及CLine类定义；
// （2）保证如下主函数能正确运行。
int main(){
     int x,y;
     cin>>x>>y;
     CPoint p1(x,y);
     cin>>x>>y;
     CPoint p2(x,y);
     CLine line1(p1,p2);
     cout<<"the length of line1 is:"<<line1.GetLen()<<endl;
     CLine line2(line1);
     cout<<"the length of line2 is:"<<line2.GetLen()<<endl;
     cout<<"the count of CLine is:"<<CLine::ShowCount()<<endl; 
     return 0;
}

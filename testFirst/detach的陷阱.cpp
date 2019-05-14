#include <iostream>
using namespace std;

#include "thread"

class A
{
public:
	int m_i;
	A(int m) :m_i(m)
	{
		cout << "构造函数" << endl;
	}
	A(const A &a) :m_i(a.m_i)
	{
		cout << "copy 构造函数" << endl;
	}
	~A()
	{
		cout << " 析构函数" << endl;
	}
};

void functionTest(int i,const A& a)
{
	cout << i << endl;
	cout << a.m_i << endl;
}
int main24()
{
	//情况一
	//thread myobj(functionTest, 1, 12); //这里是可以进行隐式类型转换12 -> A
	//myobj.detach();

	//情况二
	//int a = 1;
	//int b = 12;
	//thread myobj(functionTest, a, b);// 这里根本没有调用构造函数
	//myobj.detach();

	//情况三
	thread myobj(functionTest, 1, A(12));
	myobj.detach();
	return 0;
}
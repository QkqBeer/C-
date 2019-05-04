#include <iostream>
using namespace std;
/*
注意事项：
	1.发生异常，是可以跨函数的，方案一
	2.接受异常可以不处理，再向上一层抛出，方案二
*/
void divid(int a, int b)
{
	if (b == 0)
	{
		throw a;
	}
	cout << a / b << endl;
}

//再添加一层函数调用，可以使用断点查询函数异常的传递顺序
void MyDivid(int a, int b)
{
	//分别使用下面两种方法调用查看异常的返回顺序
	//方案一：
	//divid(a, b);
	//方案二：
	try
	{
		divid(a, b);
	}
	catch (...)
	{
		throw;
	}
}
int main10()
{
	try
	{
		MyDivid(10, 0);
	}
	catch (int e)
	{
		cout << e << "不能被0整除" << endl;
	}
	return 0;
}
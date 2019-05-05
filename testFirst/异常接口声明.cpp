#include <iostream>
using namespace std;

//可以抛出任何异常
void Test1(int a, int b)
{

}

//不抛出任何异常，如果发生异常，则unexpected函数被调用，该函数默认调用terminate函数终止程序
void Test2(int a, int b) throw()
{

}

//可以抛出int, char, char*三种异常
void Test3(int a, int b) throw(int, char, char*)
{

}

int main11()
{
	Test1(2, 3);
	Test2(2, 3);
	Test3(2, 3);
	return 0;
}
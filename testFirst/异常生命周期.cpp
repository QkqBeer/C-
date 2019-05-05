#include <iostream>
using namespace std;

class MyException
{
public:
	MyException();
	MyException(const MyException &obj);
	~MyException();
};

MyException::MyException()
{
	cout << "构造函数" << endl;
}
MyException::MyException(const MyException &obj)
{
	cout << "copy构造函数" << endl;

}

MyException::~MyException()
{
	cout << "析构函数" << endl;

}

void exceptionPlay(char* from, char* to)
{
	if (*from == 'a')
	{
		throw MyException();
	}

	if (*from == 'b')
	{
		throw new MyException;  //必须使用new来给指针分配空间，不然下面的容易生成野指针
	}
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

int main13()
{
	char from[] = "babcdef";
	char to[1024] = {0};
	try
	{
		exceptionPlay(from, to);
		
	}
	//结论1: 如果 接受异常的时候 使用一个异常变量,则copy构造异常变量.  
	//结论2: 使用引用的话 会使用throw时候的那个对象
	//结论3: 指针可以和引用/元素写在一块 但是引用/元素不能写在一块
	//结论4: 类对象时, 使用引用比较合适 
	/*
	catch (MyException e)
	{
		cout << "MyException异常" << endl;
	}
	*/
	
	catch (MyException &e)
	{
		cout << "MyException引用类型异常" << endl;
	}
	catch (MyException* e)
	{
		cout << "MyException指针类型异常" << endl;
		delete e; //在这里必须释放，不然容易导致内存泄漏
	}
	catch (...)
	{
		cout << "...." << endl;
	}
	return 0;
}
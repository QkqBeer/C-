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
	cout << "���캯��" << endl;
}
MyException::MyException(const MyException &obj)
{
	cout << "copy���캯��" << endl;

}

MyException::~MyException()
{
	cout << "��������" << endl;

}

void exceptionPlay(char* from, char* to)
{
	if (*from == 'a')
	{
		throw MyException();
	}

	if (*from == 'b')
	{
		throw new MyException;  //����ʹ��new����ָ�����ռ䣬��Ȼ�������������Ұָ��
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
	//����1: ��� �����쳣��ʱ�� ʹ��һ���쳣����,��copy�����쳣����.  
	//����2: ʹ�����õĻ� ��ʹ��throwʱ����Ǹ�����
	//����3: ָ����Ժ�����/Ԫ��д��һ�� ��������/Ԫ�ز���д��һ��
	//����4: �����ʱ, ʹ�����ñȽϺ��� 
	/*
	catch (MyException e)
	{
		cout << "MyException�쳣" << endl;
	}
	*/
	
	catch (MyException &e)
	{
		cout << "MyException���������쳣" << endl;
	}
	catch (MyException* e)
	{
		cout << "MyExceptionָ�������쳣" << endl;
		delete e; //����������ͷţ���Ȼ���׵����ڴ�й©
	}
	catch (...)
	{
		cout << "...." << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;

#include "thread"

class A
{
public:
	int m_i;
	A(int m) :m_i(m)
	{
		cout << "���캯��" << endl;
	}
	A(const A &a) :m_i(a.m_i)
	{
		cout << "copy ���캯��" << endl;
	}
	~A()
	{
		cout << " ��������" << endl;
	}
};

void functionTest(int i,const A& a)
{
	cout << i << endl;
	cout << a.m_i << endl;
}
int main24()
{
	//���һ
	//thread myobj(functionTest, 1, 12); //�����ǿ��Խ�����ʽ����ת��12 -> A
	//myobj.detach();

	//�����
	//int a = 1;
	//int b = 12;
	//thread myobj(functionTest, a, b);// �������û�е��ù��캯��
	//myobj.detach();

	//�����
	thread myobj(functionTest, 1, A(12));
	myobj.detach();
	return 0;
}
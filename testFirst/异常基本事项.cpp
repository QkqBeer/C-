#include <iostream>
using namespace std;
/*
ע�����
	1.�����쳣���ǿ��Կ纯���ģ�����һ
	2.�����쳣���Բ�����������һ���׳���������
*/
void divid(int a, int b)
{
	if (b == 0)
	{
		throw a;
	}
	cout << a / b << endl;
}

//�����һ�㺯�����ã�����ʹ�öϵ��ѯ�����쳣�Ĵ���˳��
void MyDivid(int a, int b)
{
	//�ֱ�ʹ���������ַ������ò鿴�쳣�ķ���˳��
	//����һ��
	//divid(a, b);
	//��������
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
		cout << e << "���ܱ�0����" << endl;
	}
	return 0;
}
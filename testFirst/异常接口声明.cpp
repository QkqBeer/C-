#include <iostream>
using namespace std;

//�����׳��κ��쳣
void Test1(int a, int b)
{

}

//���׳��κ��쳣����������쳣����unexpected���������ã��ú���Ĭ�ϵ���terminate������ֹ����
void Test2(int a, int b) throw()
{

}

//�����׳�int, char, char*�����쳣
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
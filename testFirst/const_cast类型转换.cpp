#include <iostream>
using namespace std;

void stringPlay(const char *p)
{
	char* pBuf;
	pBuf = const_cast<char *>(p);
	pBuf[0] = 'Z';
}

int main9()
{
	char p[] = "abcdefghijk"; //�Ѿ�����ռ�
	stringPlay(p);
	cout << p << endl;

	const char *newP = "abcdefgh"; 
	/*
	newP����ָ��һ���ַ�������������char *newP = "abcdefgh";������﷨����
	û�и�newP����ռ䣬���Բ��ܵ�������ķ���
	*/

	return 0;
}
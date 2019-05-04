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
	char p[] = "abcdefghijk"; //已经分配空间
	stringPlay(p);
	cout << p << endl;

	const char *newP = "abcdefgh"; 
	/*
	newP这是指向一个字符串常量，所以char *newP = "abcdefgh";会出现语法错误，
	没有给newP分配空间，所以不能调用上面的方法
	*/

	return 0;
}
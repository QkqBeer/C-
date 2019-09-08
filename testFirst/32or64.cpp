#include<iostream>
using namespace std;

int main32or64()
{
	void *a = 0;
	cout << sizeof(a) << endl;

#ifdef  __x86_64__
	cout << "x86_64__" << endl;
#elif __i386__
	cout << "__i386__" << endl;
#endif //  __x86_64__

	int i = 0x12345678;
	char* c = (char*)& i;
	cout << (c[0] == 0x78); //低位置存的是低位数据
	return 0;
}
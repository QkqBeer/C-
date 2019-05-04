#include <iostream>
using namespace std;

template <typename T>
class A
{
public:
	A(T a);
	~A();
	T printA();

private:
	T a;
};
template <typename T>
A<T>::A(T a)
{
	this->a = a;
}
template <typename T>
A<T>::~A()
{
}
template <typename T>
T A<T>::printA()
{
	cout << this->a << endl;
	return a;
}

void useA(A<int> &a1)
{
	a1.printA();
}
int main3()
{
	A<int> a1(10);
	cout << a1.printA() << endl;
	useA(a1);
	char p[] = "abcdef";
	//cout << sizeof(p) << endl;
	A<char *> a2(p);
	cout << a2.printA()[0] << endl;
	return 0;
}
#include <iostream>
using namespace std;

template <typename T>
class A
{
public:
	A(T a)
	{
		this->a = a;
	}
	~A()
	{
	}
	void printObj()
	{
		cout << a << endl;
	}

private:
protected:
	T a;
};

class B:public A<int>
{
public:
	B(int a = 1, int b = 2):A(a)
	{
		this->b = b;
	}
	~B()
	{

	}
	void printObjSon()
	{
		cout << "a: " << a << "  b: " << b << endl;
	}

private:
	int b;
};

template <typename T>
class C:public A<T>
{
public:
	C(T a, T c) :A<T>(a)
	{
		this->c = c;
	}
	~C()
	{

	}
	void printC()
	{
		cout << c << endl;
	}

private:
	T c;
};

int main4()
{
	/* //具体的类继承
	B b1(2, 3);
	b1.printObjSon();*/

	C <int>c1(1, 2);
	c1.printC();
	return 0;
}

#include <iostream>
using namespace std;

class MyArrayL
{
public:
	MyArrayL();
	MyArrayL(int size);
	int& operator[](int index);
	int getLen();
	~MyArrayL();
public:
	class eSize
	{
	public:
		eSize(int size)
		{
			this->e_size = size;
		}
		~eSize(){}
		virtual void printE()
		{
			cout << e_size << "Exception" << endl;
		}
	protected:
		int e_size;
	};
	class eNegative:public eSize
	{
	public:
		eNegative(int size):eSize(size)
		{

		}
		virtual void printE()
		{
			cout << e_size << "eNegative" << endl;
		}
	};

	class eZero :public eSize
	{
	public:
		eZero(int size) :eSize(size)
		{

		}
		virtual void printE()
		{
			cout << e_size << "eZero" << endl;
		}
	};
	class eTooSmall :public eSize
	{
	public:
		eTooSmall(int size) :eSize(size)
		{

		}
		virtual void printE()
		{
			cout << e_size << "eTooSmall" << endl;
		}
	};
	class eTooBig :public eSize
	{
	public:
		eTooBig(int size) :eSize(size)
		{

		}
		virtual void printE()
		{
			cout << e_size << "eTooBig" << endl;
		}
	};
private:
	int size;
	int* m_space;
};

MyArrayL::MyArrayL()
{
	this->size = 0;
	this->m_space = NULL;
}
MyArrayL::MyArrayL(int size)
{
	this->size = size;
	if (size < 0)
	{
		throw eNegative(size);
	}
	else if (size == 0)
	{
		throw eZero(size);
	}
	else if (size < 3)
	{
		throw eTooSmall(size);
	}
	else if (size > 1000)
	{
		throw eTooBig(size);
	}
	
	this->m_space = new int[size];
}
MyArrayL::~MyArrayL()
{
	if (this->m_space != NULL)
	{
		delete[] this->m_space;
		this->size = 0;
	}
}
int& MyArrayL::operator[](int index)
{
	return this->m_space[index];
}
int MyArrayL::getLen()
{
	return size;
}
int main14()
{
	try
	{
		MyArrayL a(2);
		for (int i = 0; i < a.getLen(); i++)
		{
			a[i] = i + 1;
			printf("%d ", a[i]);
		}
	}
	catch (MyArrayL::eSize &e)
	{
		e.printE();
	}
	catch (...)
	{
		cout << "other type exception" << endl;
	}
	return 0;
}
#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
	friend ostream& operator << <T>(ostream& out, MyVector<T> &myv);
public:
	MyVector();
	MyVector(int size);
	~MyVector();
	int getLen();
	MyVector& operator=(MyVector<T>& myv);
	MyVector(MyVector<T>& myv);
	T & operator[](int index);

private:
	int size;
	T *m_space;
};



#include <iostream>
using namespace std;
#include "MyVector.h"

template <typename T>
MyVector<T>::MyVector()
{
	this->size = 0;
	this->m_space = NULL;
}

template <typename T>
MyVector<T>::MyVector(int size)
{
	this->size = size;
	this->m_space = new T[size];
}

template <typename T>
int MyVector<T>::getLen()
{
	return size;
}

template <typename T>
ostream& operator << (ostream& out, MyVector<T> &myv)
{
	for (int i = 0; i < myv.getLen(); ++i)
	{
		out << myv.m_space[i] << " ";
	}
	out << endl;
	return out;
}

template <typename T>
MyVector<T>::~MyVector()
{
	if (this->m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;
		size = 0;
	}
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>& myv)
{
	if (this->m_space != NULL)
	{
		delete[] this->m_space;
		this->m_space = NULL;
		this->size = 0;
	}
	this->size = myv.getLen();
	this->m_space = new T[size];
	for (int i = 0; i < myv.getLen(); ++i)
	{
		m_space[i] = myv.m_space[i];
	}
	return *this;
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>& myv)
{
	this->size = myv.getLen();
	this->m_space = new T[size];
	for (int i = 0; i < myv.getLen(); ++i)
	{
		m_space[i] = myv.m_space[i];
	}
}
template <typename T>
T& MyVector<T>::operator[](int index)
{
	return this->m_space[index];
}
#include <iostream>
using namespace std;

template <typename T>
class Complex
{   
	//Ϊ�˱���bug�����Խ���Ԫ����д������ڲ�����Ϊ��������ģ���ඨ��ʱ��C++����������ȷ������Ĵ�С
	friend ostream& operator<< <T>(ostream& out, Complex& c); //ע��۲죬<T>��λ����
public:
	Complex(T a, T b);
	Complex& operator+(Complex& c2);

private:
	T a;
	T b;
};
template<typename T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

template<typename T>
Complex<T>& Complex<T>::operator+(Complex& c2)
{
	Complex tmp(a + c2.a, b + c2.b);
	return tmp;
}

//��������ص�����д��������<< >> ֻ������Ԫ�����������������Ҫд�ɳ�Ա��������Ҫ������Ԫ����
template <typename T>
ostream& operator<<(ostream &out, Complex<T> &c)
{
	out << c.a << "+" << c.b << "i" << endl;
	return out;
}
int main5()
{
	Complex<int> c1(1, 2);
	Complex<int> c2(2, 3);
	Complex<int> c3 = c1 + c2;
	cout << c3 << endl;
	
	return 0;
}
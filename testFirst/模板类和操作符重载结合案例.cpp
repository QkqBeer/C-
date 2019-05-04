#include <iostream>
using namespace std;

template <typename T>
class Complex
{   
	//为了避免bug，所以将友元函数写到类的内部，因为放在外面模板类定义时，C++编译器不能确定对象的大小
	friend ostream& operator<< <T>(ostream& out, Complex& c); //注意观察，<T>的位置上
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

//运算符重载的正规写法：重载<< >> 只能用友元函数，其他运算符都要写成成员函数，不要滥用友元函数
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
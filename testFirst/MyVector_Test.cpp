#include <iostream>
using namespace std;
#include "My_Vector.cpp"

class Teacher
{
public:
	Teacher()
	{
		age = 33;
		m_p = new char[1];
		strcpy(m_p,"");
	}
	Teacher(int age, char* name)
	{
		this->age = age;
		this->m_p = new char[strlen(name) + 1];
		strcpy(this->m_p, name);
	}
	Teacher(Teacher& t)
	{
		this->age = t.age;
		this->m_p = new char[strlen(t.m_p) + 1];
		strcpy(this->m_p, t.m_p);
	}
	~Teacher()
	{
		if (m_p != NULL)
		{
			delete[]m_p;
			m_p = NULL;
		}
	}
	
private:
	int age;
	char *m_p;
};



int main7()
{
	MyVector<int> myv1(10);
	for (int i = 0; i < myv1.getLen(); ++i)
	{
		myv1[i] = i;
	}
	cout << myv1 << endl;
	
	//这样才是等号的重载调用
	MyVector <int> myv2;
	myv2 = myv1;
	cout << myv2 << endl;

	//MyVector <int> myv3 = myv1;这样才是copy构造函数
	MyVector <int> myv3 = myv1;
	cout << myv3 << endl;

	//char类型检测
	MyVector<char> myv4(4);
	myv4[0] = 'a';
	myv4[1] = 'b';
	myv4[2] = 'c';
	myv4[3] = 'd';
	cout << myv4 << endl;



	return 0;
}
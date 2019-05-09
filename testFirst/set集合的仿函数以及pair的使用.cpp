#include <iostream>
using namespace std;
#include "set"
#include "string"
class Student
{   
	friend ostream& operator <<(ostream &out, Student & obj);
public:
	Student(string  name, int age)
	{
		this->age = age;
		this->name = name;
	}
public:
	int age;
	string name;
};
ostream& operator<<(ostream &out, Student & obj)
{
	out << obj.name << " : " << obj.age;
	return out;
}
struct setFunc
{
	bool operator()(const Student &left, const Student &right)
	{
		if (left.age < right.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void PrintS(set<Student, setFunc> s)
{
	for (set<Student, setFunc>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << it->name << "  :  "  << it->age << endl;
		//cout << *it << endl; //实在不明白这里的<<重载为什么不起作用
	}
}


int main17()
{
	set<Student, setFunc> s;
	
	Student s1("s1", 31);
	Student s2("s2", 32);
	Student s3("s3", 33);
	Student s4("s4", 34);
	Student s5("s5", 31);
	pair<set<Student, setFunc>::iterator, bool> pair1 = s.insert(s1);
	if (pair1.second)
	{
		cout << "insert success" << endl;
	}
	else
	{
		cout << "insert fail" << endl;
	}
	s.insert(s2);
	s.insert(s3);
	s.insert(s4);
	pair<set<Student, setFunc>::iterator, bool> pair2 = s.insert(s5);
	if (pair2.second)
	{
		cout << "insert success" << endl;
	}
	else
	{
		cout << "insert fail" << endl;
	}
	PrintS(s);

	return 0;
}

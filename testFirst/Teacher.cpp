#include <iostream>
using namespace std;
class Teacher
{
public:
	Teacher()
	{
		age = 33;
		this->name = NULL;
	}
	~Teacher()
	{

	}
	Teacher(int age, char *name)
	{
		this->age = age;
		int len = strlen(name);
		this->name = new char[len - 1];
		for (int i = 0; i < len; i++)
		{
			this->name[i] = name[i];
			//cout << name[i];
		}
	}
	void PrintT()
	{
		cout << name << endl;
	}

private:
	int age;
	char *name;
};

int main6()
{
	char name[] = "abcd";
	Teacher t1(2, name);
	t1.PrintT();
	cout << sizeof(t1) << endl;
	return 0;
}
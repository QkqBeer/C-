#include <iostream>
using namespace std;
#include "string"
#include "map"
class Person
{
public:
	Person(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
	
public:
	int age;
	string name;
};


void multimapTest(multimap<string, Person> &m)
{
	Person p1(31, "a");
	Person p2(32, "b");
	Person p3(33, "c");
	Person p4(34, "d");
	Person p5(35, "e");
	m.insert(pair<string, Person>("sale", p1));
	m.insert(pair<string, Person>("sale", p2));
	m.insert(pair<string, Person>("development", p3));
	m.insert(pair<string, Person>("development", p4));
	m.insert(pair<string, Person>("hr", p5));
	//update
	for (multimap<string, Person>::iterator it = m.begin(); it != m.end(); it++)
	{	
		if (it->second.name == "a")
		{
			it->second.age = 53;
		}
	}

	//²é 
	for (multimap<string, Person>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " : " << it->second.name << "   " <<it->second.age <<endl;
	}
	
	int count = m.count("development");
	int flag = 0;
	multimap<string, Person>::iterator it = m.find("development");
	while (it != m.end() && flag < count)
	{
		cout << it->first << " : " << it->second.name << endl;
		it++;
		flag++;
	}
}
int main19()
{
	multimap<string, Person> m;
	multimapTest(m);
	return 0;
}
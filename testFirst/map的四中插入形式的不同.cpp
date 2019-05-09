#include <iostream>
using namespace std;

#include "map"
#include "string"

void testInsert(map<int, string> &m)
{
	//first insert method
	m.insert(pair<int, string>(1, "teacher1"));
	//second insert method
	m.insert(make_pair<int, string>(2, "teacher2"));
	//third insert method
	m.insert(map<int, string>::value_type(3, "teacher3"));
	//forth insert method
	m[4] = "teacher4";
	//四种方法异同：前三种方法当出现重复键时，编译器会报错，而第四种方法，当键重复时，会覆盖掉之前的键值对。

	//使用前三种方法可以的到一个返回值pair，该pair的类型是 pair<map<int, string>::iterator, bool>
	pair<map<int, string>::iterator, bool> pair1 = m.insert(pair<int, string>(1, "teacher5"));
	if (pair1.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}
	m[4] = "teacher6";
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}
}

int main18()
{
	map<int, string> m;
	testInsert(m);
	return 0;
}
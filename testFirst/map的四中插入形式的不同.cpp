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
	//���ַ�����ͬ��ǰ���ַ����������ظ���ʱ���������ᱨ���������ַ����������ظ�ʱ���Ḳ�ǵ�֮ǰ�ļ�ֵ�ԡ�

	//ʹ��ǰ���ַ������Եĵ�һ������ֵpair����pair�������� pair<map<int, string>::iterator, bool>
	pair<map<int, string>::iterator, bool> pair1 = m.insert(pair<int, string>(1, "teacher5"));
	if (pair1.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
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
#include<iostream>
#include<utility>
#include<vector>
#include<string>

using namespace std;
int mainmove()
{
	std::string str = "Hello";
	std::vector<std::string> v;
	//���ó���Ŀ������캯�����½��ַ����飬��������
	v.push_back(str);
	std::cout << "After copy, str is \"" << str << "\"\n";
	//�����ƶ����캯�����Ϳ�str���Ϳպ���ò�Ҫʹ��str
	v.push_back(std::move(str));
	std::cout << "After move, str is \"" << str << "\"\n";
	std::cout << "The contents of the vector are \"" << v[0]
		<< "\", \"" << v[1] << "\"\n";
	return 0;
}
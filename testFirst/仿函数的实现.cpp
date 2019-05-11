#include <iostream>
using namespace std;
#include "vector"
#include "algorithm"



template <typename T>
class ShowElem
{
public:
	void operator()(T &t)
	{
		cout << t << endl;
	}
};

int main20()
{
	int a = 10;
	ShowElem<int> showElem;
	showElem(a);

	vector <int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	//for_each中的函数参数（3号位置参数），只是一个形参值传递，而不是引用传递。
	for_each(v1.begin(), v1.end(), showElem);
	return 0;
}


#include <iostream>
using namespace std;

template <typename T>
void myswap(T a, T b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
	cout << "welcome to the template func" <<endl;
}
int main1()
{
	myswap(1, 2);
	myswap('a', 'b');
	return 0;
}

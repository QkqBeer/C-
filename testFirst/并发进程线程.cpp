#include <iostream>
using namespace std;
#include "map"
#include "thread"

//method 1
class TA
{
public:
	void operator()()
	{
		cout << "class thread start!" << endl;
		//....
		cout << "class thread end!" << endl;
	}

};

//method 2
void funcT()
{
	cout << "func thread start!" << endl;
	//....
	cout << "func thread end!" << endl;
}

int main23()
{   
	TA ta;
	thread mycobj(ta);
	thread myfobj(funcT);

	mycobj.join();
	if (myfobj.joinable())
	{
		myfobj.join();
	}

	auto mylambdaFunc = []()
	{
		cout << "lambdaFunc strat! " << endl;
		//...
		cout << "lambdaFunc end! " << endl;
	};

	thread mymobj(mylambdaFunc);
	mymobj.join();

	return 0;
}

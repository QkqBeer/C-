#include <iostream>
#include <string>
#include <thread>
#include <future>
using namespace std;
class A
{
public:
	int mythread(int param)
	{
		cout << "strat_thread_id :" << std::this_thread::get_id() << endl;
		std::chrono::milliseconds dura(param);
		this_thread::sleep_for(dura);
		cout << "end_thread_id:" << std::this_thread::get_id() << endl;
		return 5;
	}

};



int main33()
{
	A a;
	int timeParam;
	cout << "mainFunc_thread_id: " << std::this_thread::get_id() << endl;
	cout << "ÇëÊäÈëÑÓ³ÙÊ±¼ä: ";
	cin >> timeParam;
	std::future<int> result = std::async(&A::mythread, &a, timeParam);
	//do something
	cout << "return value: " << result.get() << endl;
	cout << "hahaha" << endl;
	return 0;
}
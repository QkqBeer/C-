#include <iostream>
#include <string>
#include <thread>
#include <future>
using namespace std;
int mythread()
{
	cout << "strat_thread_id :" << std::this_thread::get_id() << endl;
	std::chrono::milliseconds dura(5000);
	this_thread::sleep_for(dura);
	cout << "end_thread_id:" << std::this_thread::get_id() << endl;
	return 5;
}

int main32()
{
	cout << "mainFunc_thread_id: " << std::this_thread::get_id() << endl;
	std::future<int> result = std::async(mythread);   //async的第一个默认参数是std::launch::async|std::launch::referred
	//do something
	cout << "return value: " << result.get() << endl;
	cout << "hahaha" << endl;
	return 0;
}
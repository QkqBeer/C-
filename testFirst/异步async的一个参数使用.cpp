#include <iostream>
#include "thread"
#include "future"

using namespace std;

int mythread1()
{
	cout << "this threadId: " << this_thread::get_id() << endl;
	this_thread::sleep_for(5s); //新的时间用法
	return 1;
}

int main37()
{
	cout << "main thread Id: " << this_thread::get_id() << endl;
	//std::async(std::launch::async, mythread); //表示在这儿强制创建线程
	//std::async(std::launch::deferred, mythread); //表示不创建线程
	std::future<int> result = std::async(mythread1);//默认参数是std::launch::deferred|std::launch::async
	std::future_status status = result.wait_for(0s);

	if (status == std::future_status::deferred)
	{
		cout << result.get() << endl;
	}
	else
	{
		if (status == std::future_status::ready)
		{
			cout << "thread 成功执行并返回！" << endl;
			cout << result.get() << endl;
		}
		else if (status == std::future_status::timeout)
		{
			cout << "timeOut" << endl;
			cout << result.get() << endl;
		}
	}
	return 0;
}
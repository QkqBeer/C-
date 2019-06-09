#include <iostream>
#include "thread"
#include "future"

using namespace std;

int mythread1()
{
	cout << "this threadId: " << this_thread::get_id() << endl;
	this_thread::sleep_for(5s); //�µ�ʱ���÷�
	return 1;
}

int main37()
{
	cout << "main thread Id: " << this_thread::get_id() << endl;
	//std::async(std::launch::async, mythread); //��ʾ�����ǿ�ƴ����߳�
	//std::async(std::launch::deferred, mythread); //��ʾ�������߳�
	std::future<int> result = std::async(mythread1);//Ĭ�ϲ�����std::launch::deferred|std::launch::async
	std::future_status status = result.wait_for(0s);

	if (status == std::future_status::deferred)
	{
		cout << result.get() << endl;
	}
	else
	{
		if (status == std::future_status::ready)
		{
			cout << "thread �ɹ�ִ�в����أ�" << endl;
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
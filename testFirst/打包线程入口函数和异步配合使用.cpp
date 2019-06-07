#include <iostream>
#include <thread>
#include <future>
using namespace std;


int mythread(int time)
{
	cout << "mythreadId: " << std::this_thread::get_id() << endl;
	std::chrono::milliseconds duar(time);
	std::this_thread::sleep_for(duar);
	return 5;
}

void mySecondThread(std::future<int>& temp)
{
	cout << "mySecondThreadId: " << std::this_thread::get_id() << endl;
	auto result = temp.get(); //get()�������ƶ����壬����ֻ�ܵ���һ�Σ����򱨴�
	cout << "result :" << result << endl;
	return;
}

int main35()
{
	cout << "main" << "thread_id: " << std::this_thread::get_id();
	std::packaged_task <int(int)> mypt(mythread);
	std::thread t1(std::ref(mypt), 4000); //�������һ������
	t1.join();

	std::future<int> re = mypt.get_future();
	std::thread t2(mySecondThread, std::ref(re));
	t2.join();
	cout << "hello world" << endl;
	return 0;
}
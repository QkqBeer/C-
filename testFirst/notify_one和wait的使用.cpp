#include <iostream>
#include "future"
#include "thread"
#include "list"

using namespace std;

class HelloNotify
{
public:
	void getMsg()
	{
		while (true)
		{
			std::unique_lock<std::mutex> bguard(mymutex);
			cond.wait(bguard, [this]
				{
					if (!MsgVector.empty())
						return true;
					return false;
				});
			int data = MsgVector.front();
			MsgVector.pop_front();
			bguard.unlock();
			cout << data << endl;
		}
	}
	void sendMsg()
	{
		for (int i = 0; i < 10000; ++i)
		{
			cout << "do sendMsg() insert a number: " << i << endl;
			std::unique_lock<std::mutex> bguard(mymutex);
			MsgVector.push_back(i);
			cond.notify_one();
		}
	}

private:
	std::list<int> MsgVector;
	std::condition_variable cond;
	std::mutex mymutex;
};

int main38()
{
	HelloNotify m;
	std::thread obj1(&HelloNotify::getMsg, &m);
	std::thread obj2(&HelloNotify::sendMsg, &m); //�ڶ������������ã����ܱ�֤�߳���ʹ�õ���ͬһ������

	obj1.join();
	obj2.join();
	return 0;
}
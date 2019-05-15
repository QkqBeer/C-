#include <iostream>
using namespace std;

#include <list>
#include <thread>
#include <mutex>
class A
{
public:
	void receiveMes()//������һ��Ĭ�ϲ���this
	{
		for (int i = 0; i < 10000; ++i)
		{
			my_mutex.lock();
			msgQueue.push_back(i);
			cout << "msgQueue insert " << i << endl;
			my_mutex.unlock();
		}
	}

	void dealMsg()
	{
		for (int i = 0; i < 10000; ++i)
		{  
			my_mutex.lock();
			if (!msgQueue.empty())
			{ 
				int command = msgQueue.front();
				cout << "deal msgQueue" << command << endl;
				msgQueue.pop_front();
			}
			my_mutex.unlock();
		}
	}
	

private:
	list<int> msgQueue;
	mutex my_mutex;
};

int main()
{
	A myobj;
	thread threadDeal(&A::dealMsg, &myobj);
	thread threadReceive(&A::receiveMes, &myobj); //����Ķ���Ҫ�������ݴ������Դ������á�
	
	threadReceive.join();
	threadDeal.join();
	return 0;
}
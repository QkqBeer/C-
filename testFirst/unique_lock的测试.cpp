#include <iostream>
using namespace std;

#include <list>
#include <thread>
#include <mutex>
class A
{
public:
	std::unique_lock<std::mutex> rtn_unique_lock()
	{
		unique_lock<std::mutex> tmpguard(my_mutex);
		return tmpguard;
	}
	void receiveMes()
	{
		for (int i = 0; i < 10000; ++i)
		{
			//std::lock_guard<std::mutex> sbguard(my_mutex, std::adopt_lock);
			//std::unique_lock<std::mutex> sbguard(my_mutex, std::adopt_lock);
			//上述两种方法相似，默认在尾部析构函数中释放mutex
			std::unique_lock<std::mutex> sbguard (my_mutex, std::try_to_lock);
			//尝试去锁定mutex,不会卡在这里不动
			//std::unique_lock<std::mutex> sbguard(my_mutex, std::defer_lock);
			//defer_lock是初始化一个没有加锁的mutex，其中的几个关键成员函数： lock(), unlock(), try_lock(),release();
			//lock() 加锁
			//unlock() 释放锁
			//try_lock() 尝试加锁，如果成功则返回true，否则false
			//release() 返回它所管理的mutex对象指针，释放所有权，也就是 说这个unique_lock和mutex没有关系  mutex *Pmutex = sbguard.release()
			//锁住的代码的多少称为粒度
			//sbguard 和 mutex之间的关系只能是一对一的关系，需要使用move函数,转移所有权
			//std::unique_lock<std::mutex> sbguard1 (std::move(sbguard));
			//或者：见上面的rtn_unique_lock()函数,返回一个局部变量会导致系统生成一个临时unique_lock对象，并调用unique_lock的移动构造函数

			if (sbguard.owns_lock())
			{
				msgQueue.push_back(i);
				cout << "msgQueue insert " << i << endl;
			}
			else
			{
				cout << "do some other thing" << endl;
			}
			
		}
	}

	void dealMsg()
	{
		for (int i = 0; i < 10000; ++i)
		{
			my_mutex.lock();
			std::chrono::milliseconds dura(20000);
			this_thread::sleep_for(dura);
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
	mutex my_mutex; //互斥量
};

int main26()
{
	A myobj;
	thread threadReceive(&A::receiveMes, &myobj); //传入的对象要进行数据处理，所以传入引用。
	thread threadDeal(&A::dealMsg, &myobj);
	

	threadReceive.join();
	threadDeal.join();
	return 0;
}
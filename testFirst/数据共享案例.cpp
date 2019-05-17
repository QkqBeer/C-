#include <iostream>
using namespace std;

#include <list>
#include <thread>
#include <mutex>
class A
{
public:
	void receiveMes()//里面有一个默认参数this
	{
		for (int i = 0; i < 10000; ++i)
		{
			
			//lock_guard <std::mutex> sbguard(my_mutex); 
			//这句话可以代替my_mutex.lock(); my_mutex.unlock();不用成对匹配，利用对象构造函数和析构函数的特点，隐式调用lock()和unlock()函数。
			//也可以使用下述方法：但是必须建立在拥有两个或两个以上互斥量的前提（两个互斥量的不同顺序会导致死锁）
			/* //这样也不需要自己去匹配着去写unlock()函数
			lock(my_mutex, my_mutex1);
			lock_guard<std::mutex>(my_mutex, std::adopt_lock);
			lock_guard<std::mutex>(my_mutex1, std::adopt_lock);
            */

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
	mutex my_mutex; //互斥量
	mutex my_mutex1; //互斥量
};

int main25()
{
	A myobj;
	thread threadDeal(&A::dealMsg, &myobj);
	thread threadReceive(&A::receiveMes, &myobj); //传入的对象要进行数据处理，所以传入引用。
	
	threadReceive.join();
	threadDeal.join();
	return 0;
}
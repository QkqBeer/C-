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
			
			//lock_guard <std::mutex> sbguard(my_mutex); 
			//��仰���Դ���my_mutex.lock(); my_mutex.unlock();���óɶ�ƥ�䣬���ö����캯���������������ص㣬��ʽ����lock()��unlock()������
			//Ҳ����ʹ���������������Ǳ��뽨����ӵ���������������ϻ�������ǰ�ᣨ�����������Ĳ�ͬ˳��ᵼ��������
			/* //����Ҳ����Ҫ�Լ�ȥƥ����ȥдunlock()����
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
	mutex my_mutex; //������
	mutex my_mutex1; //������
};

int main25()
{
	A myobj;
	thread threadDeal(&A::dealMsg, &myobj);
	thread threadReceive(&A::receiveMes, &myobj); //����Ķ���Ҫ�������ݴ������Դ������á�
	
	threadReceive.join();
	threadDeal.join();
	return 0;
}
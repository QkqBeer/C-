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
			//�������ַ������ƣ�Ĭ����β�������������ͷ�mutex
			std::unique_lock<std::mutex> sbguard (my_mutex, std::try_to_lock);
			//����ȥ����mutex,���Ῠ�����ﲻ��
			//std::unique_lock<std::mutex> sbguard(my_mutex, std::defer_lock);
			//defer_lock�ǳ�ʼ��һ��û�м�����mutex�����еļ����ؼ���Ա������ lock(), unlock(), try_lock(),release();
			//lock() ����
			//unlock() �ͷ���
			//try_lock() ���Լ���������ɹ��򷵻�true������false
			//release() �������������mutex����ָ�룬�ͷ�����Ȩ��Ҳ���� ˵���unique_lock��mutexû�й�ϵ  mutex *Pmutex = sbguard.release()
			//��ס�Ĵ���Ķ��ٳ�Ϊ����
			//sbguard �� mutex֮��Ĺ�ϵֻ����һ��һ�Ĺ�ϵ����Ҫʹ��move����,ת������Ȩ
			//std::unique_lock<std::mutex> sbguard1 (std::move(sbguard));
			//���ߣ��������rtn_unique_lock()����,����һ���ֲ������ᵼ��ϵͳ����һ����ʱunique_lock���󣬲�����unique_lock���ƶ����캯��

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
	mutex my_mutex; //������
};

int main26()
{
	A myobj;
	thread threadReceive(&A::receiveMes, &myobj); //����Ķ���Ҫ�������ݴ������Դ������á�
	thread threadDeal(&A::dealMsg, &myobj);
	

	threadReceive.join();
	threadDeal.join();
	return 0;
}
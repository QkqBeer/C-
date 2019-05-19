#include <iostream>
using namespace std;
#include "thread"
#include "mutex"

std::mutex resource_mutex;
class singleInstance
{
private:
	singleInstance() {}
public:
	static singleInstance* getInstance()
	{
		if (instanceT == NULL)//(Ë«ÖØËø¶¨)
		{
			unique_lock<std::mutex> mymutex(resource_mutex);
			if (instanceT == NULL)
			{
				instanceT = new singleInstance();
				static destory d;
			}
		}
		return instanceT;
	}
	void func()
	{
		cout << "test" << endl;
	}
	class destory
	{
	public:
		destory() {}
		~destory()
		{
			delete singleInstance::instanceT;
			singleInstance::instanceT = NULL;
		}
	};
private:
	static singleInstance* instanceT;
};

void threadFunc()
{
	cout << "thread start" << endl;
	singleInstance* s = singleInstance::getInstance();
	cout << "thread end" << endl;
}

singleInstance* singleInstance::instanceT = NULL;

int main()
{
	thread myobjThread1(threadFunc);
	thread myobjThread2(threadFunc);
	myobjThread1.join();
	myobjThread2.join();
	return 0;
}
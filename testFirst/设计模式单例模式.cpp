#include <iostream>
using namespace std;

class singleInstance
{
private:
	singleInstance(){}
public:
	static singleInstance* getInstance()
	{
		if (instance == NULL)
		{
			instance = new singleInstance();
			static destory d;
		}
		return instance;
	}
	void func()
	{
		cout << "test" << endl;
	}
	class destory
	{
	public:
		destory(){}
		~destory()
		{
			delete singleInstance::instance;
			singleInstance::instance = NULL;
		}
	};
private:
	static singleInstance* instance;
};

singleInstance* singleInstance::instance = NULL;

int main29()
{
	singleInstance *s1 = singleInstance::getInstance();
	singleInstance *s2 = singleInstance::getInstance();
	s1->func();
	return 0;
}
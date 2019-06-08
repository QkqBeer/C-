#include <iostream>
#include "thread"
#include "future"
using namespace std;

std::atomic<bool> g_flag = false;
void mythread()
{
	while (g_flag == false)
	{
		cout << "mythreadId: " << std::this_thread::get_id() << "ing" <<endl;
		std::chrono::milliseconds duar(1000);
		std::this_thread::sleep_for(duar);
	}
	cout << "mythreadId: " << std::this_thread::get_id() << "end" <<endl;
}

int main36()
{
	std::thread obj1(mythread);
	std::thread obj2(mythread);
	std::chrono::milliseconds dura(5000);
	std::this_thread::sleep_for(dura);
	g_flag = true;
	obj1.join();
	obj2.join();
	return 0;
}
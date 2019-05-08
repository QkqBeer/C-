#include <iostream>
using namespace std;
#include "string.h"


int main()
{
	string s1 = "abc 111 abc 222 abc 333";
	int index = s1.find("abc", 0);
	int count = 0;
	while (index != string::npos)
	{
		count++;
		cout << index << "  ";
		index = s1.find("abc", index + 3);
	}
	if (count == 0)
	{
		cout << "ц╩спур╣╫" << endl;
	}
	return 0;
}
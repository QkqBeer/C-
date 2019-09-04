#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	int findNthDigit(int n)
	{
		int i = 1;
		while (n > i * (pow(10, i - 1) * 9))
		{
			n -= i * (pow(10, i - 1) * 9);
			i += 1;
		}
		int num = (n - 1) / i + pow(10, i - 1);
		string tmp = to_string(num);
		if (n % i == 0)
		{
			return tmp[i - 1] - '0';
		}
		return tmp[n % i - 1] - '0';
	}
};

int main400()
{
	Solution s;
	cout << s.findNthDigit(3);
	return 0;
}
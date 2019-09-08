#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums)
	{
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp;
		vector<int> sp;
		dp.push_back(1);
		sp.push_back(1);
		for (int i = 1; i < nums.size(); i++)
		{
			dp.push_back(1);
			sp.push_back(1);
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
				{
					if (dp[j] + 1 > dp[i])
					{
						dp[i] = dp[j] + 1;
						sp[i] = sp[j];
					}
					else if (dp[j] + 1 == dp[i])
					{
						sp[i] += sp[j];
					}
				}
			}
		}
		int m = *max_element(dp.begin(), dp.end());
		int res = 0;
		for (int i = 0; i < sp.size(); i++)
		{
			if (dp[i] == m)
			{
				res += sp[i];
			}
		}
		return res;
	}
};


int main673()
{
	Solution s;
	vector<int> a = { 1, 3, 5, 4, 7 };
	cout << s.findNumberOfLIS(a);
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums)
	{
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp;
		dp.push_back(1);
		for (int i = 1; i < nums.size(); i++)
		{
			int tmp = 1;
			bool flag = false;
			for (int j = 0; j < i; j++)
			{	
				if (nums[i] > nums[j])
				{
					flag = true;
					tmp = max(tmp, dp[j]);
				}
			}
			if (!flag)
			{
				dp.push_back(tmp);
			}
			else
			{
				dp.push_back(tmp + 1);
			}
		}
		auto it = max_element(dp.begin(), dp.end());
		return *it;
	}
};
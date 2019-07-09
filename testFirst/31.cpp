#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums)
	{
		int size = nums.size();
		int flag = size - 1;
		bool t = false;
		for (int i = size - 1; i > 0; i--)
		{
			if (nums[i] > nums[i - 1])
			{
				flag = i;
				t = true;
				break;
			}
		}
		if (t)
		{
			int minmax = nums[flag];
			int index = flag;
			for (int i = flag; i < size; i++)
			{
				if (nums[i] > nums[flag - 1] && nums[i] < minmax)
				{
					index = i;
					minmax = nums[i];
				}
			}
			int t = nums[flag - 1];
			nums[flag - 1] = nums[index];
			nums[index] = t;
			for (int i = flag; i < size; i++)
			{
				for (int j = flag; j < size - 1; j++)
				{
					if (nums[j] > nums[j + 1])
					{
						int o = nums[j];
						nums[j] = nums[j + 1];
						nums[j + 1] = o;
					}
				}
			}
		}
		else
		{
			reverse(nums.begin(), nums.end());
		}

	}
};
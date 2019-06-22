/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool DFS(int i, int cur, vector<int> nums, int sum)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (cur + nums[j] == sum)
			{
				return true;
			}
			else if (cur + nums[j] > sum)
			{
				continue;
			}
			else
			{
				return DFS(j, cur + nums[j], nums, sum);
			}
		}
		return false;
	}
	bool canPartition(vector<int>& nums)
	{
		if (nums.empty()) return false;
		int sum = 0;
		for (int i : nums)
		{
			sum += i;
		}
		if (sum % 2) return false;
		sum /= 2;
		if (nums.back() > sum) return false;
		sort(nums.begin(), nums.end());
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			if (nums[i] == sum) return true;
			if (DFS(i, nums[i], nums, sum)) return true;
		}
		return false;
	}
};


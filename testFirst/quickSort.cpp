#include <iostream>
#include <vector>

using namespace std;

void quick(vector<int> & nums, int l, int r)
{
	int tmp = nums[l];
	int left = l;
	int right = r;
	if (l < r)
	{
		while (l < r)
		{
			while (l < r && nums[r] > tmp)
			{
				r--;
			}
			nums[l] = nums[r];
			while (l < r && nums[l] <= tmp)
			{
				l++;
			}
			nums[r] = nums[l];
		}
		nums[l] = tmp;
		quick(nums, left, l);
		quick(nums, l + 1, right);
	}
}

int mainquick()
{
	vector<int> r = { 4, 3, 2, 5, 6, 8, 0 };
	quick(r, 0, r.size() - 1);
	for (int i = 0; i < r.size(); i++)
	{
		cout << r[i] << " ";
	}
	return 0;
}
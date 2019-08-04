#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;
class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		int mask = 0;
		int res = 0;
		for (int i = 30; i >= 0; i--)
		{
			mask = mask | (1 << i);
			unordered_set<int>sets; //�������Թ���set,��tle������ hash����ţ�ƣ����Ͼ�O(1)
			for (auto num : nums) {
				sets.insert(num & mask);
			}

			int temp = res | (1 << i);
			for (auto it : sets) {
				if (sets.find(it ^ temp) != sets.end()) {
					res = temp;
					break;
				}
			}
		}
		return res;
	}
};

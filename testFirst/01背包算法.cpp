#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	01背包算法和部分背包算法的区别
	01背包算法：每件物品或被带走，或被留下，每件东西只能拿一次
	部分背包算法：可以只带走某个物品的一部分，不必做出0-1选择。
*/
int solution(vector<int> weight, vector<int> capacity, int size, int n)
{
	/*
	weight : 权重
	capacity : 体积
	size : 包的最大容量
	n : 多少个商品
	*/
	vector<vector<int>> data(n + 1, vector<int>(size + 1, 0));
	cout << data.size() << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (capacity[i - 1] > j) //放不下
			{
				data[i][j] = data[i - 1][j];
			}
			else
			{
				data[i][j] = max(data[i - 1][j - capacity[i - 1]] + weight[i - 1], data[i - 1][j]);
			}
		}
	}
	return data[n][size];
}

int main01()
{
	vector<int> weight = { 2,3,4,5 };
	vector<int> capacity = { 3,4,5,6 };
	int size = 8;
	int n = 4;
	cout << solution(weight, capacity, size, n);
	return 0;
}
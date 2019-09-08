#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	01�����㷨�Ͳ��ֱ����㷨������
	01�����㷨��ÿ����Ʒ�򱻴��ߣ������£�ÿ������ֻ����һ��
	���ֱ����㷨������ֻ����ĳ����Ʒ��һ���֣���������0-1ѡ��
*/
int solution(vector<int> weight, vector<int> capacity, int size, int n)
{
	/*
	weight : Ȩ��
	capacity : ���
	size : �����������
	n : ���ٸ���Ʒ
	*/
	vector<vector<int>> data(n + 1, vector<int>(size + 1, 0));
	cout << data.size() << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (capacity[i - 1] > j) //�Ų���
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

//int main()
//{
//	long  long m, n, r;
//	cin >> m;
//	cin >> n;
//	r = m % n;
//	while (r)
//	{
//		m = n;
//		n = r;
//		r = m % n;
//	}
//	cout << n << endl;
//	return 0;
//}

//需求是：insert，find
//find是查找里面有没有集合| 按位或可以得到该结果
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void getSonSet(int a, vector<vector<int>>& sonSet)
{
	if (sonSet.empty())
	{
		vector<int> n;
		n.push_back(a);
		sonSet.push_back(n);
	}
	else
	{
		vector <vector<int>> tp;
		for (int i = 0; i < sonSet.size(); i++)
		{
			vector <int> tmp = sonSet[i];
			tmp.push_back(a);
			tp.push_back(tmp);
		}
		sonSet.insert(sonSet.end(), tp.begin(), tp.end());
		vector<int> n;
		n.push_back(a);
		sonSet.push_back(n);
	}
}

int mainWangyi()
{
	int operate;
	cin >> operate;
	vector<vector<int>> res;
	set<int> t;
	for (int i = 0; i < operate; i++)
	{
		vector <int> n;
		int first, second;
		cin >> first >> second;
		n.push_back(first);
		n.push_back(second);
		res.push_back(n);
	}
    	
	for (int i = 0; i < operate; i++)
	{
		if (res[i][0] == 1)
		{
			t.insert(res[i][1]);
		}
		else
		{
			vector<vector<int>> sonSet;
			for (set<int>::iterator it = t.begin(); it != t.end(); it++)
			{
				getSonSet(*it, sonSet);
			}
			bool flag = false;
			for (int k = 0; k < sonSet.size(); k++)
			{
				int tmp = sonSet[k][0];
				for (int j = 0; j < sonSet[k].size(); j++)
				{
					tmp |= sonSet[k][j];
				}
				if (tmp == res[i][1])
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
//6
//1 2
//1 3
//2 1
//1 4
//2 6
//2 7

//#include <iostream>
//#include <vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	if (n == 0)
//	{
//		return 0;
//	}
//	vector<int> res(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> res[i];
//	}
//	vector<int> p;
//	for (int k = 1; k <= n; k++)
//	{
//		vector<int> t;
//		for (int i = 0; i <= n - k; i++)
//		{
//			//cout << i << endl;
//			int y = res[i];
//			for (int j = i + 1; j < i + k; j++)
//			{
//				//cout << y << "  " << res[j] << endl;
//				if (res[j] > y)
//				{
//					y = res[j];
//				}
//			}
//			t.push_back(y);
//		}
//		p.push_back(*min_element(begin(t), end(t)));
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		cout << p[i] << " ";
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include <algorithm>
//
//using namespace std;
//
//
//bool check(int m, int T, int M, vector<int> H)
//{
//	int t = H.size();
//	for (int i = 0; i < t; i++)
//	{
//		while (H[i] > 0 && T > 0)
//		{
//			if (H[i] > 1 && M > 0)
//			{
//				M--;
//				H[i] -= m;
//			}
//			else
//			{
//				H[i]--;
//			}
//			T--;
//		}
//		
//	}
//	
//	if (H[t - 1] <= 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//
//}
//int main22()
//{
//	int N, T, M;
//	//N 怪物数量 ， T 几回合，M初始法力值
//	vector<int> H;
//	cin >> N;
//	cin >> T;
//	cin >> M;
//	
//	for (int i = 0; i < N; i++)
//	{
//		int temp;
//		cin >> temp;
//		H.push_back(temp);
//	}
//	if (N > T)
//	{
//		cout << -1 << endl;
//	}
//	int min = *min_element(H.begin(), H.end());
//	
//	bool flag = check(min, T, M, H);
//	while (!flag)
//	{
//		min += 1;
//		flag = check(min, T, M, H);
//	}
//	cout << min << endl;
//	return 0;
//}
//

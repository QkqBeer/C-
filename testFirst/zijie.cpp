//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int x;
//	vector < vector <int> > in;
//	cin >> x;
//	for (int i = 0; i < x; i++)
//	{
//		vector <int> t;
//		in.push_back(t);
//		for (int j = 0; j < x; j++)
//		{
//			int temp;
//			cin >> temp;
//			in[i].push_back(temp);
//		}
//	}
//
//	vector<vector<int>> re;
//	for (int i = 0; i < x; i++)
//	{
//		bool flag = false;
//		for (int j = 0; j < re.size(); j++)
//		{
//			for (int k = 0; k < re[j].size(); k++)
//			{
//				if (i == re[j][k])
//				{
//					flag = true;
//				}
//			}
//			if (flag)
//			{
//				for (int z = 0; z < x; z++)
//				{
//					if (in[i][z] != 0)
//					{
//						re[j].push_back(z);
//					}
//				}
//				break;
//			}
//		}
//		if (!flag)
//		{
//			vector<int> t;
//			t.push_back(i);
//			for (int y = 0; y < x; y++)
//			{
//				if (in[i][y] != 0)
//				{
//					t.push_back(y);
//				}
//			}
//			re.push_back(t);
//		}
//
//	}
//	cout << re.size() << endl;
//	cout << " mmm" << endl;
//	for (int i = 0; i < re.size(); i++)
//	{
//		for (int j = 0; j < re[i].size(); j++)
//		{
//			cout << re[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//
//}


//#include<iostream>
//#include<vector>
//
//using namespace std;
//int main()
//{
//	int x;
//	cin >> x;
//	vector<vector<int>> in;
//	for (int i = 0; i < 4; i++)
//	{
//		vector<int> r;
//		for (int j = 0; j < 4; j++)
//		{
//			int tmp;
//			cin >> tmp;
//			r.push_back(tmp);
//		}
//		in.push_back(r);
//	}
//	if (x == 1)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			for (int i = 0; i < 4; i++)
//			{
//				if (in[i][j] != 0)
//				{
//					int tmp_i = i;
//					while (in[++i][j] == 0)
//					{
//						;
//					}
//					if (i < 4 && in[tmp_i][j] == in[i][j])
//					{
//						in[tmp_i][j] = in[tmp_i][j] * 2;
//						in[i][j] = 0;
//					}
//					i--;
//				}
//			}
//		}
//		for (int j = 0; j < 4; j++)
//		{
//			int index = 0;
//			for (int i = 0; i < 4; i++)
//			{ 
//				if (in[i][j] != 0)
//				{
//					int tmp = in[index][j];
//					in[index][j] = in[i][j];
//					in[i][j] = tmp;
//					index++;
//				}
//			}
//		}
//	}
//	/*if (x == 2)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			for (int i = 3; i > -1; i--)
//			{
//				if (in[i][j] != 0)
//				{
//					int tmp_i = i;
//					while (in[--i][j] == 0)
//					{}
//					if (i >= 0 && in[tmp_i][j] == in[i][j])
//					{
//						in[tmp_i][j] = in[tmp_i][j] * 2;
//						in[i][j] = 0;
//					}
//					i++;
//				}
//			}
//		}
//		for (int j = 0; j < 4; j++)
//		{
//			int index = 3;
//			for (int i = 3; i >= 0; i--)
//			{
//				if (in[i][j] != 0)
//				{
//					int tmp = in[index][j];
//					in[index][j] = in[i][j];
//					in[i][j] = tmp;
//					index--;
//				}
//			}
//		}
//	}*/
//	if (x == 3)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				if (in[i][j] != 0)
//				{
//					int tmp_j = j;
//					while (in[i][++j] == 0)
//					{ }
//					if (j < 4 && in[i][tmp_j] == in[i][j])
//					{
//						in[i][tmp_j] = in[i][tmp_j];
//						in[i][j] = 0;
//					}
//					j--;
//				}
//			}
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			int index = 0;
//			for (int j = 0; j < 4; j++)
//			{
//				if (in[i][j] != 0)
//				{
//					int tmp = in[i][index];
//					in[i][index] = in[i][j];
//					in[i][j] = tmp;
//					index++;
//				}
//			}
//		}
//	}
//	if (x == 4)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = 3; j >= 0; j--)
//			{
//				if (in[i][j] != 0)
//				{
//					int tmp_j = j;
//					while (in[i][--j] == 0)
//					{
//					}
//					if (j >= 0 && in[i][tmp_j] == in[i][j])
//					{
//						in[i][tmp_j] = in[i][tmp_j] * 2;
//						in[i][j] = 0;
//					}
//					j++;
//				}
//			}
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			int index = 3;
//			for (int j = 3; j >= 0; j--)
//			{
//				if (in[i][j] != 0)
//				{
//					int tmp = in[i][j];
//					in[i][index] = in[i][j];
//					in[i][j] = tmp;
//					index--;
//				}
//			}
//		}
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cout << in[i][j];
//			if (j != 3)
//			{
//				cout << " ";
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

#include<iostream>
#include<vector>

using namespace std;
int W(int x)
{
	if (x == 4)
	{
		return 2;
	}
	if (x < 4)
	{
		return 1;
	}
	return x * W(x - 2) / 2;
}
int mainzijie()
{
	int x;
	cin >> x;
	cout << W(x);
	return 0;
}
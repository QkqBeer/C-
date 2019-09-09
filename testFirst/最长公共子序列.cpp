#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int LCS(string s1, string s2)
{
	int size1 = s1.size();
	int size2 = s2.size();
	vector<vector<int>> res(size1 + 1, vector<int>(size2 + 1));
	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				res[i][j] = res[i - 1][j - 1] + 1;
			}
			else
			{
				res[i][j] = max(res[i - 1][j], res[i][j - 1]);
			}
			cout << res[i][j] << "  ";
		}
		cout << endl;
	}
	
	return 0;
}

int mainLCS()
{
	LCS("helloert", "hot");
	return 0;
}
#include <iostream>
#include<vector>
#include <string>
using namespace std;
string change(int n)
{
	string s = "";
	while (n)
	{
		s += to_string(n % 2);
		n /= 2;
	}
	return s;
}
string nixu(string s)
{
	string a = "";
	for (int i = s.size() - 1; i >= 0; i--)
	{
		a += s[i];
	}
	return a;
}
int mainWangyiFirst()
{
	int num;
	cin >> num;
	vector<int> data;
	for (int i = 0; i < num; i++)
	{
		int tmp;
		cin >> tmp;
		data.push_back(tmp);
	}
	for (int i = 0; i < num; i++)
	{
		string s = change(data[i]);
		if (s == nixu(s))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}




#include <unordered_map>
#include <unordered_set>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;

int root(unordered_map<int, vector<int>> hash)
{
	unordered_set<int> s;
	for (auto it = hash.begin(); it != hash.end(); it++)
	{
		vector<int> tmp = it->second;
		for (int i = 1; i < tmp.size(); i++)
		{
			if (tmp[i] != -1)
			{
				s.insert(tmp[i]);
			}
		}
	}
	int z = hash.size();
	for (int j = 0; j < z; j++)
	{
		if (s.find(j) == s.end())
		{
			return j;
		}
	}
}
bool istrue(unordered_map<int, vector<int>> hash)
{
	int r = root(hash);
	queue<pair<int, int>> d;
	vector<pair<int,int>> tmp;
	d.push(pair<int, int>(r, 0));
	int flag = 0;
	while (!d.empty())
	{
		auto it = d.front();
		d.pop();
		tmp.push_back(it);
		int key = it.first;
		int level = it.second;
		vector<int> fi = hash.find(key)->second;
		for (int i = 1; i < fi.size(); i++)
		{
			if (fi[i] != -1)
			{
				d.push(pair<int, int>(fi[i], level + 1));
			}
		}
	}
	
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << tmp[i].first << "  " << tmp[i].second << endl;
	}
	
	vector<vector<int>> res(tmp.back().second + 1);
	
	for (int i = 0; i < tmp.size(); i++)
	{
		auto it = tmp[i];
		int node = it.first;
		int level = it.second;
		res[level].push_back(node);
	}
	
	cout << "´òÓ¡²ã´Î±éÀú" << endl;
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	bool f = true;
	int before = 0;
	int after = 0;
	for (int i = 0; i < res[0].size(); i++)
	{
		before += hash.find(res[0][i])->second[0];
	}

	for (int i = 1; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			after += hash.find(res[i][j])->second[0];
		}
		if (after > before)
		{
			before = after;
			after = 0;
		}
		else
		{
			f = false;
			break;
		}
	}
	return f;
}
int mainWangyiSecond()
{
	int time;
	vector<string> res;
	cin >> time;
	for (int i = 0; i < time; i++)
	{
		int hang;
		cin >> hang;
		unordered_map<int, vector<int>> hash;
		for (int j = 0; j < hang; j++)
		{
			vector<int> tmp;
			int a, b, c;
			cin >> a >> b >> c;
			tmp.push_back(a);
			tmp.push_back(b);
			tmp.push_back(c);
			hash.insert(std::pair<int, vector<int>>(j, tmp));
		}
		if (istrue(hash))
		{
			res.push_back("YES");
		}
		else
		{
			res.push_back("NO");
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}

























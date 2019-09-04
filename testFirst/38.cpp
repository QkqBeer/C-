#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
	string countAndSay(int n)
	{
		string s = "1";
		for (int i = 1; i < n; i++)
		{
			string newString = "";
			int j = 1;
			int count = 1;
			char t = s[0];
			while (j < s.size())
			{
				if (t == s[j])
				{
					count += 1;
					j += 1;
				}
				else
				{
					newString += (to_string(count) + t);
					t = s[j];
					count = 1;
					j += 1;
				}
			}
			newString += (to_string(count) + t);
			s = newString;
		}
		return s;
	}
};
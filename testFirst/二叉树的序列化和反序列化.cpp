#include <iostream>
#include <string>
#include <stack>
using namespace std;


//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		if (root == NULL)
		{
			return "";
		}
		return to_string(root->val) + "[" + serialize(root->left) + "," + serialize(root->right) + "]";
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		stack<TreeNode *> s;
		TreeNode* root = NULL;
		string val;
		for (int i = 0; i < data.size(); i++)
		{
			char t = data[i];
			if ((t >= '0' && t <= '9') || t == '-')
			{
				val += t;
			}
			else
			{
				if (i >= 1 && data[i - 1] != ']')
				{
					TreeNode* node = NULL;
					if (!val.empty())
					{
						node = new TreeNode(stoi(val));
					}
					if (root == NULL)
					{
						root = node;
					}
					s.push(node);
					val.clear();
				}
				if (t == ',' || t == ']')
				{
					TreeNode* node = s.top();
					s.pop();
					if (!s.empty())
					{
						TreeNode* pre_node = s.top();
						if (t == ',')
						{
							pre_node->left = node;
						}
						else
						{
							pre_node->right = node;
						}
					}
				}
			}
		}
		return root;
	}
};
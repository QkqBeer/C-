
#include<iostream>
#include<vector>
using namespace std;
struct treeNode {
	int num;
	int hight;
	treeNode* left;
	treeNode* right;
};

class BalanceTree
{
public:
	BalanceTree();
	BalanceTree(vector<int> nums);
	~BalanceTree();
	treeNode* buildTree(int start, int end, int hight);
	
public:
	vector<int> nums;
};

BalanceTree::BalanceTree()
{

}
BalanceTree::BalanceTree(vector<int> nums)
{
	this->nums = nums;
}

BalanceTree::~BalanceTree()
{
}

treeNode* BalanceTree::buildTree(int start, int end, int hight)
{
	if (start > end)
	{
		return NULL;
	}
	else
	{
		int mid = (start + end) / 2;
		treeNode * node = (treeNode*)malloc(sizeof(treeNode));
		node->num = nums[mid];
		node->hight = hight;
		node->left = buildTree(start, mid - 1, hight + 1);
		node->right = buildTree(mid + 1, end, hight + 1);
		return node;
	}
}


int mainpinghang()
{
	vector<int> tmp = { 1,2,3,4,5,6,7,8 };
	BalanceTree a(tmp);
	treeNode *b = a.buildTree(0, a.nums.size() - 1, 1);
	//cout << b->right->right->right->num << endl;
	return 0;
}





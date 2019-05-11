#include <iostream>
using namespace std;
#include "vector"
#include <algorithm> 
#include "functional"


class IsGreat
{
public:
	IsGreat(int num)
	{
		this->i_num = num;
	}
	bool operator()(const int num)
	{
		if (i_num > num)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

private:
	int i_num;
};


int main22()
{
	vector<int> v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i + 1);
	}

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		cout << *it << "   ";
	}
	cout << endl;
	//使用自己写的函数对象
	int num = count_if(v1.begin(), v1.end(), IsGreat(3));
	cout << num << endl;

	//使用预定义的函数对象
	//greater 的仿函数
	/*template <class _Ty = void>
	struct greater { // functor for operator>
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty first_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty second_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const { // apply operator> to operands
			return _Left > _Right;
		}
	};*/

	//通过预定义的函数对象，求大于2的个数
	//greater<int>()有两个参数 左参数来自容器的元素， 右元素固定成2（通过bind2nd）
	int num1 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
	cout << num1 << endl;

	//奇数的个数
	int num2 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << num2 << endl;

	//偶数的个数
	int num3 = count_if(v1.begin(), v1.end(), not1( bind2nd(modulus<int>(), 2)));
	cout << num3 << endl;
	return 0;
}
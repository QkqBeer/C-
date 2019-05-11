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
	//ʹ���Լ�д�ĺ�������
	int num = count_if(v1.begin(), v1.end(), IsGreat(3));
	cout << num << endl;

	//ʹ��Ԥ����ĺ�������
	//greater �ķº���
	/*template <class _Ty = void>
	struct greater { // functor for operator>
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty first_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty second_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const { // apply operator> to operands
			return _Left > _Right;
		}
	};*/

	//ͨ��Ԥ����ĺ������������2�ĸ���
	//greater<int>()���������� ���������������Ԫ�أ� ��Ԫ�ع̶���2��ͨ��bind2nd��
	int num1 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
	cout << num1 << endl;

	//�����ĸ���
	int num2 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << num2 << endl;

	//ż���ĸ���
	int num3 = count_if(v1.begin(), v1.end(), not1( bind2nd(modulus<int>(), 2)));
	cout << num3 << endl;
	return 0;
}
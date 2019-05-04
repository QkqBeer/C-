#include <iostream>
using namespace std;

template <typename T1, typename T2>
void mySort(T1* myArray, T2 size)
{
	T2 i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (myArray[i] > myArray[j])
			{
				T1 tmp = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}
//如果定义了类型，就必须在函数中使用
template <typename T1, typename T2>
void myPrint(T1* myArray, T2 size)
{
	T2 i, j;
	for (i = 0; i < size; i++)
	{
		cout << myArray[i] << "  ";
	}
}
int main2()
{
	int myArray[] = { 2, 5, 3, 7, 9, 1, 0, 10 };
	int* p = myArray;
	int size = sizeof(myArray) / sizeof(myArray[0]);
	mySort(p, size);
	myPrint(p, size);
	return 0;
}
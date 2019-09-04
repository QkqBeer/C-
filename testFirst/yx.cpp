#include<iostream>
using namespace std;

void Gauss()
{
	int h_size;
	float siz, sigma;
	int i, j;
	
	cin >> h_size >> sigma;
	siz = (h_size - 1) / 2;
	float** a, **b;
	a = new float* [h_size];
	for (int i = 0; i < h_size; i++)   a[i] = new float[h_size];
	b = new float* [h_size];
	for (i = 0; i < h_size; i++)   b[i] = new float[h_size];
	for (i = 0; i < h_size; i++)
	{
		for (j = 0; j < h_size; j++)
		{
			a[i][j] = -siz + j;
		}
	}
	
	for (i = 0; i < h_size; i++)
	{
		for (j = 0; j < h_size; j++)
		{
			b[i][j] = a[j][i];
		}
	}
	float h_sum = 0;
	for (i = 0; i < h_size; i++)
	{
		for (j = 0; j < h_size; j++)
		{
			a[i][j] = a[i][j] * a[i][j];
			b[i][j] = b[i][j] * b[i][j];
			a[i][j] = -(a[i][j] + b[i][j]) / (2 * sigma * sigma);
			a[i][j] = exp(a[i][j]);
			if (a[i][j] < 0.0001) a[i][j] = 0;
			h_sum = h_sum + a[i][j];
		}
	}
	for (i = 0; i < h_size; i++)
	{
		for (j = 0; j < h_size; j++)
		{
			a[i][j] = a[i][j] / h_sum;
		}
	}
	for (i = 0; i < h_size; i++)
	{
		for (j = 0; j < h_size; j++)
		{
			if (j < h_size - 1)
			{
				cout << a[i][j] << " ";
			}
			else
			{
				cout << a[i][j];
			}	
		}
		cout << endl;
	}
}


int mainyx()
{
	Gauss();
	return 0;
}
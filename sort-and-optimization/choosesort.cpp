#include "choosesort.h" 
/*
选择排序
*/
void ChooseSort(int a[], int n)
{
	assert(NULL!=a && n>1);
	for (int i = 0; i < n-2; i++)
	{
		for (int j = i+1; j < n-1; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

/*
选择排序，每次找到最大和最小
*/
void ChooseSort1(int a[], int n)
{
	assert(NULL != a && n>1);
	int min = a[0], max = a[0];
	int minPos =0, maxPos = 0;
	int i, j;
	for ( i = 0; i < n-i-1; i++)
	{
		min = a[i];
		max = a[i];
		for ( j = i; j < n-i-1; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				minPos = j;
			}
			if (max < a[j])
			{
				max = a[j];
				maxPos = j;
			}
		}
		swap(a[i], a[minPos]);
		swap(a[j], a[maxPos]);
	}
}


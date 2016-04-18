
/*
简单冒泡排序
*/
void Buble(int a[], int n)
{
	assert(NULL != a && n > 1);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
			}
		}

	}
}

/*
* 改进，记录最后一次交换的位置，则这个位置之后的是有序的，无交换则全有序
*/
void Buble1(int a[], int n)
{
	assert(NULL != a && n > 1);
	int pos = 0;
	for (int i = n-1; i > 0; )
	{
		pos = 0;
		for (int j = 0; j < i ; j++)
		{
			if (a[j] > a[j + 1])
			{
				pos = j;
				swap(a[j], a[j + 1]);
			}
		}
		i = pos;
	}
}

/*
	首尾同时进行冒泡排序。
*/
void Buble2(int a[], int n)
{
	assert(NULL != a && n > 1);
	int high = n - 1;
	int low = 0;
	int i, j;
	while (low < high)
	{
		//找到最大的。
		for (j = low; j < high; j++)
		{
			if (a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
			}
		}
		high--;
		//找到最小的
		for ( i = high; i > low; i--)
		{
			if (a[i] < a[i-1])
			{
				swap(a[i], a[i-1]);
			}
		}
		low++;
	}
}


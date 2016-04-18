
/*
*插入排序
*/
void InsertSort(int a[], int n)
{
	assert(NULL != a && n>1);
	int i, j,temp;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && temp < a[j]; j--)
		{
			a[j+1] = a[j];
		}
		a[++j] = temp;
	}
}

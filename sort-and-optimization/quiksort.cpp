
#if 0

inline void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
#else
//
inline void swap(int& a, int& b)
{
	if (a != b)
	{
		a = a^b;
		b = a^b;
		a = a^b;
	}
}
#endif


/*
快速排序
*/
void QuikSort(int a[], int n)
{
	assert(NULL != a );
	int i = 0, j = n - 1;
	int temp = a[0];
	if (n <= 1)
	{
		return;
	}
	while (i < j)
	{
		while (i<j && temp <= a[j])
		{
			j--;
		}
		a[i] = a[j];
		while (i<j && temp >= a[i])
		{
			i++;
		}
		a[j] = a[i];
	}
	a[i] = temp;
	
	QuikSort(a, i );
	QuikSort(a + i + 1, n - i -1 );
}

/*
*改进快速排序
*优化如下：
*	1.关键码的选取，如果子区间大小在7-40个元素之间，采用两端和中间取中位数，
* 如果元素个数大于40个，则选取左端三个数的中位数，中间三个数的中位数，右边三个数的中位数，三个中位数的中位数。
*	
*	2.子区间小于7个元素，则可以直接用插入排序，插入排序对于基本有序的少量的数组排序时间复杂度接近于O（n）。
*	
*	3.对于与关键码相同的元素，集中到中间，下次不再继续参与递归。但是一趟排序还没有完成之前，不好确定中间位置。。。
* 可以先移动到两端，最后再移动到中间
*/
int GetMidNumPos(int arr[],int a, int b,int c)
{
	return (arr[a] < arr[b]) ? \
		((arr[b] < arr[c]) ? \
			b : ((arr[a] < arr[c]) ? c : a)) : \
		((arr[a] < arr[c]) ? \
			a : ((arr[b] < arr[c]) ? c : b));
}

void QuikSort1(int a[], int n)
{
	assert(NULL != a);

	if (n <= 1)
	{
		return;
	}
	int i, j, temp;
	if (n <= 7)
	{
		//个数小于7则插排
		for ( i = 1; i < n; i++)
		{
			temp = a[i];
			for ( j = i - 1; j >= 0 && temp < a[j]; j--)
			{
				a[j + 1] = a[j];
			}
			a[++j] = temp;
		}
		return;
	}
	else if ( n <= 40 )
	{
		//三数取中
		int mid = GetMidNumPos(a, 0, n >> 1, n - 1);
		temp = a[mid];
	}
	else
	{
		//9数取中
		int mid, mid1, mid2, mid3;
		mid1 = GetMidNumPos(a, 0, 1, 2);
		mid2 = GetMidNumPos(a, n >> 1 - 1, n >> 1, n >> 1 + 1);
		mid3 = GetMidNumPos(a, n - 3, n - 2, n-1);
		mid = GetMidNumPos(a, mid1,  mid2,  mid3);
		temp = a[mid];
	}

	int h, t;
	h =	i = 0;
	t = j = n - 1;

	while (true)
	{
		while (i<=j && temp >= a[i])
		{
			//先把与枢轴相同的元素移到左边
			if (temp == a[i])
			{
				swap(a[i], a[h]);
				h++;
			}
			i++;
		}
		while (i<=j && temp <= a[j])
		{
			//先把与枢轴相同的元素移到右边
			if (temp == a[j])
			{
				swap(a[j], a[t]);
				t--;
			}
			j--;
		}	
		if (i>j)
		{
			break;
		}
		swap(a[i], a[j]);
		i++;
		j--;
	}
	//把移动到两边与枢轴相同的数移动到中间。下次不再递归
	for (int k = 0; k < h; k++)
	{
		i--;
		swap(a[k], a[i]);
	}
	for (int k = n-1; k >t ; k--)
	{
		j++;
		swap(a[k], a[j]);
	}

	QuikSort1(a, i);
	QuikSort1(a + j + 1 , n - j - 1 );
}
/*
*	1.在上一种优化的基础上，一趟排序分出来的前面区间用循环，第二区间依然是递归
*	2.子区间开线程去做排序的话。。有好有坏。。。不做了。。
*/
void QuikSort2(int arr[], int len)
{
	assert(NULL != arr);
	int n = len;
	int i, j, ti, tj, steps, temp;
	int* a = arr;
	int h, t, k;
	int mid, mid1, mid2, mid3;
	while (len > 1)
	{
		n = len;
		if (n <= 8)
		{
			for (i = 1; i < n; i++)
			{
				temp = a[i];
				for (j = i - 1; j >= 0 && temp < a[j]; j--)
				{
					a[j + 1] = a[j];
				}
				a[++j] = temp;
			}
			return;
		}
		else if (n <= 40)
		{
			mid = GetMidNumPos(a, 0, n >> 1, n - 1);
			temp = a[mid];
		}
		else
		{
			//数组分成三个区间，三个区间的中位数的中位数作为枢轴
			int num1 = n >> 2;
			int num2 = n >> 1;
			mid1 = GetMidNumPos(a, 0, num1 >> 1, num1 - 1);
			mid2 = GetMidNumPos(a, num1, num2, num1 + num2);
			mid3 = GetMidNumPos(a, num1 + num2 + 1, num1 + num2 + num1>>1 + 1, n - 1);
			mid  = GetMidNumPos(a, mid1, mid2, mid3);
			temp = a[mid];
		}

		h = i = 0;
		t = j = n - 1;

		while (true)
		{
			while (i <= j && temp >= a[i])
			{
				if (temp == a[i])
				{
					swap(a[i], a[h]);
					h++;
				}
				i++;
			}
			while (i <= j && temp <= a[j])
			{
				if (temp == a[j])
				{
					swap(a[j], a[t]);
					t--;
				}
				j--;
			}
			if (i > j)
			{
				break;
			}
			swap(a[i], a[j]);
			i++;
			j--;
		}

		ti = i;
		//移动次数可以调整
		steps = (h < (ti - h)) ? h : (ti - h);
		for ( k = 0; k < steps; k++)
		{
			--ti;
			swap(a[k], a[ti]);
		}
		len = i - h + 1;

		tj = j;
		steps = (n - 1 - t) < (t - j) ? (n - 1 - t) : (t - j);
		for ( k = 0; k <steps; k++)
		{
			++tj;
			swap(a[n - 1 - k], a[tj]);
		}

		//第一层递归改用循环
		//	QuikSort2(a, i);
		//len = i;
		QuikSort2(a + j + 1, n - j - 1);
	}
}

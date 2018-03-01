#include "heapsort.h"
//下标从0开始，左孩子
static inline int LeftChild(int i)
{
	return (i << 1) + 1;
}
//元素i下沉
void ElemDown(int a[], int i, int n)
{
	int tmp = a[i];
	int child = 0;
	//有左孩子就继续下沉
	for (; (child = LeftChild(i)) < n; i = child)
	{
		//找到孩子中的较大者
		if ((child + 1) < n && a[child] < a[child + 1])
		{
			++child;
		}

		//如果小于孩子中的最大者，就和这个孩子交换，否则不需要再下沉
		if (tmp < a[child])
		{
			a[i] = a[child];
		}
		else
		{
			break;
		}
	}
	a[i] = tmp;
}
void HeapSort(int a[], int n)
{
	//先构建堆
	for (int i = (n >> 1); i >= 0 ; --i)
	{
		ElemDown(a,i,n);
	}

	for (int i = n - 1; i > 0; --i)
	{
		//交换最大的一个到最后
		swap(a[0],a[i]);
		//重新整理堆
		ElemDown(a,0,i);
	}

}
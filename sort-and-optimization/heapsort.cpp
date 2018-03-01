#include "heapsort.h"
//�±��0��ʼ������
static inline int LeftChild(int i)
{
	return (i << 1) + 1;
}
//Ԫ��i�³�
void ElemDown(int a[], int i, int n)
{
	int tmp = a[i];
	int child = 0;
	//�����Ӿͼ����³�
	for (; (child = LeftChild(i)) < n; i = child)
	{
		//�ҵ������еĽϴ���
		if ((child + 1) < n && a[child] < a[child + 1])
		{
			++child;
		}

		//���С�ں����е�����ߣ��ͺ�������ӽ�����������Ҫ���³�
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
	//�ȹ�����
	for (int i = (n >> 1); i >= 0 ; --i)
	{
		ElemDown(a,i,n);
	}

	for (int i = n - 1; i > 0; --i)
	{
		//��������һ�������
		swap(a[0],a[i]);
		//���������
		ElemDown(a,0,i);
	}

}
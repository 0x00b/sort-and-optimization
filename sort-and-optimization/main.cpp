#include "bublesort.h"
#include "choosesort.h"
#include "insertsort.h"
#include "quiksort.h"

int Now()
{
#if defined(_WIN)
	return GetTickCount();
#else
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv, &tz);
	return tv.tv_usec;
#endif
}
/*
*获取一段代码（func）执行的时间
*/
#define GetTm(func, t)				\
do{									\
	int t1, t2;					\
	t1 = Now();			\
	func;							\
	t2 = Now();				\
	t = (t2 - t1);					\
}while(0)

void Print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
}
/*
*产生随机数组
*/

void MessArr(int a[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		if (0 && ((i % 3) == 0))
		{
			a[i] = a[rand() % n];
		}
		else
		{
			a[i] = rand();
		}
	}
}

void GetEqCnt(int a[], int n)
{
	int sum = 0;
	int* pa = new int[n];
	memset(pa, 0x00, n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		pa[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (pa[i] > 1)
		{
			sum += pa[i];
		}
	}
	free(pa);
	printf("\nsum:%d\n",sum);
}

#define len		20000

int comp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b ;
}
int main()
{
	int a[len] = {};
	int t = 0;
	int i = 9, j = 9;
	MessArr(a, len);
//	MkRptArr(a,len);
	//Buble(a,len);
	//Buble1(a,len);	//
	//Buble2(a,len);	//事实证明，三种都差不多。。。没啥提高，不应该啊，

	//ChooseSort(a,len);
	//ChooseSort1(a,len); //事实证明效率提升很多

	//QuikSort(a,len);

	//InsertSort(a,len);
	 
#if 1
//	Print(a,len);
//	GetEqCnt(a,len);
	int t1 = 0, t2 = 0, t3 = 0;
	for (int i = 0; i < 150; i++)
	{
	/*	printf("\n1\n");
		t = 0;
		MessArr(a,len);
		GetTm(QuikSort(a,len), t); //printf("qtime:%d \n", t);	
		t1 += t;
		*/

//		printf("\n2\n");
		t = 0;
		MessArr(a, len);
		GetTm(QuikSort1(a, len), t);
		t2 += t;

//		printf("\n3\n");
		t = 0;
		MessArr(a, len);
		GetTm(QuikSort2(a, len), t);// printf("time:%d \n", t); 
		t3 += t;
//		printf("\n4\n");
	}
	printf("\nt1=%d,t2=%d,t3=%d\n",t1,t2,t3);
//	GetTm(qsort(a, len, 4, comp), t); printf("time:%d\n", t);	

//	printf("\n排序后：\n");	Print(pa);
#else
	Print(a, len);
	//MkRptArr(a,len);// Print(pa);
	//QuikSort(a,len);
	//printf("\n排序后：\n"); Print(a,len);
	//MessArr(a,len);
	//MkRptArr(a,len); printf("\n2222：\n"); Print(a,len);
	QuikSort1(a, len);
	//qsort(a, len, 4, comp);
	printf("\n排序后：\n");	Print(a, len);
#endif

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

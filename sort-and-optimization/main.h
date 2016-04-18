#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>


#if defined(_WIN32) || defined(_WIN64)
#define _WIN
#endif

#if defined(_WIN)
#include <windows.h>
#endif

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

#endif //_MAIN_H_
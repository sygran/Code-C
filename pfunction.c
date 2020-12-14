#include <stdio.h>
//! Находит сумму элементов массива
double dbl_sum(const double *a, int size)
{
	return size > 0 ? *a + dbl_sum(a + 1, size - 1) : 0;

	//! an easier option
	/* 	if (size > 0)
	{
		return *a + dbl_sum(a + 1, size - 1);
	}
	else
	{
		return 0;
	} */
}
//! Принимает на вход массив элементов типа double в виде первого элемента и целого числа, обозначающего длину массива, соответственно возвращает число типа double
double dbl_min(const double *a, int size)
{
	double d;
	if (size == 1)
	{
		return *a;
	}
	d = dbl_min(a + 1, size - 1);
	return *a < d ? *a : d;
}

//! Среднее арифметическое
double dbl_average(const double *a, int size)
{
	return dbl_sum(a, size) / (double)size; // (double)size приведение к типу
}
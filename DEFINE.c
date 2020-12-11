#include <stdio.h>
#include <stdlib.h>

// Суммируем массив из int'ов
int int_array_sum(const int *a, int n)
{
	int s = 0;
	while (n > 0)
	{
		s += *a;
		a++;
		n--;
	}
	return s;
}

// с помощью макрсов можно сделать лучше
#define MAKE_ARRAY_SUM_FUNCTION(FUNNAME, TYPE) \
	TYPE FUNNAME(const TYPE *a, int n)         \
	{                                          \
		TYPE s = 0;                            \
		while (n > 0)                          \
		{                                      \
			s += *a;                           \
			a++;                               \
			n--;                               \
		}                                      \
		return s;                              \
	}
// Макровызовы для суммирования массивов
MAKE_ARRAY_SUM_FUNCTION(int_array_sum, int)
MAKE_ARRAY_SUM_FUNCTION(double_array_sum, double)
MAKE_ARRAY_SUM_FUNCTION(long_array_sum, long)

#define VAP_PRINT(x) printf("%s = %d\n", #x, x)
//Лучше так
#define VAR_PRINT1(x) printf(#x " = %d\n", x)
// Используем вызов:
int abrakadabra = 13;
VAR_PRINT(abrakadabra);
// Макрос раскрывает в выражение
printf("%s = %d\n", "abrakadabra", abrakadabra);
// Напечатает так
abrakadabra = 13
#include <stdarg.h>
#include <stdio.h>

void print_times(const char *str, ...)
{
	va_list vl;
	const char *p;
	va_start(vl, str);
	for (p = str; p; p = va_arg(vl, const char *))
	{
		int n, i;
		n = va_arg(vl, int);
		for (i = 0; i < n; i++)
		{
			printf("%s ", p);
		}
		printf("\n");
	}
	va_end(vl);
}

int main()
{
	print_times("once", 1, "twice", 2, "seven times", 7, NULL);
}
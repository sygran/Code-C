#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
	int m[] = {123, 12, 312, 5346, 73, 63, 267, 8, 95, 2};
	int i;
	for (i = 0; i < sizeof(m) / sizeof(*m); i++)
	{
		printf("[%d] = %d\n", i, m[i]);
	}
	getch();
}

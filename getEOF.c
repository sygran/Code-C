#include <stdio.h>
//! читает текст, на каждую прочитанную сточку печатает OK!
int main()
{
	int c;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			printf("OK\n");
		}
	}
	return 0;
}

//! Тоже самое только вместо OK пишит количество прочитанных символов
int main()
{
	int c, n;
	n = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			printf("%d\n", n);
			n = 0;
		}
		else
		{
			n++;
		}
	}
	return 0;
}
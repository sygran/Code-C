#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	for (i = 0; i < argc; i++)
		printf("[%s]\n", argv[i]);
	return 0;
}

int main(int argc, char **argv)
{
	argv++;
	while (*argv)
	{
		printf("[%s]\n", *argv);
		argv++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	while (*++argv)
		printf("[%s]\n", *argv);
	return 0;
}

int main(int argc, char **argv)
{

	printf("My name is %s\n", argv[0]);
	return 0;
}
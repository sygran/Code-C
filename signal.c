#include <stdio.h>
#include <signal.h>
int n = 0;
void handler(int s)
{
	n++;
	printf("Press it again, I like it\n");
}
int main()
{
	signal(SIGINT, handler);
	while (n < 25)
		;
	return 0;
}

// bad program, second better in pressagain.c
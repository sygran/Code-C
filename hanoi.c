#include <stdio.h>
#include <stdlib.h> //! for atoi
#include <conio.h>

static void solve(int source, int target, int interm, int n)
{
	if (n == 0)
	{
		return;
	}
	solve(source, interm, target, n - 1);
	printf("%d: %d -> %d\n", n, source, target);
	solve(interm, target, source, n - 1);
}

int main(int argc, char **argv)
{
	int n;
	scanf(n);
	solve(1, 3, 2, n);
	getch();
}
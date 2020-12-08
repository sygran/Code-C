#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

//! в файл запишем значение синуса и косинуса для углов от 0 до 359
int main()
{
	FILE *f;
	int grad;
	f = fopen("sincos.txt", "w");
	if (!f)
	{
		perror("sincos.txt");
		return 1;
	}
	for (grad = 0; grad < 360; grad++)
	{
		double rads = (double)grad * M_PI / 180.0;
		double s = sin(rads);
		double c = cos(rads);
		fprintf(f, "%03d % 7.5f % 7.5f\n", grad, s, c);
	}
	fclose(f);

	return 0;
}
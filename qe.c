#include <math.h>
#include <stdio.h>
#include <conio.h>
// !Формула дискриминанта вычисяется по формуле D = b*b - 4*a*c
double discrim(double a, double b, double c)
{
    return b * b - 4 * a * c;
}
int main()
{
    printf("Never say 'never'\n");
    printf("This "
           "is"
           " a string "
           "whi"
           "ch is "
           "long");

    double p, q, r, d;
    int n;
    n = scanf("%lf %lf %lf", &p, &q, &r);
    if (n != 3)
    {
        printf("Error: wring input.\n");
        return 1;
    }
    if (p == 0)
    {
        printf("Error: Not a quadratic equation!\n");
        return 2;
    }
    d = discrim(p, q, r);
    if (d < 0)
    {
        printf("No roots\n");
        return 0;
    }
    d = sqrt(d);
    printf("%.5f %.5f\n", (-q - d) / (2 * p), (-q + d) / (2 * p));
    return 0;
}
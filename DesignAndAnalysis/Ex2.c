#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

double square(double x)
{
    return x * x;
}

double func(double x)
{
    return sqrt(1.0 - square(x));
}

double Darts(int n)
{
    int k = 0;
    int i;
    srand(time(NULL));
    for(i = 0; i < n; ++i)
    {
	double x = (double)rand() / RAND_MAX;
	double y = (double)rand() / RAND_MAX;
	double f = func(x);
	if(y < f)
	    ++k;
    }
    return (double)k / n;
}

int main(int argc, char **argv)
{
    int count = 0;
    printf("please input count: ");
    scanf("%d", &count);
    int i;
    for(i = 0; i < count; ++i)
    {
	int n;
	scanf("%d", &n);
	printf("%lf\n", 4 * Darts(n));
    }
    return 0;
}

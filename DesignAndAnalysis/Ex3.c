#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double square(double x)
{
    return x * x;
}


double areaFunc(double a, double b, double c, double d, int n, double (*f)(double x))
{
    double S = (b - a) * (d - c);
    srand(time(NULL));   
    
    int i;
    int k = 0;
    for(i = 0; i < n; ++i)
    {
	double x = (rand() * (b - a) / RAND_MAX) + a;
	double y = (rand() * (d - c) / RAND_MAX) + c;
	if(y <= f(x))
	    ++k;
    }

    return S * k / n;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    int count = 0;
    printf("please input count : ");
    scanf("%d", &count);
    for(int i = 0; i < count; ++i)
    {
	int n;
	scanf("%d", &n);
	printf("%lf\n", areaFunc(0, 1, 0, 1, n, square));
    }
    return 0;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double square(double x)
{
    return x * x;
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
	//double y = x;
	if(square(x) + square(y) <= 1)
	    ++k;
    }
    return 4.0 * k / n;
}

int main(int argc, char **argv)
{
    int count = 0;
    long num;
    scanf("%d", &count);
    int i;
    for(i = 0; i < count; ++i)
    {
	scanf("%ld", &num);
    	printf("%lf\n", Darts(num));
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <map>

using namespace std;

long SetCount(long x)
{
	int k = 0;
	double Pi = 3.1415;
	map<long, int> mySet;
	srand(time(NULL));
	while(1)
	{
		long temp = rand() * 1.0 / RAND_MAX * x;
		if(mySet[temp] == 0)
			++mySet[temp];
		else
			break;
		++k;
	}
	return 2 * k * k / Pi;
}

int main(int argc, char **argv)
{
	int count;
	printf("please input count : ");
	scanf("%d", &count);
	int i;
	for(i = 0; i < count; ++i)
	{
		long n;
		scanf("%ld", &n);
		printf("%ld\n", SetCount(n));
	}
	return 0;
}

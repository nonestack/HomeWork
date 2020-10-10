#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1000000

int arr[MAXN] = {0};
int ptr[MAXN] = {0};
int head = 0;

int Search(int x, int index)
{
	while(x > arr[index])
	{
		index = ptr[index];
	}
	return index;
}

int A(int x)
{
	return Search(x, head);
}

int D(int x)
{
	srand(time(NULL));
	int index = rand() % MAXN;
	int y = arr[index];

	if(x < y)
		return Search(x, head);
	else if(x > y)
		return Search(x, ptr[index]);
	else
		return index;
}

int B(int x)
{
	int index = head;
	int max = arr[index];
	int border = (int)sqrt(1.0 * MAXN);
	int i;
	for(i = 0; i < border; ++i)
	{
		int y = arr[index];
		if(max < y && y <= x)
		{
			index = i;
			max = y;
		}
	}
	return Search(x, index);
}

int C(int x)
{
	srand(time(NULL));
	int index = head;
	int max = arr[index];
	int border = (int)sqrt(1.0 * MAXN);
	int i;
	for(i = 0; i < border; ++i)
	{
		int r = rand() % MAXN;
		int y = arr[r];
		if(max < y && y <= x)
		{
			max = y;
			index = r;
		}
	}
	return Search(x, index);
}

void init()
{
	FILE *fp = fopen("array.txt", "r");

	int i;
	fscanf(fp, "%d", &head);
	for(i = 0; i < MAXN; ++i)
	{
		fscanf(fp, "%d\t%d", arr + i, ptr + i);
	}
	
	fclose(fp);
}



int main(int argc, char **argv)
{
	init();
	int k = arr[MAXN / 2];
	printf("%d\n", k);

	clock_t startA, startB, startC, startD, endA, endB, endC, endD;

	startA = clock();
	int a = A(k);
	endA = clock();
	int secondA = endA - startA;

	startB = clock();
	int b = B(k);
	endB = clock();
	int secondB = endB - startB;
	
	startC = clock();
	int c = C(k);
	endC = clock();
	int secondC = endC - startC;

	startD = clock();
	int d = D(k);
	endD = clock();
	int secondD = endD - startD;

	printf("timeA = %dms, timeB = %dms, timeC = %dms, timeD = %dms\n", secondA, secondB, secondC, secondD);
	return 0;
}

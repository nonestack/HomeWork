#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>

#define MAXN 1000000

int arr[MAXN] = {0};
int ptr[MAXN] = {0};
int head = 0;
int hashTab[5 * MAXN] = {0};

void init()
{
	srand(time(NULL));
	int i;
	for(i = 0; i < MAXN; ++i)
	{
		int temp = rand() % (5 * MAXN);
		while(hashTab[temp] != 0)
		{
			temp = rand() % (5 * MAXN);
		}
		++hashTab[temp];
		arr[i] = temp;
	}

	int first = 0;
	int pre = 0;
	for(i = 0; i < 5 * MAXN; ++i)
	{
		if(hashTab[i] == 0)
			continue;

		if(first == 0)
		{
			first = 1;
			for(int j = 0; j < MAXN; ++j)
			{
				if(i == arr[j])
				{
					head = j;
					pre = j;
					//printf("%d\t%d\n", arr[j], j); break;
				}
			}
		}
		else
		{
			for(int j = 0; j < MAXN; ++j)
			{
				if(i == arr[j])
				{
					ptr[pre] = j;
					pre = j;
					//printf("%d\t%d\n", arr[j], j);
					break;
				}
			}

		}
	}
	ptr[pre] = -1;
}


int main()
{
	init();
	//for(int pre = head; pre != -1; pre = ptr[pre])
	//{
	//	printf("%d\t%d\n", arr[pre], ptr[pre]);
	//}
	//printf("%d\n", head);
	//for(int i = 0; i < MAXN; ++i)
	//{
	//	printf("%d\t%d\n", arr[i], ptr[i]);
	//}
	FILE *fp = fopen("array.txt", "w+");
	fprintf(fp, "%d\n", head);
	for(int i = 0; i < MAXN; ++i)
	{
		fprintf(fp, "%d\t%d\n", arr[i], ptr[i]);
	}
	fclose(fp);
	return 0;
}

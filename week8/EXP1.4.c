#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[])
{
	int n, num;
	scanf("%d%d", &n, &num);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 3 * n - 2 * i - 2; j++)
		{
			if ((i == 0 || i == n-1) || (j == 0 || j == 3 * n - 2 * i - 3)) {
				printf("%d", (num + i) % 10);
			} else
			{
				printf(" ");
			}
		}
		printf("\n");
		
		
	}
	return 0;
}
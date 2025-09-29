#include <stdio.h>

int main()
{
	int num;

	scanf("%d", &num);
	printf("%d\n", num % 10 * 100 + num / 10 % 10 * 10 + num / 100);
	return 0;
}
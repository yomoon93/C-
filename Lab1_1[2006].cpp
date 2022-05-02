#include "stdio.h"
int main()
{
	int x, y, sum, sub;
	printf("Hello\n");
	printf("enter two integers from a keyboard to add\n");
	scanf_s("%d %d", &x, &y);
	sum = x + y;
	printf("addition result=%d\n", sum);
	getchar();
	printf("Enter Two integers from a keyboard to minus\n");
	scanf_s("%d %d", &x, &y);
	sub = x - y;
	printf("Subtraction = %d", sub);

	getchar();
	return 0;
}
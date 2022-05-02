#include "stdio.h"
int main(void)
{
	char x, y, sum, diff;
	printf("Hello\n");
	printf("Names: Ajay and Kevin, Class: CET 3510 LAB, Date: 8/31/2018\n");
	scanf_s("%d %d", &x, &y);
	__asm
	{
		MOV AL, x;
		MOV BL, y;
		MOV CL, AL;
		ADD CL, BL
		MOV sum, CL
	}
	printf("Addition result= %d\n", sum);
	printf("*************\n");
	getchar();
	printf("Enter Two integers from keybpard to minus\n");
	scanf_s("%d %d", &x, &y);
	_asm
	{
		MOV AL, x;
		MOV BL, y;
		MOV CL, AL;
		SUB CL, BL
		MOV diff, CL
	}
	printf("Subtraction = %d\n", diff);
	getchar();
	getchar();
	return 0;
}


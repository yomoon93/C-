#include "stdio.h"// library for everything to be read in assembly language
int main(void)// no argument needed basically it avoids bc no argument is made
{
	char x, y, sum, diff;
	printf("Hello\n");
	printf("Names: Ajay and Kevin, Class: CET 3510 LAB, Date: 8/31/2018\n");
	scanf_s("%d %d", &x, &y)/* we uuse &d to contain the integer in this case*/
	__asm // the start of the assembly language
	{
		MOV AL, x; /* AL is 8 bits and it s holding whatever the user put into the console*/
		MOV BL, y; //same as the last comment
		MOV CL, AL; // move CL to AL
		ADD CL, BL// add CL and BL
		MOV sum, CL // answer after adding both numbers is CL
	}// ends
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

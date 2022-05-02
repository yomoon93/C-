/************************************************************************************************************
File name: SwapBytes.cpp
Swap bytes in two general registers and examin the functions and contents
Method: Embedding an in-line assembly language module into C program

A. Swap bytes in two general registers of BL, BH
B. Swap bytes in two general registers of AL, AH

printf() is used to display information on the console
scanf_s() is used to recieve the integers from the keyboard
************************************************************************************************************/

#include <stdio.h>     //to use printf()
#include <iostream>       //to use system ("pause") to hold the console

int main(){

	char temp, r1, r2, temp1, temp2;
	short int r;

	char letter[20] = { 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd','E', 'e','F', 'f','G', 'g','H', 'h','I', 'i','J', 'j' };

	for (char i = 0; i < 19; i++) {
		temp1 = letter[i];
		temp2 = letter[i + 1];


			//A. Swap bytes in two registers of BL, B
			_asm
		{
			MOV BL, temp1;
			MOV BH, temp2;
			MOV r1, BL;
			MOV r2, BH;
			MOV r, BX;

		}

		std::cout << "===================================================================" << std::endl;
		std::cout << "Before swapping " << std::endl;
		//to display characters
		printf("BH = %c, BL = %c\n", r2, r1);
		//to display hexadecimal value of each charcter
		printf("BH = 0x%x, BL = 0x%x, BX = 0x%x\n", r2, r1, r);

		//Swap bytes in two registers of BL, BH
		_asm
		{
			MOV temp, BH;
			MOV BH, BL;
			MOV BL, temp;
			MOV r1, BL;
			MOV r2, BH;
			MOV r, BX;
		}
		std::cout << "====================================================================" << std::endl;
		std::cout << "After swapping" << "\n";
		//to display characters
		printf("BH = %c, BL = %c \n ", r2, r1);
		//to display hexadecimal value of each charcter
		printf("BH = 0x%x, BL =0x%x, BX=0x%x\n", r2, r1, r);
		/***********************************************************************************/

	}

	system("pause");
	return 0;




}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

// addition for signed numbers
void addition(short int x, short int y);
// subtraction for signed numbers
void subtraction(short int x, short int y);
// addition for unsigned integers
void un_addition(unsigned short int x, unsigned short int y);
// subtraction for unbsigned numbers
void un_subtraction(unsigned short int x, unsigned short int y);

int main()
{
	// Declare variables here
	char ch, ch1, ch2, ch3;
	signed short r1, r2;
	unsigned short ur1, ur2;
	cout << "Start your calculator Y/N, enter Y(y) or N(n)" << endl;
	cin >> ch;
	ch1 = ch;
	while (ch1 == 'Y' || ch1 == 'y')
	{
	Menu:
		cout << "Menu:\n";
		cout << "1, Signed Integer Arithmetic Operation (16-bit)\n";
		cout << "2, Unsigned Integer Arithmetic Operation (16-bit)\n";
		cout << "3, Exit\n";
		cout << "Menu Options:\n";
		std::cin >> ch;
		ch2 = ch;

	Submenu:
		if (ch2 == '1')
		{
			cout << "Submenu - input your choice\n";
			cout << "a, Input two 16-bit signed number operands for addition and display\n"
				<< "the sum in decimal and hexadecimal format, respectively.\n";

			cout << "b, Input two 16-bit signed number operands for subtraction and display\n"
				<< " the difference in decimal and hexadecimal format, respectively.\n";
			cin >> ch;
			ch3 = ch;
			switch (ch3)
			{
			case 'a':
			 {
				cout << "Input two signed numbers operands in decimal format\n";
				cin >> r1 >> r2;
				addition(r1, r2);
				cout << "============================================================\n";
				break;
			}
			case 'b':
			{
				cout << "Input two signed number operands in decimal format\n";
				cin >> r1 >> r2;
				subtraction(r1, r2);
				cout << "==========================================================\n";
				break;
			}
			default: goto Menu;
			}

		}
		else if (ch2 == '2')
		{
			cout << "Submenu - input your choice\n";
			cout << "a, Input two 16-bit unsigned number operands for addition, and display\n"
				<< " the sum in decimal and hexadecimal format, respectively.\n";

			cout << "b, Input two 16 - bit unsigned number operands for addition, and display\n"
				<< " the difference in decimal and hexadecimal format, respectively.\n";
			cin >> ch;
			ch3 = ch;

			switch (ch3)
			{
			case 'a':
			{
				cout << "Input two unsigned numbers operands in decimal format\n";
				cin >> ur1 >> ur2;
				un_addition(ur1, ur2);
				cout << "============================================================\n";
				break;
			}
			case 'b':
			{
				cout << "Input two unsigned number operands in decimal format\n";
				cin >> ur1 >> ur2;
				un_subtraction(ur1, ur2);
				cout << "==========================================================\n";
				break;
			}
			default: goto Menu;
			}
		}
		else
		{
			goto EndLable;
		}
		cout << "Do you like to continue the arithmetic operations (Y/N)? Enter Y(y) or N(n)" << endl;
		cin >> ch;
		ch1 = ch;
	}

    EndLable:
	cout << "Exit program" << endl;
	system("pause");

	exit(0);
	return(0);
}

// addition for signed short integers
void addition(short int x, short int y)
{
	short int r;
	_asm
	{
		MOV AX, x;
		MOV BX, y;
		ADD AX, BX;
		MOV r, AX;
	}


cout << "The decimal sum of " << dec << x << "and" << dec << y << "is" << dec << r << endl;
cout << "The hexadecimal sum of" << hex << x << "and" << hex << y << "is" << hex << r << endl;

}

// subtraction for signed short integers
void subtraction(short int x, short int y)
{
	short int r;
	_asm
	{
		MOV AX, x;
		MOV BX, y;
		SUB AX, BX;
		MOV r, AX;
	}
	cout << "The decimal subtraction of " << dec << x << "minus" << dec << y << " is" << dec << r << endl;
	cout << "The hexadecimal sum of" << hex << x << "and" << hex << x << "minus" << hex << y << "is"
		<< hex << r << endl;

}

// addition for unsigned short integers
void un_addition(unsigned short int x, unsigned short int y)
{
	unsigned short int r;
	_asm
	{
		MOV AX, x;
		MOV BX, y;
		ADD AX, BX;
		MOV r, AX;
	}


cout << "The decimal sum of " << dec << x << "and" << dec << y << "is" << dec << r << endl;
cout << "The hexadecimal sum of" << hex << x << "and" << hex << y << "is" << hex << r << endl;
}


// subtraction for signed short integers
void un_subtraction(unsigned short int x, unsigned short int y)
{
	unsigned short int r;
	_asm
	{
		MOV AX, x;
		MOV BX, y;
		SUB AX, BX;
		MOV r, AX;
	}
	cout << "The decimal subtraction of " << dec << x << "minus" << dec << y << " is" << dec << r << endl;
	cout << "The hexadecimal sum of" << hex << x << "and" << hex << x << "minus" << hex << y << "is"
		<< hex << r << endl;

}


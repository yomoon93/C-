#include <iostream>
#include <bitset>
using namespace std;

void mainMenu();
void subMenu1();
void And_operation(unsigned short r1, unsigned short r2);
void Or_operation(unsigned short r1, unsigned short r2);
void Xor_operation(unsigned short r1, unsigned short r2);
void Not_operation(unsigned short r1);

void subMenu2();
void And_operation2(unsigned int r1, unsigned int r2);
void Or_operation2(unsigned int r1, unsigned int r2);
void Xor_operation2(unsigned int r1, unsigned int r2);
void Not_operation2(unsigned int r1);

int main() {
	//Declare variables here:
	char ch, ch1, ch2, ch3;
	unsigned short r1, r2;		//A 16-bit word declaration

	cout << "Start the logic operations Y/N, enter Y(y) or N(n): ";
	cin >> ch;
	ch1 = ch;

	mainMenu();
	cout << "Menu Options: ";
	cin >> ch;
	ch2 = ch;
	while (ch1 == 'Y' || ch1 == 'y')
	{
	

		if (ch2 == '1')
		{
			Submenu:
				subMenu1();
				cout << "Submenu - input your choice";
				cin >> ch;
				ch3 = ch;

				switch (ch3)
			{
			case 'a':
			{
						cout << "Enter the first number in hexadecimal format (for example, 12ae):";
						cin >> hex >> r1;
						cout << "Enter the second number in hexadecimal format (for example, ff00):";
						cin >> hex >> r2;
						And_operation(r1, r2);
						break;
			}
			case'b':
			{
					   cout << "Enter the first number in hexadecimal format (for example, 12ae):";
					   cin >> hex >> r1;
					   cout << "Enter the second number in hexadecimal format (for example, ff00):";
					   cin >> hex >> r2;
					   Or_operation(r1, r2);
					   break;
			}
			case'c':
			{
					   cout << "Enter the first number in hexadecimal format (for example, 12ae):";
					   cin >> hex >> r1;
					   cout << "Enter the second number in hexadecimal format (for example, ff00):";
					   cin >> hex >> r2;
					   Xor_operation(r1, r2);
					   break;
			}
			case 'd':
			{
						cout << "Enter the first number in hexadecimal format (for example, 12ae):";
						cin >> hex >> r1;
						Not_operation(r1);
						break;
			}

			default: goto Submenu;

			}
		}
		else if (ch2 == '2')
		{
			subMenu2(); //code here
			cout << "Submenu - input your choice";
			cin >> ch;
			ch3 = ch;

			switch (ch3)
			{
			case 'a':
			{
						cout << "Enter the first number in hexadecimal format (for example, 12ae):";
						cin >> hex >> r1;
						cout << "Enter the second number in hexadecimal format (for example, ff00):";
						cin >> hex >> r2;
						And_operation2(r1, r2);
						break;
			}
			case'b':
			{
					   cout << "Enter the first number in hexadecimal format (for example, 12ae):";
					   cin >> hex >> r1;
					   cout << "Enter the second number in hexadecimal format (for example, ff00):";
					   cin >> hex >> r2;
					   Or_operation2(r1, r2);
					   break;
			}
			case'c':
			{
					   cout << "Enter the first number in hexadecimal format (for example, 12ae):";
					   cin >> hex >> r1;
					   cout << "Enter the second number in hexadecimal format (for example, ff00):";
					   cin >> hex >> r2;
					   Xor_operation2(r1, r2);
					   break;
			}
			case 'd':
			{
						cout << "Enter the first number in hexadecimal format (for example, 12ae):";
						cin >> hex >> r1;
						Not_operation2(r1);
						break;
			}

			default: goto Submenu;

			}
		}
		else
		{
			goto EndLable;
		}

		cout << "Do you like to continue the logic operations (Y/N)? Enter Y(y) or N(n): " << endl;
		cin >> ch;
		ch1 = ch;
	}

EndLable:

	cout << "Exit program" << endl;

	system("pause");
	exit(0);
	return 0;
}




void mainMenu()
{
	cout << "Menu:" << endl;
	cout << "1, Perform logic operations with 16-bit operand(s)" << endl;
	cout << "2,  Perform logic operations with 32-bit operand(s)" << endl;
	cout << "3,  Exit" << endl;

}

void subMenu1()
{
	cout << "a. Input two 16-bit unsigned number operands and perform an AND (&) operation.\n"
		<< " Display the operands and the result in binary format" << endl;
	cout << "b. Input two 16-bit unsigned number operands and perform an OR (|) operation.\n"
		<< " Display the operand and the result in binary format" << endl;
	cout << "c. Input two 16-bit unsigned number operands and perform an XOR (^) operation.\n"
		<< " Display the operand and the result in binary format" << endl;
	cout << "d. Input two 16-bit unsigned number operands and perform an NOT (~) operation.\n"
		<< " Display the operand and the result in binary format" << endl;
}

void subMenu2()
{
	cout << "a. Input two 32-bit unsigned number operands and perform an AND (&) operation.\n"
		<< " Display the operands and the result in binary format" << endl;
	cout << "b. Input two 32-bit unsigned number operands and perform an OR (|) operation.\n"
		<< " Display the operand and the result in binary format" << endl;
	cout << "c. Input two 32-bit unsigned number operands and perform an XOR (^) operation.\n"
		<< " Display the operand and the result in binary format" << endl;
	cout << "d. Input two 32-bit unsigned number operands and perform an NOT (~) operation.\n"
		<< " Display the operand and the result in binary format" << endl;
}

void And_operation(unsigned short r1, unsigned short r2)
{
	unsigned short r;
	_asm
	{
		mov AX, r1;
		mov CX, r2;
		and AX, CX;
		mov r, AX;
	}

	bitset<16>operant1_Bits(r1);
	bitset<16>operant2_Bits(r2);
	bitset<16>result_Bits(r);

	cout << "Perform an AND operation: " << endl;
	cout << "\t\t" << operant1_Bits << endl;
	cout << "\tAND" << "\t" << operant2_Bits << endl;
	cout << "--------------------------------\n";
	cout << "\t\t" << result_Bits << endl;
	cout << "=====================================================\n";
}

void Or_operation(unsigned short r1, unsigned short r2)
{
	unsigned short r;
	_asm
	{
		mov AX, r1;
		mov CX, r2;
		or AX, CX;
		mov r, AX;
	}
	bitset<16>operant1_Bits(r1);
	bitset<16>operant2_Bits(r2);
	bitset<16>result_Bits(r);

	cout << "Perform an OR operation: " << endl;
	cout << "\t\t" << operant1_Bits << endl;
	cout << "\tOR" << "\t" << operant2_Bits << endl;
	cout << "--------------------------------\n";
	cout << "\t\t" << result_Bits << endl;
	cout << "=====================================================\n";
}

void Xor_operation(unsigned short r1, unsigned short r2)
{
	unsigned short r;
	_asm
	{
		mov AX, r1;
		mov CX, r2;
		xor AX, CX;
		mov r, AX;
	}
	bitset<16>operant1_Bits(r1);
	bitset<16>operant2_Bits(r2);
	bitset<16>result_Bits(r);

	cout << "Perform an XOR operation: " << endl;
	cout << "\t\t" << operant1_Bits << endl;
	cout << "\tXOR" << "\t" << operant2_Bits << endl;
	cout << "--------------------------------\n";
	cout << "\t\t" << result_Bits << endl;
	cout << "===============================\n";
}

void Not_operation(unsigned short r1)
{
	unsigned short r;
	_asm
	{
		mov AX, r1;
		not AX;
		mov r, AX;
	}
	bitset<16>operant1_Bits(r1);
	bitset<16>result_Bits(r);

	cout << "Perform an NOT operation: " << endl;
	cout << "\tNOT" << "\t" << operant1_Bits << endl;
	cout << "--------------------------------\n";
	cout << "\t\t" << result_Bits << endl;
	cout << "===============================\n";
}

//------------------------------------------------32-bit----------------------------------------------------------------

void And_operation2(unsigned int r1, unsigned int r2)
{
	unsigned int r;
	_asm
	{
		mov EAX, r1;
		mov ECX, r2;
		and EAX, ECX;
		mov r, EAX;
	}

	bitset<32>operant1_Bits(r1);
	bitset<32>operant2_Bits(r2);
	bitset<32>result_Bits(r);

	cout << "Perform an AND operation: " << endl;
	cout << "\t\t" << operant1_Bits << endl;
	cout << "\tAND" << "\t" << operant2_Bits << endl;
	cout << "--------------------------------\n";
	cout << "\t\t" << result_Bits << endl;
	cout << "=====================================================\n";
}

void Or_operation2(unsigned int r1, unsigned int r2)
{
	unsigned int r;
	_asm
	{
		mov EAX, r1;
		mov ECX, r2;
		or EAX, ECX;
		mov r, EAX;
	}
	bitset<32>operant1_Bits(r1);
	bitset<32>operant2_Bits(r2);
	bitset<32>result_Bits(r);

	cout << "Perform an OR operation: " << endl;
	cout << "\t\t" << operant1_Bits << endl;
	cout << "\tOR" << "\t" << operant2_Bits << endl;
	cout << "--------------------------------\n";
	cout << "\t\t" << result_Bits << endl;
	cout << "=====================================================\n";
}

void Xor_operation2(unsigned int r1, unsigned int r2)
{
	unsigned int r;
	_asm
	{
		mov EAX, r1;
		mov ECX, r2;
		xor EAX, ECX;
		mov r, EAX;
	}
	bitset<32>operant1_Bits(r1);
	bitset<32>operant2_Bits(r2);
	bitset<32>result_Bits(r);

	cout << "Perform an XOR operation: " << endl;
	cout << "\t\t" << operant1_Bits << endl;
	cout << "\tXOR" << "\t" << operant2_Bits << endl;
	cout << "--------------------------------\n";
	cout << "\t\t" << result_Bits << endl;
	cout << "===============================\n";
}

void Not_operation2(unsigned int r1)
{
	unsigned int r;
	_asm
	{
		mov EAX, r1;
		not EAX;
		mov r, EAX;
	}
	bitset<32>operant1_Bits(r1);
	bitset<32>result_Bits(r);

	cout << "Perform an NOT operation: " << endl;
	cout << "\tNOT" << "\t" << operant1_Bits << endl;
	cout << "--------------------------------\n";
	cout << "\t\t" << result_Bits << endl;
	cout << "===============================\n";
}
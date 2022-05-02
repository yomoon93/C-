#include <iostream> 
using namespace std;

int main() {
	/*A 16-bit one dimensional u16_arr[n] array declaration and initialization.
	Pointers of uPtr will be used to store the address of the array 
	uc0 and u1 will store teh retrieved value from the relatively addressed by a register
	*/
	const int n = 5; //the dimension of an array 
	unsigned short int u16_arr[n] = { 0x0041, 0x0052, 0x1169, '12', 'aA' };
	unsigned short *uPtr;
	unsigned short u0, u1, u2, u3, u4;
	int i; //used as index
	int u0_addr, u1_addr, u2_addr, u3_addr, u4_addr;

	//Dispaly the hexadecimal and decimal values for each element of the unsigned short array 
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "-------The value of each element of the 16-bit array---------\n";
	for (i = 0; i < n; i++) {
		cout << "The value and size of element " << dec << i;
		cout << " in an array are 0x" << hex << u16_arr[i] << " and " << sizeof(u16_arr[i]) << " byte(s)" << endl;
	}
	printf("-------------------------------------------------------\n");
	uPtr = u16_arr;
	//Display the 32-bit address in hexadecimal format 
	cout << "The memory address of the array is 0x" << hex << uPtr << endl;

	_asm {
		//EBX holds the address of element 0 in the array 
		MOV EBX, uPtr

		//u0 holds the retrieved value from the indirect address contained in register EBX
		MOV AX, [EBX]
		MOV u0, AX
		MOV u0_addr, EBX

		//EBX IS INCREASED BY 2 DUE u16_arr IS AN UNSIGNED SHORT ARRAY (2 BYTES). EBX HOLDS THE ADDRESS OF ELEMENT 1 IN THE ARRAY
		MOV ECX, 2H
		ADD EBX, ECX

		//u1 HOLDS THE RETREIVED VALUE FROM TEH INDIRECT ADDRESS CONTAINED IN REGISTER EBX
		MOV AX, [EBX]
		MOV u1, AX
		MOV u1_addr, EBX

		//EBX+2H HOLDS TEH ADDRESS OF ELEMENT 2 IN THE ARRAY. u2 HOLDS THE RETREIVED VALUE FROM THE REGISTER RELATIVE ADDRESSING 
		MOV AX, [EBX+2H]
		MOV u2, AX

		//EDI HOLD TEH ADDRESS OF ELEMENT 2 IN AN ARRAY 
		MOV EDI, EBX
		ADD EDI, 2H
		MOV u2_addr, EDI

		//EBX+4H HOLDS THE ADDRESS OF ELEMENT 3 IN TH ARRAY. u3 HOLDS THE RETRIEVED VALUE FROM THE REGISTER RELATIVE ADDRESSING
		MOV AX, [EBX+4H]
		MOV u3, AX
		 
		//EDI HOLDS THE ADDRESS OF ELEMENT 3 IN THE ARRAY 
		MOV EDI, EBX
		ADD EDI, 4H
		MOV u3_addr, EDI

		//EBX+6H HOLDS THE ADDRESSS OF ELEMENT 4 IN TEH ARRAY. u4 HOLDS THE RETRIEVED VALUE FROM THE REGISTER RELATIVE ADDRESSING 
		MOV AX, [EBX+6H]
		MOV u4, AX

		//EDI HOLDS THE ADDRESS OF ELEMENT 4 IN THE ARRAY 
		MOV EDI, EBX
		ADD EDI, 6H
		MOV u4_addr, EDI
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "The retrieved values 0x" << hex << u0 << "\t at the address of 0x" << hex << u0_addr << endl;
	cout << "The retrieved values 0x" << hex << u1 << "\t at the address of 0x" << hex << u1_addr << endl;
	cout << "The retrieved values 0x" << hex << u2 << "\t at the address of 0x" << hex << u2_addr << endl;
	cout << "The retrieved values 0x" << hex << u3 << "\t at the address of 0x" << hex << u3_addr << endl;
	cout << "The retrieved values 0x" << hex << u4 << "\t at the address of 0x" << hex << u4_addr << endl;

	system("pause");
	return 0;
}
#include<stdio.h>	//to use printf()
#include<iostream>	//to use system("pause");

int main()
{
	/*A 16-bit one dimensional array declaration and initialization. 
	Pointers of svPtr0, svPtrl, etc will be used to store the address of each element of the array 
	A 32-bit array md[4] will be used to store each of pointers
	A 32-bit array madd[4] is used to store the address of each element of the array*/

	int const size = 4;
	short int sh16_arr[4] = { -1, -3, 1000, 2000 }; //16-bit array
	short *svPtr0, *svPtr1, *svPtr2, *svPtr3;			// used to store the address
	int md[4], madd[4];
	int i;		//used as index

	//Display the address of each element in an array sh16_arr[4]
	//printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	//printf("-----------The value of each element of 16-bit array---------\n\n");
	svPtr0 = &sh16_arr[0];
	svPtr1 = &sh16_arr[1];
	svPtr2 = &sh16_arr[2];
	svPtr3 =&sh16_arr[3];
    //Display the hexadecimal value and decimal for each element of the array
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("---------------The value of each element of 16-bit array------\n\n");
	for (i = 0; i < 4; i++)
	{
		printf("The value of element %d in an array is 0x%x(hex), %d(decimal)\n",
			i, sh16_arr[i], sh16_arr[i], sh16_arr[i]);

	}
	
	//Display addresses in hexadecimal format for each element of the array
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("--------The address of each element of 16-bit array---------\n\n");
	for (i = 0; i < 4; i++);
	{
		printf("The memory address of element %d in an array is 0x%X(hexadecimal)\n", i, svPtr0 + i);
	}
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	// Find the total numbers of bytes in the array
	printf("-----------------The size information in bytes of an 16-bit array---\n\n");
	printf("The total numbers in bytes of an 16-bit array with 4 elements is %d bytes\n",
		sizeof(sh16_arr));
	//Find the number of bytes of each element of the array
	for (i = 0; i < 4; i++)
	{
		md[i] = sizeof(sh16_arr[i]);
		madd[i] = sizeof(svPtr0 + i);
		printf("--------------------------------------------------------\n");
		printf("The size of element %d is %d bytes\n", i, md[i]);
		printf("The size of the address of the element %d is %d bytes\n", i, madd[i]);
	}
	system("pause");
	return 0;



}
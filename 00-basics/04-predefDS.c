#include <stdio.h>
// cont: array inside struct (use memcpy?), structure padding and packing unions, dynamic mem, threads

int main(){

	/*----ARRAYS----*/
	int intarr[5] = {0, 1, 2, 3, 4};				// 1d array
	double doubarr[] = {1.1, 2.22, 3.333, 4.4444};
	char str[] = "an array of characters";				// size = sizeof(str)/sizeof(char) 
	char arrofstr[][4] = {"str1", "str2", "str3", "str4"};		// 2d arr 


	/*----STRUCT----*/
	struct health {
		int height;
		double weight;
		char *bloodtype;
	};

	struct health h1;
	h1.height = 78; h1.weight = 190.88; h1.bloodtype = "o+";


	/*
	 * structure padding: (saves cycles, wastes space)
	 * if a structure variable does not fit on memory boundary of the architecture
	 * then empty space is added and next variable is made to fit the boundary
	 * ex: struct { char, char, int}. size of struct would be 8 bytes if word = 4 byte, 
	 * since both chars can fit in one word and int would have to scoot over
	 *
	 * structure packing: (wastes cycles, saves space)
	 * no boundary alignment, just pack all together
	 * can be done using pragma pack or attribute packed
	 */


	typedef struct {
		unsigned int cores : 5;		// max 5 bits (not enforced. will convert/truncate)
		char company[10];		// arrays must have specific size inside struct
		unsigned int mem   : 5; 	// in gb
	} laptop;


	laptop l1 = {4, "asus", 8};
	laptop l2 = {.cores = 2, .mem = 4, .company = "nokia"};


	/*----UNION----*/
	union nodiff {				// shares same mem location (size = size of max member)
		int a;
		char c;
	};

	union nodiff u1;
	u1.a = 10;				// both members value = 10 (since sharing mem location)
	u1.c = 'F';				// both members value = 70

	/* unions mostly used with structs inside or for mix type array */
	
}

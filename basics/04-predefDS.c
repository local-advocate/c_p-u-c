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

	typedef struct {
		unsigned int cores : 5;		// max 5 bits (not enforced. will convert/truncate)
		char company[10];		// arrays must have specific size inside struct
		unsigned int mem   : 5; 	// in gb
	} laptop;

	struct health h1;
	h1.height = 78; h1.weight = 190.88; h1.bloodtype = "o+";

	laptop l1 = {4, "asus", 8};
	laptop l2 = {.cores = 2, .mem = 4, .company = "nokia"};

}

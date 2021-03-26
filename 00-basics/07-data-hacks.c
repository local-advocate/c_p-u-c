#include <stdio.h>
#include <stdlib.h>		// to convert one type to another
#include <ctype.h>		// to determine type

int main(){


	/* STDLIB TYPE CONVERSION
	 * 
	 * FUNCTIONS
	 * double atof(const char *str)		:	string to double (0.0 if can't be converted)
	 *
	 */



	int i1 = 10;
	int i2;

	double d1 = 10.9d;
	double d2 = 0.0d;

	char c1 = 'Z';
	char c2;

	float f1 = 333.11f;
	float f2;

	char *str1  = "string1";
	char str2[] = "9&9.4a1";

	long int l1 = 129900388833l;
		



	if ((d2 = atof(str2)) != 0) {
		printf("String %s in double is %.5lf\n", str2, d2);
	}
	else {
		printf("ERR OR ZERO. String: %s. Double: %.5lf\n", str2, d2);
	}
}


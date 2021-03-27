#include <stdio.h>
#include <stdlib.h>		// to convert one type to another
#include <ctype.h>		// to determine type

int main(){

	/* STDLIB TYPE CONVERSION
	 * 
	 * FUNCTIONS
	 * double atof(const char *str)		:	string to double (0.0 if can't be converted)
	 *						a13.129 returns 000.000 (ERR)
	 *						1a3.129 returns 001.000
	 *						13a.129 returns 013.000
	 *						123.a11 returns 123.000
	 *						123.1a1 returns 123.100
	 *						123.11a returns 123.110
	 * 
	 * int atoi(const char *str)		:	string to int (0 if can't be converted or zero)
	 * 						a56.yyy returns 000 (ERR)
	 * 						4a6.yyy returns 004
	 * 						45a.yyy returns 045
	 * 						456.yyy returns 456
	 * 
	 * long int atol(const char *str)	:	string to long int (same as atoi but long qualifier)
	 *
	 * double strtod(const char *str, char **endptr) : returns double like atof and endptr = str location
	 * 						   a13.129 -- dbret: 000.000, endptr: &str[0]
	 *						   1a3.129 -- dbret: 001.000, endptr: &str[1]
	 *						   13a.129 -- dbret: 013.000, endptr: &str[2]
	 *						   123.a12 -- dbret: 123.000, endptr: &"a12"
	 *						   123.1a1 -- dbret: 123.100, endptr: &"a1"
	 *						   123.12a -- dbret: 123.120, endptr: &"a"
	 *						   123.123 -- dbret: 123.123, endptr: &(not null ptr)
	 *
	 * long int strtol(const char *str, char **endptr, int base) : same as strtod, but from base b to decimal
	 *
	 * long int strtoul(const char *str, char **endptr, int base) : same as strtod, but return in base
	 * 							        warning: will convert neg to pos
	 */


	int i1 = 10;
	int i2 = 0;

	double d1 = 10.9d;
	double d2 = 0.0d;
	double d3 = 0.0d;

	char c1 = 'Z';
	char c2;

	float f1 = 333.11f;
	float f2;

	char *str1  = "string1";
	char str2[] = "12a.a12";
	char *str3 = "45a.)))";
	char str5[] = "109988772a";
	const char *str6 = "-29943239814092348";
	char *str4 = NULL;

	long int l1 = 129900388833l;
	long int l2 = 0l;
	unsigned long int l3 = 0uL;

	// string to double
	if ((d2 = atof(str2)) != 0) {
		printf("String %s in double is %.5lf\n", str2, d2);
	}
	else {
		printf("ERR OR ZERO. String: %s. Double: %.5lf\n", str2, d2);
	}

	// string to double w/ pointer to str value start (&str4 because str4 would make local ptr copy)
	if ((d3 = strtod(str2, &str4)) != 0) {
		printf("String %s in double is %.5lf ; Remaining string: %s\n", str2, d3, str4);
	}
	else {
		printf("ERR OR ZERO. String: %s. Double: %.5lf\n", str2, d3);
	}

	// string to int
	if ((i2 = atoi(str3)) != 0) {
		printf("String %s in integer is %d\n", str3, i2);
	}
	else {
		printf("ERR OR ZERO. String: %s. Integer: %d\n", str3, i2);
	}
	
	// string to long int (in base b) w/ pointer to str value start [base range: [2,36]]. base 0 = atoi
	int base = 10;
	if ((l2 = strtol(str5, &str4, base)) != 0) {
		printf("String %s (base %d) in long is %ld (base %d) ; Remaining string: %s\n", str5, base,  l2, 10, str4);
	}
	else {
		printf("ERR OR ZERO. String: %s. Long: %ld (base %d)\n", str5, l2, base);
	}

	// string to unsigned long (will convert negative to positive if str starts with -)
	if ((l3 = strtoul(str6, &str4, base)) != 0 && str6[0] != '-') {
		printf("String %s (base %d) in ulong is %lu (base %d) ; Remaining string: %s\n", str6, base,  l3, 10, str4);
	}
	else {
		printf("ERR OR ZERO. String: %s. uLong: %lu (from base %d)\n", str6, l3, base);
	}


	/* 
	 * ctype ref (more ref at: https://code-reference.com/c/ctype.h)
	 *
	 * int alnum(int c)		:	returns non-zero if alphanumeric (0-9, a-z, A-Z), else zero
	 * int alpha(int c)		:	returns non-zero if alphabetic   (a-z, A-Z)     , else zero
	 * int iscntrl(int c)		:	returns non-zero if control char (ascii 0-1F,7F), else zero
	 *
	 * int tolower(int c)		:	return lowercase of c if possible else c 
	 *
	 * int toascii(int c)		:	returns c ascii value
	 *
	 */
}


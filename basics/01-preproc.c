// default search path: cpp -v
#include <stdio.h>			// <file> searches in system path. can be prepended with -I
#include "01-preproc.h"			// "file.h" searches in local dir first. can be prepended w/ -iquote

#include "01-preproc.h"			// will only be included once

 
// --------------------MACROS-------------------
#define MACRO_STR "ref: https://gcc.gnu.org/onlinedocs/cpp/index.html#SEC_Contents\n"  
#define CONT	  "cont: https://gcc.gnu.org/onlinedocs/cpp/Computed-Includes.html#Computed-Includes\n"

#define CONST 10    			// CONST = 10

#define FORARR 'a', \
		'b', \
		'c'

#define MAXFUNC(X, Y) ((X) > (Y) ? (X) : (Y))

int main(){
	
	/*----string----*/
	printf(CONT);

	/*----constant----*/
	printf("Const: %d\n", CONST);
	
	/*----array substitution----*/
	int arr[] = {FORARR};
	printf("arr: %c, %c, %c\n", *arr, arr[1], arr[2]);

	/*----function----*/
	int a = 29, b = 10;
	printf("Max of %d and %d is %d\n", a, b, MAXFUNC(a, b));

	/*----warning, error----*/
	#define PI 3
	#warning "redefining pi"
		printf("incr pi: %d\n", PI);
	#ifdef WINDOWS 
		#error "win wont work in linux"
	#endif

	/*----ifdef, undef----*/
	#ifdef PI
		#undef PI
	#endif /* PI */

	#define PI 3.14
		printf("cr pi: %f\n", PI);
	#undef PI

	/*----if, elif----*/
	#define SIZE 10
	#if defined SIZE && SIZE > 10
		printf("size is greater than 10\m");
	#elif SIZE - 10 == 0
		printf("size is 10\n");
	#else 
		printf("size not defined\n");
	#endif /* size */

	/*----ignoring line control----*/

	/*----predefined macros----*/ 
	printf("File: %s\n", __FILE__);
	printf("Line: %d\n", __LINE__);
	printf("Date: %s, Time: %s\n", __DATE__, __TIME__);
	printf("ISO?: %d, STDC version: %d, All stdc facilities available?: %d\n", __STDC__, __STDC_VERSION__, __STDC_HOSTED__);
	/*
	 * below doesnt work
	printf("c++ compiler used: %d\n", __cplusplus);
	printf("c# compiler used: %d\n", __OBJC__);
	printf("Preprocessing assembly?: %d\n", __ASSEMBLER__);
	*/
}

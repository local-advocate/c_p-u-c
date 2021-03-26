#include <stdio.h>
#include "03-qualifiers.h"

void printextern(){
	printf("Value of extint1 is: %d\n", extint1);
}

int inlfunc1(){				// will be called in case inlfunc1 is not inlined
	return -11;
}

static inline int inlfunc2(){		// will not get called in qualifiers.c
	return -22;
}

__attribute((always_inline))inline int inlfunc3(){	// definition of extern. gets called not substituted 
	return -3;
}


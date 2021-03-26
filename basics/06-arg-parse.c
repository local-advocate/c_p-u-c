#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){			// argc = num of arguments, argv = pointer to strings
	
	printf("Total arguments: %d\n", argc);
	
	if (argc < 2) {
	       printf("No arguments. Exiting...\n"); 	// first arg = file name	
	       exit(0);					// exit no error for now
	}

	for (int i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[argc]);
		++i;	
	}

}


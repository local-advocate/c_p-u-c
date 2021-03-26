#include <stdio.h>

int main (int argc, char **argv){			// argc = num of arguments, argv = pointer to strings
	
	printf("Total arguments: %d", argc);
	
	while (argc != 0) {
		printf("argv[%d]: %s\n", argc, argv[argc]);
		--argc;	
	}

}


#include <stdio.h>
#include <unistd.h>		// for getopt
#include <stdlib.h>		// for exit


/* NOTES (ref: https://www.gnu.org/software/libc/manual/html_node/Argument-Syntax.html)
 * command format: <command> -[option] <argument> 
 * 		   if option takes argument: -option argument is same as -optionargument
 * 		   if it does not	   : -optionoption is same as -option -option
 * 		   -- terminates all options & arguments
 */


/* GETOPT (ref: https://www.gnu.org/software/libc/manual/html_node/Getopt.html)
 *
 * VARIABLES
 * int opterror	: print error if unknown option && int != 0, if zero returns '?'
 * int optopt	: unknown option char or option with missing arg stored in optopt [used to print nondef options]
 * int optind	: index of next elem of array (set by getopt) [use to determine where nondef options start]
 * char *optarg : point at value of optional argument
 * 
 * FUNCTIONS
 * int getopt (int argc, char *const *argv, const char *options)
 * 	param argc    : total arguments
 * 	param argv    : constant pointer to arguments
 * 	param options : pointer to options (constant literal) 
 * 		        options = string of valid option characters, add : to indicate arguments required, :: opt
 * 	return value  : returns character/option read, -1 if no more VALID options (compare optind with argc)
 * 			if option has argument, it is stored in optarg
 * 			if non-option, sets optopt = non-opt char and returns ? (if opterror == 0)
 * 			if arg not found but req, returns : (if opterror == 0, else prints error msg)
 *
 * WORKING
 * rearranges all non-option to be at the end
 * if finds -, attaches the following arg (if present) to it
 * if finds +, terminates processing
 */


int main(int argc, char **argv) {
	
	int c;							// c: option to be read
	int index;						// index of non-option
	int opterr = 0;						// to not print error message
	
	int  aflag = 0, bflag = 0, cflag = 0;			// flags to avoid parsing same options again
	char *a_arg, *c_arg;					// arg: argument for option (if present)

	while ((c = getopt(argc, argv, "a:bc:")) != -1) {	// if -1 then done
	
		switch (c) {
			
			case 'a':
				a_arg = optarg;
				aflag = 1;
				break;

			case 'b':
				bflag = 1;
				break;

			case 'c':
				cflag = 1;
				c_arg = optarg;
				break;

			/*  
			 * getopt does not return : but handles it internally in my case
			 * can implement ':' with switch optopt but would let getopt take care of it
			 */
				
			/* case ':':
			 *	printf("Optiooooon %c requires argument\n", optopt);
			 *	break;
			 */

			// how to disable getopt message "argv[0]: invalid option -- 'optopt'"
			case '?':
				printf("Unknown option: %c at index %d\n", optopt, optind);
				break;

			default:
				printf("Usage: %s -[abc]\n", argv[0]);
				exit(0);
		}
		
	}


	/* 
	 * printing nonoptions (only works if option format is invalid [doesnt start with '-'])
	 * works since all invalid format get rearragned to be positioned at the end
	 */	
	if (optind != argc) {						// non-options present
		for (index = optind; index < argc; index++) {
			printf("Unknown option: %s at index %d\n", argv[index], index);
		}
		printf("\n");
	}


	/*
	 * now parsing all flags 
	 * to do: better way to combine and use arguments +
	 * check and convert argument from string to char, int, or other type
	 */
	if (aflag) {
		printf("a argument: %s\n", a_arg);
	}
	if (bflag) {
		printf("bflag true\n");
	}
	if (cflag) {
		printf("c argument: %s\n", c_arg);
	}
}

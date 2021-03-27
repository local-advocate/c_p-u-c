#include <stdio.h>
#include <getopt.h>	// for getopt long
#include <stdlib.h>	// for exit


/* NOTES (ref: https://www.gnu.org/software/libc/manual/html_node/Getopt-Long-Options.html)
 *  
 * GETOPT LONG
 *
 * STRUCT
 *
 * struct option {	 	// describes a single long option (getopt long takes array of this struct)
 * 	const char *name;	// name of the option
 * 	int has_arg;		// option takes argument (no_argument, required_argument, optional_argument)
 *	int *flag;		// if flag = NULL, val  = value which identifies option (for err reporting)
 *	int val;		// if flag ! NULL, flag = address of int variable of flag, val =  
 *	}
 *
 *
 * FUNCTION
 *
 * int getopt_long (int argc, char *const *argv, const char *shortopts, const struct option *longopts, int *indexptr) 
 * param:
 * argc		:	total argumets
 * argv		:	pointer vector of decode options
 * *shortopts	:	ptr string of short options (same as getopt) (all params of getopt can be used here)
 * *longopts	:	pointer to array of long options 
 * *indexptr	:	pointer to index in longopts array for any longoptions encountered
 * 			use with val to determine which options set flags
 * optarg	:	argument if used is stored in optarg, else null (check for optional argumets)
 * optind	:	index for remaining arguments (if optind != argc at the end)
 *
 *
 * RETURN
 * if flag == NULL, return = contents of val to indicate which option found (keep val values distinct)
 * 		    if long == shortopt, short option's character code can be used as val
 * if flag != NULL, option should set a flag (of int type) defined in program. (return = 0)
 * 		    *flag = address of flag, val = value to be stored in flag
 * -1 if done processing (compare optind and argc for remaining arguments)
 *
 *
 * other: (legacy)
 * int getopt_long_only(same as above) can take long options starting with - instead of -- 
 * (first searches longopts and then short)
 */

	int help_flag = 0;

int main(int argc, char **argv){

	if (argc < 2) {
		printf("Usage: %s [flags]\n", argv[0]);
		exit(-1);
	}


	int c; 						// return value of getopt_long
	int option_index = 0;				// index of current option
	// int has_arg;					// 0: no arg, 1: required, 2: optional
	

	static struct option longopts[] = 		// array of struct option
	{	
		// options that set flag
		{"help", 0, &help_flag, 1},		// argument sets help flag and sets value = 1

		// options that set value
		{"opta", 0, 0, 'a'},
		{"optb", 1, 0, 'b'}, 
		{"optc", 2, 0, 'c'},
		
		{0, 0, 0, 0}				// null terminate
	};

	char *shortopts = "a";
	
	while ((c = getopt_long (argc, argv, shortopts, longopts, &option_index)) != -1) {

		switch (c) {
			
			case 0:				// option sets a flag
				printf("Option %s sets flag. Val = %d.\n", longopts[option_index].name, longopts[option_index].val); 			
				if (longopts[option_index].has_arg) {
					printf("Argument: %s\n", optarg);
				}
				break;

			default:
				printf("DEFAULT\n");
				exit(-1);

		}

	}


	/* implementing flags now */
}

#include <stdio.h>
#include <unistd.h>		// for getopt


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
 * int optint	: index of next elem of array (set by getopt) [use to determine where nondef options start]
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

int main() {

}

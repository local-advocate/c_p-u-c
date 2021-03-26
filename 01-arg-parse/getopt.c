#include <stdio.h>
#include <unistd.h>		// for getopt

/* NOTES (ref: https://www.gnu.org/software/libc/manual/html_node/Argument-Syntax.html)
 * command format: <command> -[option] <argument> 
 * 		   if option takes argument: -option argument is same as -optionargument
 * 		   if it does not	   : -optionoption is same as -option -option
 * 		   -- terminates all options & arguments

int main() {

}

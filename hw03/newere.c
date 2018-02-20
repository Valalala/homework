//Walter Rasmussen Spring 2018
//Args = RE, out = matches from stdin

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <sys/types.h>
int main(int argc, char * argv[])
{
	regex_t re; // Stores the regular expression. 
	char line[4096]; // Line from file.  

	if (argc!=2) { // Checks args. 
		printf("Only enter an RE as arg.\n");
		return 1;
	}
	if (regcomp(&re, argv[1],REG_EXTENDED) != 0){
		printf("Please enter a valid RE.");
		return 1;
	}
	
	do { // Reads line by line. 
		fgets(line,4096,stdin);
		if (regexec(&re,line,0,NULL,0) == 0){ // RE search
			printf("%s",line); // Prints whole line if match exits.
		}
	} while (!feof(stdin)); 
	regfree(&re);
	return 0;
}



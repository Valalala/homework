//Walter Rasmussen Spring 2017
//Accepts REs and outputs matches.

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <sys/types.h>
int main(int argc, char * argv[])
{
	regex_t re;
	int ret;
	char line[4096];
	regmatch_t rm[256];
	if (argc!=2) {
		fprintf(stderr,"Usage: %s Eregex\n",argv[0]);
		fprintf(stderr," data input from stdin\n");
		return 1;
	}
	ret=regcomp(&re, argv[1],REG_EXTENDED);
	
	while (!feof(stdin)) {
		fgets(line,4096,stdin);
		ret=regexec(&re,line,256,rm,0);
		if (!ret) {
			printf("%s",line);
		}
	}
	regfree(&re);
	return 0;
}


// Walter Rasmussen - Spring 2018
// Prints all entered command line arguments.
#include <stdio.h>
int main(int argc, char *argv[])
{
	int i;
	for (i=0;i<argc;i++) {
		printf("%s\n",argv[i]);
	}
	return 0;
}

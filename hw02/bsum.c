// Walter Rasmussen Spring 2017
// A program to sum file sizes using the block count
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdint.h>
int main(int argc, char * argv[])
{
	unsigned int i; // Counter
	blkcnt_t sum=0; // Sum
	struct stat s; // Stat buffer for count
	int ret; // Error checking
	// For each command line arg
	for (i=1;i<argc;i++) {
		ret=stat(argv[i],&s); // Get the inode metadata
		if (ret<0) { // Check for errors
			perror("stat");
			continue;
		}
		printf("%s %lu\n",argv[i],s.st_blocks); // Print this file
		sum+=s.st_blocks; // Sum
	}
	printf("%lu\n",sum); // Total
	return 0;
}


// Walter Rasmussen - Spring 2018
// Returns total size in bytes of passed files. 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int i; // Counter for for loops.
	long sum = 0; // 
	long oldsum = 0; // Checks for overflow.(Kind of un-needed, but for robustness)
	struct stat sb;
	
	// Checks number of arguments. 
	if (argc == 1) {
		printf("Please enter at least one file. \n");
		return 1;
	}
	
	// Loop for each argument. 
	for (i=1; i<argc; i++){
		// Checks if stat() succeeds.
		if (stat(argv[i], &sb) == -1) {
			printf("Stat syscall failed on arg %d.\n", i);
			return 1;
		}
		// Checks if number of bytes fit in a long int.
		if (sum < oldsum){
			printf("Overflow: files too large.\n");
			return 1;
		}
		sum += sb.st_size;
		oldsum = sum;
	}
	printf("Total size: %li bytes.\n", sum);		
	return 0;
}


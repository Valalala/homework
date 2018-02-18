// Walter Rasmussen - Spring 2018
// Parses a string to sum positive integers. 
// Plus signs indicating a number is positive are not accepted; positive numbers are assumed.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int i; // Counter for for loops.
	long sum = 0; // 
	long oldsum = 0; // Checks for overflow.
	char *integerstr; // Keeps track of where in the passed string the program is.
	
	// Checks number of arguments. 
	if (argc != 2) {
		printf("Please enter exactly one argument. \n");
		return 1;
	}
	// Checks for existance of '+', and ensures it is not at the start or end of the argument. 
	if (strchr(argv[1],'+') == NULL || *(strrchr(argv[1],'+')+1) == '\0' || strchr(argv[1], '+') == argv[1]) {
		printf("Please include a + between two integers. \n");
		return 1;
	}
	// Ensures the argument is only integers and '+'
	for (i=0;i<strlen(argv[1]);i++){
		if ((*(argv[1]+i) < '0' || *(argv[1]+i) > '9') && *(argv[1]+i) != '+') {
			printf("Please only enter integers and plus signs.\n");
			return 1;
		}
	}
	
	// Takes each integer string and adds it to a running total: sum.
	sum += strtol(argv[1], &integerstr, 10);
	while (*integerstr != '\0') {
		sum += strtol(integerstr+1, &integerstr, 10);
		if (sum < oldsum){
			printf("Overflow: use smaller numbers.\n");
			return 1;
		}
		oldsum = sum;
		// printf("sum = %d\n", sum);
	}

	printf("sum = %d\n", sum);
		
	return 0;
}



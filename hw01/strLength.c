//Walter Rasmussen - Spring 2018
//Prints the number of characters in the given argument.
#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Fix your args\n");
		return 1;
	}
	printf("%d\n", strlen(argv[1]));
	return 0;
}

// pnc.c - Walter Rasmussen - Spring 2018
// Print number of characters
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Fix your args.\n");
		return 1;
	}
	int i;
	for (i = 0; i < strtol(argv[1], NULL, 10); i++) printf("f");
	return 0;
}

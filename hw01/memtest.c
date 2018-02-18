//Walter Rasmussen Spring 2017
// A program to test memory speed
#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
int main(int argc, char *argv[])
{
	size_t size; // Buffer size
	unsigned char *b; // Buffer
	int ret; // Return values
	
	struct timespec res; // Timer resolution
	struct timespec s; // Start time stamp
	struct timespec e; // End time stamp

	// Pass the size of the buffer in bytes
	if (argc!=2) {
		printf("Usage: %s size\n",argv[0]);
		return 1;
	}
	
	// Print the size
	printf("%s ",argv[1]);
	
	// Get the resolution just to check it
	ret=clock_getres(CLOCK_MONOTONIC,&res);
	if (ret<0) {
		perror("getres");
		return 6;
	}
	printf("%lu %lu",res.tv_sec,res.tv_nsec);
	
	// Convert passed size to integer
	size=atoi(argv[1]);
	if (size<=0) {
		printf("buffer size must be non-zero and positive\n");
		return 8;
	}
	
	// Allocate the memory and check for errors
	b=(unsigned int *)malloc(size);
	if (b==NULL) {
		perror("malloc");
		return 2;
	}
	
	// Start time stamp, write, and stop time stamp
	ret=clock_gettime(CLOCK_MONOTONIC,&s);
	if (ret<0) {
		perror("getres");
		return 6;
	}
	memset(b,'a',size);
	
	//sleep(100);
	ret=clock_gettime(CLOCK_MONOTONIC,&e);
	if (ret<0) {
		perror("getres");
		return 6;
	}
	printf(" %lu %lu %lu %lu\n",s.tv_sec,s.tv_nsec,e.tv_sec,e.tv_nsec);
	
	// clean up
	free(b);
	return 0;
}



//Walter Rasmussen Spring 2017
// Block size sum program modified to use a glob passed on cmd line
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdint.h>
#include <glob.h>
int main(int argc, char * argv[])
{
	unsigned int i; // Count
	blkcnt_t sum=0; // Block Sum
	struct stat s; // Inode metadata
	int ret; // Error checking
	glob_t pglob; // Glob return
	// Check for 1 arg - namely glob pattern
	if (argc!=2) {
		printf("Usage: %s glob\n",argv[0]);
		return 1;
	}
	// Glob the passed arg
	ret=glob(argv[1],0,NULL,&pglob);
	if (ret<0) {
		perror("glob");
		return errno;
	}
	// Iterate over globs
	for (i=0;i<pglob.gl_pathc;i++) {
		ret=stat(pglob.gl_pathv[i],&s); // Get metadata
		if (ret<0) {
			perror("stat");
			continue;
		}
		printf("%s %lu\n",pglob.gl_pathv[i],s.st_blocks); // Print each
		sum+=s.st_blocks; // Sum
	}
	// Print total
	printf("%lu\n",sum);
	globfree(&pglob); // Clean up
	return 0;
}


// Walter Rasmussen - Spring 2018
// Creates a child, whom waits, then sends SIGHUP

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]){
	pid_t pid; // Stores pid of child. 
	
	signal(SIGHUP, SIG_DFL); // Uses default handling for SIGHUP. 
	pid = fork(); // Creates child. 
	
	if (pid > 0) { // If parent. 
		kill(pid,SIGHUP); // Sends SIGHUP, then exits. 
	} else if (pid == 0) { // If child.
		while (1) sleep(1); // Sleeps in 1 second intervals. 
	} else { // If fork() fails, exit. 
		printf("fork() failed. \n");
		return 1;
	}

	return 0;
}


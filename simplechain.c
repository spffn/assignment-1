#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This program takes in an argument from the command line and creates that many child processes.
int main (int argc, char *argv[]) {

	pid_t childpid = 0;
	int i, n;
	
	if (argc != 2) { /* check for valid number of command-line arguments */
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	
	n = atoi(argv[1]);
	for (i = 1; i < n; i++) {
		if (childpid = fork()) {
			break;
		}
	}
	
	// Print the id of the current process before it terminates, as well as its parents id.
	fprintf(stderr, "\n #%d \n Process ID: %ld \n Parent ID: %ld \n Child ID: %ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}
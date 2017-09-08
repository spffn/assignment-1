#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This program takes in an argument from the command line and creates that many child processes.
int main (int argc, char *argv[]) {

	pid_t childpid = 0;
	char errstr[50];
	snprintf(errstr, sizeof errstr, "%s: Error: ", argv[0]);
	int i, n;
	opterr = 3;		// minimum of three arguments necessary
					// program name, # of processes to spawn and -h flag
	

	if (argc > 3 || argc < 2) { /* check for valid number of command-line arguments */
		perror(errstr);
		fprintf(stderr, "Invalid number of arguments.");
		return 1;
	}
	else {
		while ((c = getopt(argc, argv, "h")) != -1) {
			switch (c) {
				case 'h':
					fprintf(stderr, "REQUIRED ARGUMENTS: \n");
					fprintf(stderr, "This program requires a command line argument for number of processes to spawn.\n");
					fprintf(stderr, "After ./a.out, please include a number.\n");
					break;
				case '?':
					perror(errstr);
					fprintf(stderr, "Invalid argument(s): %s \n", optopt);
					return 1;
				default:
					perror(errstr);
					fprintf(stderr, "Invalid argument(s): %s \n", optopt);
					return 1;
			}
		}
	}
	
	n = atoi(argv[1]);
	for (i = 1; i < n; i++) {
		if (childpid = fork()) {
			break;
		}
	}
	
	// Print the id of the current process before it terminates, as well as its parents id.
	// sleep(10);
	fprintf(stderr, "\n #%d \n Process ID: %ld \n Parent ID: %ld \n Child ID: %ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}
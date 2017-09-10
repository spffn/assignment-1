/* Taylor Clark
CS 4760
Assignment #1
Unix System Calls and Library Functions */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* This program takes in an argument from the command line and creates that many child processes. It also displays a list of allowed command line arguments
when the -h flag is used. */
int main (int argc, char *argv[]) {

	pid_t childpid = 0;
	char errstr[50];
	snprintf(errstr, sizeof errstr, "%s: Error: ", argv[0]);
	int i, n, c;
	opterr = 0;	

	// parse the command line arguments
	while ((c = getopt(argc, argv, ":n:h")) != -1) {
		switch (c) {
			// sets the number of processes to create
			// -n requires an argument to work
			case 'n':
				n = atoi(optarg);
				break;
			// show help
			case 'h':
				fprintf(stderr, "\n----------\n");
				fprintf(stderr, "HELP LIST: \n");
				fprintf(stderr, "-n: \n");
				fprintf(stderr, "\tSets the number of child processes to spawn. \n");
				fprintf(stderr, "\tMust be a number. \n");
				fprintf(stderr, "\tex: -n 5 \n");
				fprintf(stderr, "-h: \n");
				fprintf(stderr, "\tShow help, valid options and required arguments. \n");
				fprintf(stderr, "----------\n\n");
				break;
			// if no argument is given for n, print an error and end.
			case ':':
				perror(errstr);
				fprintf(stderr, "-n requires an argument. \n", optopt);
				return 1;
			// if an invalid option is caught, print that it is invalid and end
			case '?':
				perror(errstr);
				fprintf(stderr, "Invalid option(s): %s \n", optopt);
				return 1;
		}
	}

	// fork off the # of times given by the user, so long as n is
	// greater than 0
	if(n > 0){
		for (i = 1; i < n; i++) {
			if (childpid = fork()) {
				break;
			}
		}
	}
	else { 
		// n was never given and we should end early to prevent a print out
		// of the current process info
		return 1;
	}
	
	// sleep(10);
	
	// Print the id of the current process before it terminates, as well as its parents id.
	fprintf(stderr, "#%d | Process ID: %ld | Parent ID: %ld | Child ID: %ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}
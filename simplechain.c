#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This program takes in an argument from the command line and creates that many child processes.
int main (int argc, char *argv[]) {

	pid_t childpid = 0;
	char errstr[50];
	snprintf(errstr, sizeof errstr, "%s: Error: ", argv[0]);
	int i, n = 0, c;
	opterr = 0;	

	// parse the command line arguments
	while ((c = getopt(argc, argv, "n:h")) != -1) {
		switch (c) {
			// sets the number of processes to create, requires argument
			case 'n':
				n = atoi(optarg);
				break;
			// show help
			case 'h':
				fprintf(stderr, "HELP LIST: \n");
				fprintf(stderr, "-n: \n ");
				fprintf(stderr, "Sets the number of child processes to spawn. \n");
				fprintf(stderr, "Must be a number. \n");
				fprintf(stderr, "-h: \n ");
				fprintf(stderr, "Show help, valid options and required arguments. \n\n ");
				break;
			case '?':
				if(optopt == 'n'){
					perror(errstr);
					fprintf(stderr, "-n requires an argument. \n", optopt);
				}
				else if(isprint(optopt)){
					perror(errstr);
					fprintf(stderr, "Invalid option(s): %s \n", optopt);
				}
				else {
					perror(errstr);
					fprintf(stderr, "Invalid argument(s): %s \n", optopt);
				}
				return 1;
			default:
				perror(errstr);
				fprintf(stderr, "Invalid argument(s): %s \n", optopt);
				return 1;
		}
	}

	// fork off the # of times given by the user
	for (i = 1; i < n; i++) {
		if (childpid = fork()) {
			break;
		}
	}
	
	// Print the id of the current process before it terminates, as well as its parents id.
	// sleep(10);
	fprintf(stderr, "#%d | Process ID: %ld | Parent ID: %ld | Child ID: %ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}
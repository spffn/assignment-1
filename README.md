As a general description, this project takes in an argument from the command line and creates that many child processes. Each question from the assignment modifies it slightly, and therfore will be described further down in the readme in the appropriate section. The entire project is derived from Program 3.1 in the Unix System Programming book.


--- TO COMPILE ---

Run the makefile to compile all 6 versions of the code. Each will be named according to what question they align with.

--- TO RUN ---

./(program name) -(any required command line arguments) (their values, if needed)

EX: ./Q1ToQ3 -n 10

--- GITHUB ---

I would first like to mention that this is my first time using GitHub and it likely that I used it incorrectly. However, here is where my project is at and where all commits can be viewed:

	https://github.com/spffn/assignment-1


--- DESCRIPTIONS ---

-- Q1 - Q3: 
	
    Code to run: Q1ToQ3
    This program is the most basic of all, and simply runs for the specificed number of child processes provided to it by the user.
	This program has two accepted command line arguments:
		
		-n: Will set the number of child processes to spawn.
			It requires an argument. It is required for the program to run.
			Ex. -n 5
		-h: Show help. This shows all the accepted command lines arguments for this
			version of the program.
			Not required for program to run.

	Run Example: ./Q1ToQ3 -n 8 -h
			
-- Q4:
	
    Code to run: Q4
	This program is identical to Q1ToQ3 with the addition of sleep(10) in it. 
	The accepted command line arguments are the same as Q1ToQ3.
	
-- Q5: 
	
    Code to run: Q5
	This program is similar to Q4, but with the addition of a loop and the ability for the user to specify the number of times the loop must run as well as the value of sleep. These values are k (loop runs) and sleep(m), and must be passed through the command line.
	This program has two accepted command line arguments:
		
		-n: Will set the number of child processes to spawn.
			It requires an argument. It is required for the program to run.
			Ex. -n 5
		-k: Will set the number of times for the final loops to print out the 
			process information.
			It requires an argument. It is required for the program to run.
			Ex: -k 3
		-m: Will set the length of time for sleep() to run.
			It requires an argument. It is required for the program to run.
			Ex: -m 9
		-h: Show help. This shows all the accepted command lines arguments for this
			version of the program.
			Not required for program to run.
			
	Run Example: ./Q5 -n 8 -k 3 -m 10

-- Q6:
	
    Code to run: Q6
	This program is identical to Q1ToQ3 with the addition of wait() in it. 
	The accepted command line arguments are the same as Q1ToQ3.
	
-- Q7:
	
    Code to run: Q7
	This program replaces the final fprintf with four seperate fprints, the last of which outputs a newline. This program is identical to Q1ToQ3 aside from this.
	The accepted command line arguments are the same as Q1ToQ3.
	
-- Q8:
	
    Code to run: Q8
	This program takes in two arguments, the number of processes to run and the number of arguments to read in from the command line. The program then prints these chars along with a process id.
	This program has two accepted command line arguments:
		
		-n: Will set the number of child processes to spawn.
			It requires an argument. It is required for the program to run.
			Ex. -n 5
		-c: Will set the number of chars to read in from command line.
			It requires an argument. It is required for the program to run.
			Ex: -c 50
		-h: Show help. This shows all the accepted command lines arguments for this
			version of the program.
			Not required for program to run.
			
		Run Example: ./Q5 -n 8 -c 20

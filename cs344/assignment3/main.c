/*
*   Max Franz
*   11/3/20
*   smallsh
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>

#define SIGINT 2 //Interrupts the process
#define SIGTSTP 20 //Stops the process

//Allowed global variables
char *argList[512]; //Handles 512 arguments
int processPID[1000]; //Keeping track of processes
int numProcesses = 0; //Number of processes
bool enableBg = false; //If background is enabled or not, default is false

struct sigaction SIGINT_action, SIGTSTP_action, INTERRUPTED_action; //Signal struct, this is from the Signal Handling API Exploration

/*
 *   This is the CTRL-Z handler
*/
void catch_SIGTSTP(int signo) {
	//If it's 1, set it to 0 and display a message
	if(enableBg == false) {
		char m1[] = "Entering foreground-only mode (& is now ignored)\n";
		write(1, m1, 49);
		fflush(stdout); //Clear the buffer
		enableBg = true; //Enable background
	} else { //If it's 0, set it to 1 and display a message
		char m1[] = "Exiting foreground-only mode\n";
		write(1, m1, 29);
		fflush(stdout); //Clear the buffer
		enableBg = false; //Disable background
	}
}

/*
 *    This function acts just like the linux 'cd' function
*/
void cd(int numArgs){
    	if(numArgs == 1){ //If it's 1, then cd was called with no arguments
     		chdir(getenv("HOME"));
    	} else{ //If there's more than 1 argument, it only reads the one after chdir
        	chdir(argList[1]);
    	}
}

/*
 *   This function will exit the shell and kill all processes
*/
void Exit() {
    	int pid;
    	for(int i = 0; i < 1000; i++) {
        	if(pid == 0){ //If there's no more processes, then we can exit
            		exit(0);
        	}
        	kill(processPID[i], SIGTERM); //This line kills the processes 1 at a time
    	}
}

/*
 *   This function prints out either the exit status or the terminating signal of the last foreground process ran by the shell
*/
void status(int *called, int stats) {
    	int procErr = 0;
    	int sigErr = 0;
    	int exitVal;

    	waitpid(getpid(), &stats, 0); //Getting the stats of the current process

    	if(WIFEXITED(stats)) { //Returns a value > 0 if the child process exits normally
        	procErr = WEXITSTATUS(stats); //Status of the dead child process gets saved
    	}

    	if(WIFSIGNALED(stats)) { //Checks what the child process was killed by
        	sigErr = WTERMSIG(stats); //Save the signal if abnormal
    	}

    	if(procErr == 0 && sigErr == 0) { //If there are no errors, exit normally
        	exitVal = 0;
    	} else { //If there are errors, exit not normally
        	exitVal = 1;
    	}

    	//I think the problem is right here, but I'm not sure how to fix it

    	if(sigErr != 0){ //If there is a signal other than zero, enter if
        	*called = 1; //This handles the terminated signal for CTRL-C
        	printf("Terminated by signal %d\n", sigErr);
        	fflush(stdout);
    	} else { //Print exit status if no error signal
        	printf("Exit value %d\n", exitVal);
        	fflush(stdout);
    	}
}

/*
 *   Gets the PID and stores them in global array
*/
void getPID(pid_t num) {
	processPID[numProcesses] = num;
    	numProcesses++; // The numbur of processes are counted
}

/*
 *   This function will run the commands that aren't built-in
*/
void otherCMDs(int *called, int stats, bool foreground) {
    	pid_t c_pid; //The child process
    	pid_t pid; //The parent process
    	int fd1 = 0, fd2 = 0, in = 0, out = 0;
    	char input[2048],  output[2048]; //File input and output buffer

    	c_pid = fork(); //Fork
    	getPID(c_pid);

    	if(c_pid == 0) {
		int i = 0;
        	while(argList[i] != NULL) { //Iterate until null terminator
            		if(strcmp(argList[i], "<") == 0) { //If < is present, this catches it
                		in = 1; //Helps with direction of the thing, < or >
                		argList[i] = NULL; //The index is set to NULL
                		strcpy(input, argList[i + 1]); //Copy to get the file location
            		} else if(strcmp(argList[i], ">") == 0) { //If > is present, this catches it
                		out = 1; //Helps with direction, < or >
                		argList[i] = NULL; //The index is set to NULL
                		strcpy(output, argList [i + 1]); //Copy to get the file location
            		}
			i++;
        	}

        	if(in) {  //If '<'
            		fd1 = open(input, 0); //Open the file
            		dup2(fd1, 0); //Redirect
            		close(fd1); // Close the filepath
        	}

        	if(out) { //If '>'
            		fd2 = open(output, O_WRONLY|O_CREAT|O_TRUNC, 0644); //Open the file
            		dup2(fd2, 1); //Redirect
            		close(fd2); //Close the filepath
        	}

        	if(foreground == true ) {
            		SIGINT_action.sa_handler = SIG_DFL; //Kill the process
        	}

        	//Change action
        	sigaction(SIGINT, &SIGINT_action, NULL);

        	//Run the command
        	execvp(argList[0], argList);
    	} else if(c_pid > 0){ //If parent, enter this
        	pid_t tempPID; //A temp process
        	if(foreground == false && enableBg == false) { //Execute the command regularly
			tempPID = waitpid(c_pid, &stats, WNOHANG); //Check child with no hang
			printf("Background PID: %d\n", c_pid); //Prints the background pid
			fflush(stdout);
		} else {  //Executing the command like normal
            		fflush(stdout);
            		tempPID = waitpid(c_pid, &stats, 0);
        	}
    	} else { //If fork fails
        	perror("Fork Error!");
        	exit(1); //Exit
    	}

    	while((c_pid = waitpid(-1, &stats, WNOHANG)) > 0) { //Wait to read out all children deaths
        	printf("Background PID %d is done: ", c_pid);
        	status(called, stats); //Status of the deceased child
        	fflush(stdout);
	}
}

/*
 *   This will call the built in and regular shell commmands based on user input
*/
void commandCall(int numArgs, int stats, bool foreground) {
    	int sigHold;
    	int called = 0;

    	if(*argList[0] == '\n' || *argList[0] == '#'){
        	//Ignore if this if is entered
    	} else if(strcmp(argList[0], "cd") == 0){ //Call cd with numArgs if this if is entered
        	cd(numArgs);
    	} else if(strcmp(argList[0], "status") == 0){ //Call status if this if is entered
        	status(&called, stats);
    	} else if(strcmp(argList[0], "exit") == 0){ //Exit the program if this if is entered
        	Exit();
    	} else {
        	foreground = true; //Want to start in foreground
        	//Check if & is present
        	if(enableBg == true && strcmp(argList[numArgs-1],"&")==0){ //Check if background is disabled here
            		argList[numArgs-1] = NULL; //Sets the & to null for execvp
        	} else if(strcmp(argList[numArgs-1],"&")==0) {
            		argList[numArgs-1]=NULL; //Sets the & to null for execvp
            		foreground = false; //Disable foreground
        	}

        	otherCMDs(&called, stats, foreground); //Handle non built in commands

        	if(WIFSIGNALED(stats) && called == 0){ //Check if child is killed
            		status(&called, stats); //Get status of child
        	}
    	}
}

/*
*   This function will collect all arguments given from the user
*/
int argParse(char* args) {
    	int numArgs = 0;
    	char buff[2048];
    	char *word;

    	printf(": "); //Prompt
    	fflush(stdout); //Flush just in case
    	fgets(args,2048,stdin); //Save the input
    	strtok(args, "\n"); //Remove the newline

    	char *rest = args;

    	//Place each argument into it's own index in the argList array
    	while((word = strtok_r(rest, " ", &rest))) {
        	argList[numArgs] = word;
        	numArgs++;
    	}

    	//This handles $$
    	for(int i = 0; i < numArgs; i++) {
        	for(int j = 0; j < strlen(argList[i]); j++){ //Locate the $$
            	if(argList[i][j] == '$' && argList[i][j+1] == '$'){
                	argList[i][j] = '\0'; //Replace the first $ with NULL
                	argList[i][j+1] = '\0'; //Replace the second $ with NULL

                	sprintf(buff, "%s%d", argList[i], getpid()); //Add the correct output to the buffer

                	argList[i] = buff;
            	}
        	}
    	}

    	return numArgs; //Return numArgs
}

/*
 *   Runs the program
*/
int main (){
    	int numArgs = 0;
    	int stats;
    	char readArgs[2048];
    	bool foreground = true;

    	//Setting up all of the signal related requirements
    	//This code is taken from the Signal Handling API Exploration
    	SIGTSTP_action.sa_handler = catch_SIGTSTP;
    	sigfillset(&SIGTSTP_action.sa_mask);
    	sigaction(SIGTSTP, &SIGTSTP_action, NULL);
    	SIGINT_action.sa_handler=SIG_IGN; //Ignoring control C from the very beginning
    	sigfillset(&SIGINT_action.sa_mask); //Using mask to intitialize and fill the signal set
    	sigaction(SIGINT, &SIGINT_action, NULL);

    	for(;;) { //For loop that runs forever, makes sure prompting never stops
        	numArgs = argParse(readArgs); //Get numArgs and the argList
        	argList[numArgs] = NULL; //Set the last to NULL just for insurance
        	commandCall(numArgs, stats, foreground); //Begin running the commands the user entered
        	fflush(stdout);
    	}

    return EXIT_SUCCESS;
}

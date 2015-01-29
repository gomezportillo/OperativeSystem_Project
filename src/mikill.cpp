#include <stdio.h>
#include <signal.h> /* signal() */
#include <unistd.h> /* _exit() */
#include <stdlib.h> /* EXIT_FAILURE, EXIT_SUCCESS */

/* Send a signal to a proccess	e.g. mikill signal process*/ 

int main(int argc, char *argv[]){
	
	if (argc != 3 ){ 	/*Basic error handling*/
		fprintf(stderr, "Error in number of arguments\n"); 
		_exit(EXIT_FAILURE);
	} 
	
	int signal = atoi(argv[1]), //signal to send
		pid_proccess = 	atoi(argv[2]); //proccess to receive the signal
			
	if(pid_proccess == 1){ //n00b
		printf("Cannot send message to init proccess\n");
		_exit(EXIT_FAILURE);
	}
			
	if (kill(pid_proccess, signal) != 0 ) { 
		fprintf(stderr, "Error in execution of kill\n"); 
		_exit(EXIT_FAILURE);
	}
	else
		printf("Success sending signal %d to pid %d", signal, pid_proccess);	
	
	return EXIT_SUCCESS;

}

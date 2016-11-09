#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/* Print each n seconds a message */

int counter = 0;	// number of alarms called

void print_message(int signal){ 	//argument necessary but never used
	printf("Alarma %d\n", ++counter);
}

int main(int argc, char *argv[]){

	if (argc != 2 ){ /*Basic error handling*/
		fprintf(stderr, "Error in number of arguments\n");
		_exit(EXIT_FAILURE); }

	int n_sec;

	if((n_sec= atoi(argv[1])) <= 0){  	//the number of waiting seconds
		fprintf(stderr,"Invalid number of sec\n");
		_exit(EXIT_FAILURE);
	}

	if (signal(SIGALRM, print_message) == SIG_ERR){
		fprintf(stderr,"Error caughting the alarm\n");
		_exit(EXIT_FAILURE);
	}

	while(1){ //throwing the alarm and pausing the program
		alarm(n_sec);
		pause();	//waked up when any signal is recived
	}

	_exit(EXIT_SUCCESS); //the program will nevah reach this point

}

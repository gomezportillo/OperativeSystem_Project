#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/* Print the signat recived if it equals the one passed though the arguments and continue the program*/

void my_handler(int signal){
	printf("\nRecibida la señal %d\n", signal);
}

int main(int argc, char *argv[]){

	if (argc != 2 ){	/*Basic error handling*/
		fprintf(stderr, "Error in number of arguments\n");
		_exit(EXIT_FAILURE);
	}

	if (signal(atoi(argv[1]), my_handler) == SIG_ERR){
		fprintf(stderr,"Error in handling the signal\n");
		_exit(EXIT_FAILURE); 
	}

	while(1); /** Do nothing*/

	return EXIT_SUCCESS;

}

/*
http://en.wikipedia.org/wiki/Unix_signal#POSIX_signals

SIGINT   2   ctrl+C
SIGTERM  15
SIGKILL  9
SIGTSTP  20  ctrl+z
SIGALRM  14
*/

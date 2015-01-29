#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/* If the recived signal equals the one passed through args it is ignored*/

int main(int argc, char *argv[]){
	
	if (argc != 2 ){ /*Basic error handling*/
		fprintf(stderr, "Error in number of arguments\n"); 
		return EXIT_FAILURE; 
	} 
	
	if(signal(atoi(argv[1]), SIG_IGN) == SIG_ERR){
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

Webgraphy
man signal
https://airtower.wordpress.com/2010/06/16/catch-sigterm-exit-gracefully/

top > pid del proceso > Terminated
*/
	

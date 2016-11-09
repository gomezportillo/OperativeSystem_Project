#include <sys/types.h> /* pid_t */
#include <sys/wait.h>  /* waitpid */
#include <stdio.h>     /* printf */
#include <stdlib.h>    /* exit */
#include <unistd.h>    /* read() write() _exit()*/
#include <signal.h>	   /* signal */
#include <fcntl.h>	   /* open() */

#define MAXBUFFER 4096

/* consumidor <tuberia> 	reads everything in the pipe */

int main(int argc, char *argv[]){

	if (argc != 2 ){ /*Basic error handling*/
		fprintf(stderr, "Error in number of arguments\n");
		return EXIT_FAILURE; //eror in _exit  was not declared in this scope (but it is!)
	}

	int pipefd, n_read_char;
	char buffer[MAXBUFFER];

	if ((pipefd = open(argv[1], O_RDONLY)) == -1) { //opening the pipe
		fprintf(stderr, "Error opening pipe %s", argv[1]);
		return EXIT_FAILURE;
	}

	while(1){ /* Infinite loop for reading the pipe */
		if((n_read_char = (read(pipefd,buffer,sizeof(buffer)))) != 0 ){
			if(n_read_char != write(STDIN_FILENO,buffer, n_read_char)) {
				fprintf(stderr, "Error in writing pipe %s in stdin", argv[1]);
				return EXIT_FAILURE;
			}
		}
		else{
			buffer[0] = '\0';
		}
		sleep(1); /*waiting for retake the loop as it is asked*/
	}

	return EXIT_SUCCESS;
}

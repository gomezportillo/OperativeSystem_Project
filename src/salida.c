#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/* Execute the proccess in argv[2] emulating the stdout with the file in the argv[1] */

int main(int argc, char *argv[]){

	if (argc < 3 ){  /*Basic error handling*/
		fprintf(stderr, "Error in number of arguments\n");
		_exit(EXIT_FAILURE);
	}

	int fd;
	if ((fd = open(argv[1], O_WRONLY)) == -1){ //opening the file
		fprintf(stderr, "Error opening file %s\n", argv[1]);
		_exit(EXIT_FAILURE);
	}

	close(STDOUT_FILENO); //closing stdout
	dup(fd); //dup will asing to fd the lowest file descriptor available (the one of stdout)
	
	if(execvp(argv[2], argv + 2) == -1){
		fprintf(stderr,"Error executing the program\n");
		_exit(EXIT_FAILURE);
	}


	return EXIT_SUCCESS;

}

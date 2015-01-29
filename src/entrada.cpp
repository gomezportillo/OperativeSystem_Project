#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/* Execute the proccess in argv[2] with the args in argv[2+n] emulating the stdin with the file in the argv[1] */ 

int main(int argc, char *argv[]){
	
	if (argc < 3){ 	/*Basic error handling*/
		fprintf(stderr, "Error in number of arguments\n"); 
		_exit(EXIT_FAILURE); 
	} 
	
	close(STDIN_FILENO); //closing stdin
	
	int fd;
	if ((fd = open(argv[1], O_RDONLY)) == -1){ //as we have just close stdin fd open will autom assing the new file the lowest fd available
		fprintf(stderr, "Error opening file %s\n", argv[1]); 
		_exit(EXIT_FAILURE); 
	} 
	
	/* Another way to do so
	int fd = open(argv[1], O_RDONLY); 
	close(0);
	dup(fd);
	close(fd);
	*/
	
	if(execvp(argv[2], argv + 2) != 0){
		fprintf(stderr,"Error executing the program\n");
   		_exit(EXIT_FAILURE); 
	}
	
	close(fd);
	
	return EXIT_SUCCESS;
}

/*
*	stdin 0
*	stdout 1
*/

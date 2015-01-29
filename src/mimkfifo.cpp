#include <stdio.h>
#include <stdlib.h> /* EXIT_FAILURE, EXIT_SUCCESS */
#include <sys/stat.h> /* mkfifo() */
#include <unistd.h> /* _exit() */

/* mikill <signal> <process>. send a signal to a proccess*/ 

int main(int argc, char *argv[]){
	
	if (argc != 3 ){ /*Basic error handling*/
		fprintf(stderr, "Error in number of arguments\n"); 
		_exit(EXIT_FAILURE);
	} 
	
	mode_t permissions;
	
	if(sscanf(argv[1], "%o", &permissions) != 0){
		fprintf(stderr,"Error argument #1 permissions \n");
    	_exit(EXIT_FAILURE);
    }
	
	if(mkfifo(argv[2], permissions) != 0){
		fprintf(stderr,"Error creating the pipe\n");
		_exit(EXIT_FAILURE);
  	}
	
	return EXIT_SUCCESS;

}

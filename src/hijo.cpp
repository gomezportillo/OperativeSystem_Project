#include <stdio.h>
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS srand() rand() */
#include <sys/types.h> /* getpid() */
#include <unistd.h> /* getpid() */
#include <time.h> /* time() */

int main(int argc, char *argv[]){
	
	/* Program executed by padre.exe */
	/* No error in number of args handler needed */
	
	/* Intializes random number generator */ //http://www.tutorialspoint.com/c_standard_library/c_function_srand.htm
	time_t t;
	srand((unsigned) time(&t));

	int rand_sec = 1 + (rand() % atoi(argv[1]));

	printf("[Proceso %d] duerme %d segundos\n", getpid(), rand_sec);

	sleep(rand_sec); 
	
	printf("[Proceso %d] finaliza\n",getpid());

  	return EXIT_SUCCESS;
}

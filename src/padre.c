#include <stdio.h>
#include <stdlib.h> /* srand() rand() */
#include <unistd.h> /* _exit() fork() execlp() getpid() sleep() */
#include <sys/types.h> /* getpid() kill() */
#include <signal.h> /* signal()  */
#include <sys/wait.h> /* wait() */

#define PROC_NUMB 3 //number of proccess to be created

pid_t children_pid[PROC_NUMB]; //this matrix will allow us to kill all the chill proccessess when ctrl+C signal is recieved

void killChildProccesses(int signum);

int main(int argc, char *argv[]){

	if (argc != 2 ){ 	/*Basic error handling*/
		fprintf(stderr, "[Proceso padre] Error in number of arguments\n");
		_exit(EXIT_FAILURE);
	}

	int i;
	pid_t child_pid;

	for(i = 0; i < PROC_NUMB; i++) children_pid[i] = 0; /* matrix initialization */

	if(signal(SIGINT,killChildProccesses) == SIG_ERR){ /* Ctrl+C handler */
		fprintf(stderr,"[Proceso padre] Error in handling Ctrl+C\n");
		_exit(EXIT_FAILURE);
	}

	for(i = 0; i < PROC_NUMB; i++){ //exec all the child proccesses

		switch(child_pid = fork()){

			case -1:
			fprintf(stderr,"[Proceso padre] Error in fork()\n");
			_exit(EXIT_FAILURE);
			break;

			case 0: //the program is though to be executed while being in proyect root directory
			if(execl("exe/hijo", "hijo", argv[1], (char *)0) != 0)	// run the program
			if(execl("hijo", "hijo", argv[1], (char *)0) != 0){	//just in case we are in exec/ directory
				fprintf(stderr,"[Proceso padre] Error in child execution\n");
				_exit(EXIT_FAILURE);
			}
			break;

			default:
			children_pid[i] = child_pid; //save its pid in case we have to kill our own child
			break;
		}
	}


	while((child_pid = wait(NULL)) != -1){ //wait until any child proccess ends and returns it pid
		printf("[Proceso padre] el proceso %d ha terminado\n", child_pid);
	}

	printf("[Proceso padre] finaliza\n");
	return EXIT_SUCCESS;
}


void killChildProccesses(int signum){
	int i;

	for(i= 0; i < PROC_NUMB; i++){ //go through the matrix
		if(children_pid[i] != 0){ //if the slot has a valid pid
			if(kill(children_pid[i],SIGINT) != 0){ //sending signal & error handling
				fprintf(stderr,"[Proceso padre] Error killing child proccess %d\n",children_pid[i]);
				_exit(EXIT_FAILURE);
			}
			printf("[Proceso padre] killed child proccess with pid %d \n",children_pid[i]);
			children_pid[i] = 0; //rm its pid from the matrix
		}
	}

	printf("[Proceso padre] finaliza\n");

	_exit(EXIT_FAILURE);
}

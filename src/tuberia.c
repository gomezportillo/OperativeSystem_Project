#include <sys/types.h> /* pid_t() */
#include <sys/wait.h>  /* wait() */
#include <stdio.h>     /* printf() */
#include <stdlib.h>    /* exit() */
#include <unistd.h>    /* _exit(), fork() */
#include <signal.h>	   /* signal() */

/* tuberia <prog1> <prog2> runs prog2 emulating its stdin with the prog1 stdout */

void runSource(int pfd[], char *prog1);
void runDestination(int pfd[], char *prog2);

int main(int argc, char *argv[]) {

	if (argc != 3 ){ /*Basic error handling*/
		fprintf(stderr, "Error in number of arguments\n");
		_exit(EXIT_FAILURE);
	}

	pid_t pid; //save the pid of the children

	int pipefd[2];
	pipe(pipefd); /* Whatever is written in fd[1] will be read from fd[0] */
	
	runSource(pipefd, argv[1]); //run the first program
	runDestination(pipefd, argv[2]); //run the second program

	close(pipefd[0]);
	close(pipefd[1]); 	/*close both file descriptors on the pipe */

	while ((pid = wait(NULL)) != -1)	{/* wait until any child proccess ends */
		printf("Process %d ends\n", pid);
	}

	return EXIT_SUCCESS;
}


void runSource(int pipefd[], char *prog1)	{	/* run the first program */

	switch (fork()) {

		case 0: /* child */
		close(STDOUT_FILENO);
		dup(pipefd[1]);			/* this end of the pipe becomes stdout */
		close(pipefd[0]); 		/* this process does not need the other end */
		execlp(prog1, prog1, (char *)NULL);	/* run the program */
		break;

		default: break; /* parent does nothing */

		case -1:
		fprintf(stderr,"Error in fork()\n");
		exit(EXIT_FAILURE);
		break;
	}
}

void runDestination(int pipefd[], char *prog2) {	/* run the second program */

	switch (fork()) {

		case 0: /* child */
		close(STDIN_FILENO);
		dup(pipefd[0]);			/* this end of the pipe becomes stdin */
		close(pipefd[1]);		/* this process does not need the other end */
		execlp(prog2, prog2, (char *)NULL);	/* run the program */
		break;

		default: break; /* parent does nothing */

		case -1:
		fprintf(stderr,"Error in fork()\n");
		exit(EXIT_FAILURE);
		break;
	}
}

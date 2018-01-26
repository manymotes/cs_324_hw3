#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {

     char *newenviron[] = { NULL };
     int child_status;
     char str[60];


	if (argc <= 2) {
		printf("No program to exec.  Exiting...\n");
		exit(0);
	}

    printf("Running exec of \"%s\"\n", argv[1]);
	//execve(argv[1], &argv[1], newenviron);
	printf("End of program \"%s\".\n", argv[2]);
	


	int  fd[2];
     pipe(fd);



     if (fork() == 0) {
		printf("HC: hello from the child\n");
		exit(0);
	}
	else
	{
		


		printf("HP: hellp from parent\n");
		wait(&child_status);
		printf("CT: child has terminated\n");
	}


	//pipe stuff
		close(fd[0]);
		//FILE* writer = fdopen( fd[1], "w+");
		write(fd[1], "hello", strlen("hello"));
		//fputs( "hello", writer);


		close(fd[1]);


	//parent stout to child stdin
	close(fd[1]);
		FILE* reader = fdopen(fd[0],"r");
		fgets( str, 60, reader);
		//puts(str);
		fprintf(stdout, "%s\n", str);
		close(fd[0]);
		exit(0);


}

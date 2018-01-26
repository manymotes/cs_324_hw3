#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>



#include <string.h>


int main(int argc, char *argv[]) {
	int pid;
	signal(SIGCHLD, SIG_IGN);
	const char *text = "";
	char str[60];
	//char empty[60];

	printf("Starting program; process has pid %d\n", getpid());
	FILE *f = fopen("fork-output.txt","w");
	fprintf(f, "BEFORE FORK %s\n", text);

	int     fd[2];
                
                pipe(fd);

//In section B: close the file descriptor corresponding to the reader end of the pipe  clos index 0

//create a stream using the file descriptor corresponding to the writer end of the pipe (see man fdopen)  fdope(fd[1],"w")  lookup second

//and write ("hello from Section B") to the newly opened stream (see man fputs)   fputs(fd[1], "hello"); 


	if ((pid = fork()) < 0) {
		fprintf(stderr, "Could not fork()");
fclose(f);
		exit(1);
	}

	/* BEGIN SECTION A */
	fprintf(f, "SECTION A %s\n", text);
	//fprintf(stdout, "SECTION chnager %s\n", empty);
	printf("Section A;  pid %d\n", getpid());
	//sleep(30);

	/* END SECTION A */
	if (pid == 0) {
		/* BEGIN SECTION B */
		fprintf(f, "SECTION B %s\n", text);
		printf("Section B\n");
		//sleep(30);
		//sleep(30);
		printf("Section B done sleeping\n");

		//pipe stuff
		close(fd[0]);
		//FILE* writer = fdopen( fd[1], "w");
		write(fd[1], "hello", strlen("hello"));
		//fputs( "hello", writer);


		close(fd[1]);
		int fwd = fileno( f );
		dup2(1, fwd);

		//exec

		char *newenviron[] = { NULL };

	printf("Program \"%s\" has pid %d. Sleeping.\n", argv[0], getpid());
	//sleep(30);

	if (argc <= 1) {
		printf("No program to exec.  Exiting...\n");
		exit(0);
	}

	printf("Running exec of \"%s\"\n", argv[1]);
	execve(argv[1], &argv[1], newenviron);
	printf("End of program \"%s\".\n", argv[0]);
		exit(0);

		/* END SECTION B */
	} else {
		/* BEGIN SECTION C */
		fprintf(f, "SECTION C %s\n", text);
		printf("Section C\n");
		//sleep(30);
		//sleep(30);
		printf("Section C done sleeping\n");

		//pipe stuff
		close(fd[1]);
		//FILE* reader = fdopen(fd[0],"r");
		fgets( str, 60, reader);
		//puts(str);
		//fprintf(stdout, "%s\n", str);
		close(fd[0]);
		exit(0);

		/* END SECTION C */
	}
	/* BEGIN SECTION D */
	fprintf(f, "SECTION D %s\n", text);
fclose(f);
	printf("Section D\n");
	//sleep(30);

	/* END SECTION D */
}

// execve stops the current process. Good for fork. I can fork parent process to run a child process. then i can call execve in the child process to stop it. 

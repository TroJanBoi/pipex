# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>


int main(void)
{

	pid_t pid1 = fork();
	if(pid1 == 0)
	{
		printf("i'm pid 1");
		sleep(2);
		exit(0);
	}

	pid_t pid2 = fork();
	if(pid2 == 0)
	{
		printf("i'm pid 2");
		sleep(2);
		exit(0);
	}

	wait(NULL);
	printf("i'm parent wait finish");


}
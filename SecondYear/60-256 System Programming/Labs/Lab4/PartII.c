//SystemProgramming
//Lab4 - Part II
//Marcus Toldo
//Wednesday, October 18, 2017

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *args[]) {

	int number = atoi(args[1]);

	if (number < 0 || number > 10) {
		return -1;
	}

	pid_t pid = fork();

	if (pid != 0) {

		int fd =  open("data.dat", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);

		write(fd, args[1], sizeof(args[1]));


	} else if (pid == 0) {

		sleep(1);

		int pd1 = open("data.dat", O_RDONLY);
		char hold[2];
		int pd2 = read(pd1, hold, 2);

		int num = atoi(hold);	
		int factorial = 1;

		for (int i = 1; i < num+1; i++) {

			factorial *= i;

		}

		printf("\n\n%d\n\n", factorial);
	}

	return 0;

}

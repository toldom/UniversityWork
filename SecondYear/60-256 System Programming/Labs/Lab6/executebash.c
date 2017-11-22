//System Programming
//Lab 6
//Marcus Toldo
//Wendesday, November 1, 2017

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	printf("EXAM! EXAM! EXAM!\n");

	if (fork() == 0) {

		char *command[] = {"./mybash.sh", NULL};
		execv(command[0], command);

	}

	return 0;
}

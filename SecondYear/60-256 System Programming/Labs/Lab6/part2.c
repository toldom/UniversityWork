//System Programming
//Lab 6 Part 2
//Marcus Toldo
//Wednesday, November 1, 2017

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	for (int i = 1; i < argc; i+= 2) {

        if (fork() == 0) {
            sleep(i);
            printf("\nPricess ID is: %d\n", getpid());
            execlp(argv[i], argv[i], argv[i+1], NULL);
            printf("ERROR");
            exit(0);
        }
	}
	return 0;
}

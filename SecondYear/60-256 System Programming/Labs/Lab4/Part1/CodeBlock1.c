//Lab4, Part I, Code 1

#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

int main() {
	fork();
	fork();
	fork();
	printf("%d\n", getpid());
}

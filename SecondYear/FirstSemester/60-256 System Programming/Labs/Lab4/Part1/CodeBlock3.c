//Lab 4, Part I, Block 3

#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>

int main() {
	if (fork() == 0) 
		fork();
	else { 	
		fork();
		fork();
	 }
	printf("%d\n", getpid()); 
}

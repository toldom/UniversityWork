//System Programming
//Lab 2 - writer2.c
//Marcus Toldo
//Wednesday, September 27, 2017

#include <fcntl.h>
#include <unistd.h>

int main(void) {

	int file = open("list2.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);

	char line[] = "GM\t101   Buick\t2010\nFord\t102   Lincoln\t2005";

	write(file, line, 43);

	close(file);

	return 0;

}

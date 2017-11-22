//System Programming
//Lab Assignment 2 - writer.c
//Marcus Toldo
//Monday, September 25, 2017

//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(void) {

	int file = open("list1.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);

	char line0[] = "101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005";

	write(file, line0, 43);

	close(file);


	return 0;
}

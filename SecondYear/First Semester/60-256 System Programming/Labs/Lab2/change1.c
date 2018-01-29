//System Programming
//Lab 2 - change2.c
//Marcus Toldo
//Wednesday, September 27, 2017

#include <fcntl.h>
#include <unistd.h>

int main(void) {

        int file = open("list1.txt", O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR); 
	
	int int101 = 101;

	write(file, &int101, 3);

	close(file);

	return 0;

}

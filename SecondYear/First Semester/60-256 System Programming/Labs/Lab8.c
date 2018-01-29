//System Programming
//Lab8
//Marcus Toldo
//Wednesday, November 15, 2017

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int fd[2];
    pipe(fd);
    
    if (fork() == 0) {
        //Child
        
        close(fd[0]);
        
        dup2(fd[1], 1);
        dup2(fd[1], 2);
        execlp(argv[1], argv[1], NULL);
        
    } else {
        
        //Parent
        char buffer[2048];
        close(fd[1]);
        
        int n = 0;
        while(read(fd[0], &buffer, sizeof(buffer)) != 0){
            //empty
        }
        
        while (buffer[n] != '\0') {
            n++;
        }
        
        int fd1 = open("result.txt", O_CREAT | O_RDWR | O_TRUNC, S_IXUSR | S_IRUSR | S_IWUSR);
        write(fd1, &buffer, n);
        printf("\nThe result of %s has been written into result.txt with %d total bytes\n", argv[1], n);
        
    }



	return 0;
}

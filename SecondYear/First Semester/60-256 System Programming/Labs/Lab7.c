///SystemProgramming
///Lab7
///Marcus Toldo
///Wednesday, Novemner 8, 2017

#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void MyAlarmHandler(int meirl);

int main(int argc, char *argv[]) {

    char *buf[3];
    pid_t pid;
    
    buf[0] = "EXAM! EXAM! EXAM!\n";
    buf[1] = "HELP! HELP! HELP!\n";
    buf[2] = "STUDY! STUDY! STUDY!\n";

	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
    printf("Parent opened the file: %s\n", argv[1]);
    
    if ((pid = fork()) > 0) {
        //this is the child process
        signal(SIGALRM, MyAlarmHandler);
        pause();
        write(fd, buf[1], 18);
        printf("Child process %d has written to the file: %s\n", getpid(), buf[1]);
        
    } else {
        //this is the first child process
        
        printf("Parent created child process: %d\n", getpid());
        write(fd, buf[0], 18);
        printf("Child process %d has written to the file: %s\n", getpid(), buf[0]);
        sleep(5);
        
        if (fork() == 0) {
            
            //this is the second child process
            printf("Parent created child process: %d\n", getpid());
            write(fd, buf[2], 21);
            sleep(5);
            printf("Parent process has written to the file %s\n", buf[2]);
            kill(pid, SIGALRM);
        }
        
    }
    
    
    
    
	return 0;
}

void MyAlarmHandler(int mairl) {
    
    static int n = 0;
    
    if (n++ < 3) {
        alarm(3);
    } else {
        exit(0);
    }
    
}

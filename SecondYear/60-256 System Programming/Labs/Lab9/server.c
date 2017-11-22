//SystemProgramming
//Lab9
//Marcus Toldo
//Wednesday, November 22, 2017

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <signal.h>

int main(int argc, char * argv[]) {

    int fd1, fd2;
    int writeBlanks = 1;
    pid_t pid;
    char ch;

    char waitingStr[] = "Waiting for connection ... ... ...\n\n";
    char headerStr[] = "my messages (server)                received messages (client)\n";
    char lineSpaceStr[] = "---------------------------------------------------------------\n";
    char blanks[] = "                                                      |";
    char clientLeftStr[] = "The client has left\n";

    unlink("./fifo1");
    unlink("./fifo2");

    if (mkfifo("./fifo1", 0777) || mkfifo("./fifo2", 0777)) {
        perror("fifo");
        exit(1);
    }

    while (true) {

        printf("%s", waitingStr);
        fd1 = open("./fifo1", O_RDONLY);
        fd2 = open("./fifo2", O_WRONLY);
        printf("%s", headerStr);
        printf("%s", lineSpaceStr);

        if ((pid = fork()) == -1) {
            perror("fork");
            exit(1);
        }

        if (pid == 0) {
            while (1) {

                ch = getchar();
                write(fd2, &ch, 1);
            }
        }

            while (read(fd1, &ch, 1) == 1) {
                if (writeBlanks == 1) {
                    write(1, blanks, sizeof(blanks));
                }

                write(1, &ch, 1);
                writeBlanks = 0;

                if (ch == '\n') {
                    writeBlanks = 1;
                }


                //Code

            }

        close(fd1);
        close(fd2);
        printf("%s", clientLeftStr);
        kill(pid, SIGTERM);

    }

}

//
//SystemProgramming
//Assignment5
//Marcus Toldo
//Sunday, November 26, 2017
//

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>

int main(int argc, char * argv[]) {

    //Declaring variables
    int welcomeSocket, clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addressSize;

     welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);

    //Can probably be PF_INET
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7777);
    serverAddr.sin_addr.s_addr = inet_addr("192.168.1.73");
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    bind(welcomeSocket, (const struct sockaddr *) &serverAddr, sizeof(serverAddr));

    while (1) {
        if (listen(welcomeSocket, 5) == 0) {
            printf("Waiting for connection from client ... ... ...\n");
        } else {
            printf("Error\n");
        }

        addressSize = sizeof(serverStorage);
        clientSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addressSize);

        printf("\nConnection established!\n\n");

        strcpy(buffer, "Hello world!\n");
        send(clientSocket, buffer, 13, 0);

        while (1) {

            char buffer2[2048];

            int fd = creat("temp.txt", S_IRUSR | S_IWUSR | S_IXUSR);
            dup2(fd, 1);
            //close(fd);

            recv(clientSocket, buffer, sizeof(buffer), 0);
            printf("\nReceived Command: %s\n", buffer);
            if (fork() == 0) {
                //printf("%s",buffer);
                //strcat(buffer, " > temp.txt");
                //printf("%s",buffer);
                execlp(buffer, buffer, (char *) 0);
                exit(0);

            } else {
                read(fd, buffer2, 2048);
                printf("%s", buffer2);
            }




        }

    }

    return 0;
}
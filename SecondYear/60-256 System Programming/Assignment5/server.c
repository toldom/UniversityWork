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

    if (listen(welcomeSocket, 5) == 0) {
        printf("Waiting for connection from client ... ... ...\n");
    } else {
        printf("Error\n");
    }

    addressSize = sizeof(serverStorage);
    clientSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addressSize);

    strcpy(buffer, "Hello world!\n");
    send(clientSocket, buffer, 13, 0);

    return 0;
}
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

    int clientSocket, serverSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addrSize;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7777);
    serverAddr.sin_addr.s_addr = inet_addr("192.168.1.73");

    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    bind(clientSocket, (const struct sockaddr *) &serverAddr, sizeof(serverAddr));

    addrSize = sizeof(serverAddr);
    connect(clientSocket, (struct sockaddr *) &serverAddr, addrSize);

    char command[1024];



    while (1){

        scanf("%s", command);




        break;
    }


    recv(clientSocket, buffer, 1024, 0);

    printf("Data received: %s", buffer);

    serverSocket = accept(clientSocket, (struct sockaddr *) &command, &addrSize);

    send(clientSocket, "TESTING", 1024, 0);

    return 0;
}
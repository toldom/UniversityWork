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
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    bind(clientSocket, (const struct sockaddr *) &serverAddr, sizeof(serverAddr));

    addrSize = sizeof(serverAddr);
    connect(clientSocket, (struct sockaddr *) &serverAddr, addrSize);

    /*recv(clientSocket, buffer, 1024, 0);
    printf("%s", buffer);*/

    char command[1024];
    char buffer2[2048];

    serverSocket = accept(clientSocket, (struct sockaddr *) &command, &addrSize);

    while (1) {

        scanf("%s", command);
        send(clientSocket, command, sizeof(command), 0);

       //recv(clientSocket, buffer2, sizeof(buffer2), 0);
    }

    exit(0);

    return 0;
}
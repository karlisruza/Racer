
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include "../server.h"
#define PORT 8058
#define _MAX_LISTEN_QUEUE 10

Server::Server(){
    this->playerlist = new PlayerList();
    this->gamelist = new GameList();
    this->Listen();
}
int Server::Listen(){
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("tcp socket error");
        return -1;
    }
    //set protocol to ipv4 and set port
    struct sockaddr_in myAddr;
    memset(&myAddr, 0, sizeof(struct sockaddr_in));
    myAddr.sin_family = AF_INET;
    myAddr.sin_port = htons(PORT); //htons converts to network byte order
    //bind address to socket
    if (bind(fd, (struct sockaddr *) &myAddr, sizeof(struct sockaddr_in)) == -1) {
        perror("tcp bind");
        return -1;
    }
    //set socket to listen
    if (listen(fd, _MAX_LISTEN_QUEUE) == -1) {
        perror("listen");
        return -1;
    }
    this->setFd(fd);
    printf("Listening on port %d \n", PORT);
    return 0;
}
void Server::handleRequest(){
    while(true){
        printf("thread running");
    }
}
int Server::handleConnection(){
    while(true){
        struct sockaddr_in peerAddr;
	    socklen_t addrSize = sizeof(peerAddr);
	    int clientFd = accept(this->getFd(), (struct sockaddr *) &peerAddr, &addrSize);
        if (clientFd == -1) {
            perror("accept");
            return -1;
        }
        // printClient(clientFd);
        Player* player = new Player();
        player->setId(clientFd);
        this->getPlayerList()->push(player);

        std::thread thread(&Server::handleRequest, *this);
    }
}
void Server::setFd(int fd){
    this->fd = fd;
}
int Server::getFd(){
    return this->fd;
}
GameList* Server::getGameList(){
    return this->gamelist;
}
PlayerList* Server::getPlayerList(){
    return this->playerlist;
}



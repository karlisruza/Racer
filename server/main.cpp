#include "./core/server.h"
int main(void){
    Server* server = new Server();
    server->handleConnection();
    return 0;
}
#include "../../data/game/game.h"
class Server{
    int fd;
    GameList* gamelist;
    PlayerList* playerlist;
    void Listen();
    void Server::handleRequest()
    void setFd(int fd);
    int getFd();
    GameList* getGameList();
    PlayerList* getPlayerList();
public:
    Server();
    void handleConnection();
};
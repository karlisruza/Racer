#include "../../data/game/game.h"
class Server{
    int fd;
    GameList* gamelist;
    PlayerList* playerlist;
    int Listen();
    void handleRequest();
    void setFd(int fd);
    int getFd();
    GameList* getGameList();
    PlayerList* getPlayerList();
public:
    Server();
    int handleConnection();
};
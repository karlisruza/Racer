#include "../player/player.h"
//Game data
class Game{           
    int id;
    int status; //(0- WAITING_PLAYERS, 1- STARTED, -1- ENDED);
    int hostid; //id of the player
    PlayerList* playerlist;
    class Game* next; //next and prev for gamelist data structure;
    class Game* prev;
public:
    Game();
    void setId(int gameid);
    void setStatus(int status);
    void setHostId(int hostid);
    void setNext(class Game* next);
    void setPrev(class Game* prev);
    int getId();
    int getStatus();
    int getHostId();
    class Game* getNext();
    class Game* getPrev();
    void print();
};

//Two way linked list
class GameList{           
    int count;
    Game* head;
    Game* tail;
    void setHead(Game* game);
    void setTail(Game* game);
    void setCount(int count);
    Game* getHead();
    Game* getTail();
    int getCount();
public:
    GameList();
    void push(Game* game);
    void deleteGame(int gameId);
    void deleteGameList();
    void print();
    void printGameById(int id);
    void testData();
};
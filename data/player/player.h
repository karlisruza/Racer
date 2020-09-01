class Player{
    int id;
    int gameid;
    char* name;
    float x; //position x
    float y; //position y
    float angle; //travel angle
    float speed; //current speed
    float acceleration; //current acceleration
    int laps; //laps finished
    Player* next;
    Player* prev;
public:
    void setId(int playerid);
    void setGameId(int gameid);
    void setName(char* name);
    void setX(float x);
    void setY(float y);
    void setAngle(float angle);
    void setSpeed(float speed);
    void setAcceleration(float a);
    void setLaps(int laps);
    void setNext(class Player* next);
    void setPrev(class Player* prev);
    int getId();
    int getGameId();
    char* getName();
    float getX();
    float getY();
    float getAngle();
    float getSpeed();
    float getAcceleration();
    int getLaps();
    Player* getNext();
    Player* getPrev();
    void print();
};
class PlayerList{
    int count;
    Player* head;
    Player* tail;
    //getter setter functions
    void setHead(Player* player);
    void setTail(Player* player);
    void setCount(int count);
    Player* getHead();
    Player* getTail();
    int getCount();
public:
    PlayerList();
    void print();
    void push(Player* player);
    void removePlayer(int playerId);
    void deletePlayer(int playerId);
    char* getPlayerName(int clientFd);
    void deletePlayerList();
    //function fills list with data for testing purposes;
    void testData();
};
#include <stdlib.h>
#include "../player.h"

PlayerList::PlayerList(){
    this->count = 0;
    this->head = NULL;
    this->tail = NULL;
}
void PlayerList::setHead(Player* game){
    this->head = game;
} 
void PlayerList::setTail(Player* game){
    this->tail = game;
}
void PlayerList::setCount(int count){
    this->count = count;
}
Player* PlayerList::getHead(){
    return this->head;
}
Player* PlayerList::getTail(){
    return this->tail;
}
int PlayerList::getCount(){
    return this->count;
}
void PlayerList::print(){
    Player* current = this->getHead();
    while(current != nullptr){
        current->print();
        current = current->getNext();
    }
    return;
}
void PlayerList::push(Player* player){
    if(this->getHead() == nullptr && this->getTail() == nullptr){
        this->setHead(player);
        this->setTail(player);
        this->setCount(this->getCount() + 1);
    }
    else{
        this->getTail()->setNext(player);
        player->setPrev(this->getTail());
        this->setTail(player);
        this->setCount(this->getCount() + 1);
    }
    return;
}
void PlayerList::removePlayer(int playerId){
    Player* current = this->getHead();
    while(current != nullptr){
        if(current->getId() == playerId){
            if(current == this->getHead() && current == this->getTail()){
                this->setHead(nullptr);
                this->setTail(nullptr);
                this->setCount(this->getCount() - 1);
            }
            else if(current == this->getHead()){
                this->setHead(this->getHead()->getNext());
                this->getHead()->setPrev(nullptr);
                current->setNext(nullptr);
                current->setPrev(nullptr);
                this->setCount(this->getCount() - 1);
            }
            else if(current == this->getTail()){
                this->setTail(this->getTail()->getPrev());
                this->getTail()->setNext(nullptr);
                current->setNext(nullptr);
                current->setPrev(nullptr);
                this->setCount(this->getCount() - 1);
            }
            else{
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
                current->setNext(nullptr);
                current->setPrev(nullptr);
                this->setCount(this->getCount() - 1);
            }
            return;    
        }
        current = current->getNext();
    }
    return;
}
void PlayerList::deletePlayer(int playerId){
    Player* current = this->getTail();
    while(current != nullptr){
        if(current->getId() == playerId){
            if(current == this->getHead() && current == this->getTail()){
                this->setHead(nullptr);
                this->setTail(nullptr);
                current->setNext(nullptr);
                current->setPrev(nullptr);
                this->setCount(this->getCount() - 1);
                free(current);
            }
            else if(current == this->getHead()){
                this->setHead(this->getHead()->getNext());
                this->getHead()->setPrev(nullptr);
                this->setCount(this->getCount() - 1);
                free(current);
            }
            else if(current == this->getTail()){
                this->setTail(this->getTail()->getPrev());
                this->getTail()->setNext(nullptr);
                this->setCount(this->getCount() - 1);
                free(current);
            }
            else{
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
                this->setCount(this->getCount() - 1);
                free(current);
            }
            return;    
        }
        current = current->getNext();
    }
    return;
}
char* PlayerList::getPlayerName(int clientFd){
    Player* current = this->getHead();
    while(current != nullptr){
        if(current->getId() == clientFd){
            return current->getName();
        }
    }
    return nullptr;
}
void PlayerList::deletePlayerList(){
    Player* temp1;
    Player* temp2;
    if(this->getHead() == this->getTail()){
        free(this->getHead());
        this->setHead(nullptr);
        this->setTail(nullptr);
        this->setCount(0);
        return;
    }
    else{
        temp1 = this->getHead();
        temp2 = this->getHead()->getNext();
        while(temp1 != nullptr){
            if(temp1 == this->getTail()){
                free(temp1);
                this->setHead(nullptr);
                this->setTail(nullptr);
                this->setCount(0);
                return;
            }
            free(temp1);
            temp1 = temp2;
            temp2 = temp2->getNext();
        }
    }
    return;
}
void PlayerList::testData(){
    Player* player1 = new Player();
    player1->setId(1);

    Player* player2 = new Player();
    player2->setId(2);

    Player* player3 = new Player();
    player3->setId(3);

    Player* player4 = new Player();
    player4->setId(4);

    this->push(player1);
    this->push(player2);
    this->push(player3);
    this->push(player4);
}
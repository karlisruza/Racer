#include <stdio.h>
#include <stdlib.h>
#include "../game.h"

GameList::GameList(){
    this->count = 0;
    this->head = NULL;
    this->tail = NULL;
}
//getter setter functions
void GameList::setHead(Game* game){
    this->head = game;
} 
void GameList::setTail(Game* game){
    this->tail = game;
}
void GameList::setCount(int count){
    this->count = count;
}
Game* GameList::getHead(){
    return this->head;
}
Game* GameList::getTail(){
    return this->tail;
}
int GameList::getCount(){
    return this->count;
}
//Add game to end of list
void GameList::push(Game* game){
    if(this->getHead() == NULL){
        this->setHead(game);
        this->setTail(game);
        this->setCount(this->getCount() + 1);
    }
    else{
        this->getTail()->setNext(game);
        game->setPrev(this->getTail());
        this->setTail(game);
        this->setCount(this->getCount() + 1);
    }
    return;
}  
//delete game from list by id
void GameList::deleteGame(int gameId){
    Game* current = this->getHead();
    while(current != NULL){
        if(current->getId() == gameId){
            if(current == this->getHead()){
                this->setHead(this->getHead()->getNext());
                this->getHead()->setPrev(NULL);
                free(current);
            }
            else if(current == this->getTail()){
                this->setTail(this->getTail()->getPrev());
                this->getTail()->setNext(NULL);
                free(current);
            }
            else{
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
                free(current);
            }
            return;
        }
        current = current->getNext();
    }
    return;
}
//empty the list
void GameList::deleteGameList(){
    Game* temp1;
    Game* temp2;
    if(this->getHead() == this->getTail()){
        free(this->getHead());
        this->setHead(NULL);
        this->setTail(NULL);
        this->setCount(0);
        return;
    }
    else{
        temp1 = this->getHead();
        temp2 = this->getHead()->getNext();
        while(temp1 != NULL){
            if(temp1 == this->getTail()){
                free(temp1);
                this->setHead(NULL);
                this->setTail(NULL);
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
//prints to terminal
void GameList::print(){
    Game* current = this->getHead();
    if(current == NULL){
        printf("gamelist empty\n");
        return;
    }
    while(current != NULL){
        current->print();
        current = current->getNext();
    }
    return;
}
void GameList::printGameById(int id){
    Game* current = this->getHead();
    while(current != NULL){
        if(current->getId() == id){
            current->print();
        }
        current = current->getNext();
    }
    return;
}
void GameList::testData(){
    Game* game1 = new Game();
    game1->setId(1);
    Game* game2 = new Game();
    game2->setId(2);
    Game* game3 = new Game();
    game3->setId(3);
    Game* game4 = new Game();
    game4->setId(4);

    this->push(game1);
    this->push(game2);
    this->push(game3);
    this->push(game4);

    return;
}
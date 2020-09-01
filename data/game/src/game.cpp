#include <stdio.h>
#include "../game.h"

//constructor
Game::Game(){
    this->next = NULL;
    this->prev = NULL;
}
//get set methods
void Game::setId(int gameid){
    this->id = gameid;
}
void Game::setStatus(int status){
    this->status = status;
}
void Game::setHostId(int hostid){
    this->hostid = hostid;
}
void Game::setNext(class Game* next){
    this->next = next;
}
void Game::setPrev(class Game* prev){
    this->prev = prev;
}
int Game::getId(){
    return this->id;
}
int Game::getStatus(){
    return this->status;
}    
int Game::getHostId(){
    return this->hostid;
}
Game* Game::getNext(){
    return this->next;
}
Game* Game::getPrev(){
    return this->prev;
}
//utility
void Game::print(){
    printf("Game ID: %d\n", this->getId());
    printf("Status: %d\n", this->getStatus());
}

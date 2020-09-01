#include "../player.h"
#include <stdio.h>

void Player::setId(int playerid){
    this->id = playerid;
}
void Player::setGameId(int gameid){
    this->id = gameid;
}
void Player::setName(char* name){
    return;
}
void Player::setX(float x){
    this->x = x;
}
void Player::setY(float y){
    this->y = y;
}
void Player::setAngle(float angle){
    this->angle = angle;
}
void Player::setSpeed(float speed){
    this->speed = speed;
}
void Player::setAcceleration(float a){
    this->acceleration = a;
}
void Player::setLaps(int laps){
    this->laps = laps;
}
void Player::setNext(Player* next){
    this->next = next;
}
void Player::setPrev(Player* prev){
    this->prev = prev;
}
int Player::getId(){
    return this->id;
}
int Player::getGameId(){
    return this->gameid;
}
char* Player::getName(){
    return this->name;
}
float Player::getX(){
    return this->x;
}
float Player::getY(){
    return this->y;
}
float Player::getAngle(){
    return this->angle;
}
float Player::getSpeed(){
    return this->speed;
}
float Player::getAcceleration(){
    return this->acceleration;
}
int Player::getLaps(){
    return this->laps;
}
Player* Player::getNext(){
    return this->next;
}
Player* Player::getPrev(){
    return this->prev;
}
void Player::print(){
    printf("    Player ID: %d\n", this->getId());
    printf("    gameID: %d\n", this->getGameId());
    printf("    name: %s\n", this->getName());
    printf("    position x: %f\n", this->getX());
    printf("    position y: %f\n", this->getY());
    printf("    angle: %f\n", this->getAngle());
    printf("    speed: %f\n", this->getSpeed());
    printf("    acceleration: %f\n", this->getAcceleration());
    printf("    laps: %d\n", this->getLaps());
    printf("\n");
    return;
}

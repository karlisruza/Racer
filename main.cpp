#include <stdio.h>
#include "./data/game/game.h"

int main(void){
    GameList* list = new GameList();
    list->testData();
    list->print();
}
/*
File:           Main.c
Author:         Karri Korsu
Description:    main file for rogue tutorial
*/

#include "Rogue.h"

struct Entity* player;
struct Tile** map;
struct Entity* coinArray;
struct Entity* orc;



int main()
{   
    struct Position posStart;
    
    int x = 5;
    int currentFloor = 0;
    extern struct Floor* floorList; 

    setupCurses();
    
    time_t t = 0;
	srand((unsigned) time(&t));
    
    map = mapTileCreation();
    //map = floorArray[currentFloor].map;
    posStart = mapSetup();  

    player = playerCreation(posStart);

    coinArray = coinCreation();
    
    orc = enemyCreation();

    menuDraw(); // --> Engine.c/Gameloop starts

    quitGame();

    return 0;
}
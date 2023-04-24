/*
File:           Main.c
Author:         Karri Korsu, Nestori Heiskanen
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
    

    setupCurses();
    
    time_t t = 0;
	srand((unsigned) time(&t));

    floorList = generateFloors();

    //map = mapTileCreation(); //struct Tile **map
    map = (floorList + 0);

    posStart = mapSetup();  

    player = playerCreation(posStart);

    coinArray = coinCreation();
    
    orc = enemyCreation();

    menuDraw(); // --> Engine.c/Gameloop starts

    quitGame();

    return 0;
}
/*
File:           Main.c
Author:         Karri Korsu
Description:    main file for rogue tutorial
*/

#include "Rogue.h"

struct Entity* player;
struct Tile** map;
struct Entity* coinArray;



int main()
{   
    struct Position posStart;
    
    setupCurses();
    
    time_t t = 0;
	srand((unsigned) time(&t));
    
    map = mapTileCreation();
    posStart = mapSetup();  

    player = playerCreation(posStart);

    coinArray = coinCreation();

    menuDraw(); // --> Engine.c/Gameloop starts

    quitGame();

    return 0;
}
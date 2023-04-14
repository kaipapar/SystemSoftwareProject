/*
File:           Main.c
Author:         Karri Korsu
Description:    main file for rogue tutorial
*/

#include "Rogue.h"

struct Entity* player;
struct Tile** map;

int main()
{   
    struct Position posStart;
    
    setupCurses();
   
    
    
    map = mapTileCreation();

    posStart = mapSetup();    
    player = playerCreation(posStart);

    gameLoop();

    quitGame();

    return 0;
}
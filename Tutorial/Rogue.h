/*
File:           Rogue.h
Author:         Karri Korsu
Description:    Header for rogue tutorial
*/

#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>

//  macros for map dimensions
#define MAP_HEIGHT 25
#define MAP_WIDTH 100

/*  Struct to store positions of "objects"  */
struct Position
{
    int y;
    int x;
};

/*  Struct to store characteristics of tile "objects"   */
struct Tile
{
    char ch;
    bool walkable; 
};

/*  Struct to store positions and representations of "objects"  */
struct Entity
{
    struct Position pos; //x,y coordinates
    char ch;      // what the player is represented as
};

// Draw.c
void mapDrawing();
void entityDrawing(struct Entity* entity);
void allDraw();

// Engine.c
void setupCurses();
void gameLoop();
void quitGame();

// Map.c
struct Tile** mapTileCreation();
struct Position mapSetup();
void releaseMap();

// Player.c
struct Entity* playerCreation(struct Position posStart);
void inputHandling(int input);
void playerMovement(struct Position newPos);

extern struct Entity* player;  // are externs good policy?
extern struct Tile** map;

#endif
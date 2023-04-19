/*
File:           Rogue.h
Author:         Karri Korsu
Description:    Header for rogue tutorial
*/

#ifndef ROGUE_H
#define ROGUE_H

#ifdef __unix__
#include <ncurses.h>
#include <menu.h>
#else
#include <curses.h>
#include "WINmenu.h"
#endif

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


// colour pairs
#define VISIBLE_COLOR 1
#define SEEN_COLOR 2
#define COIN_COLOR 1

//  macros for map dimensions
#define MAP_HEIGHT 25
#define MAP_WIDTH 100

//  macros for item amounts
#define COIN_COUNT 5

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
    bool walkable; // Used to check can the space be moved to
    int color; // Color of rendered character in axis 0 (black) - 7 (white)
    bool transparent; // Does the tile block FoV 
    bool visible; // Is the tile visible to player
    bool seen; // Rendered by the engine after the tile leaves player's FoV
};

/*  Attributes of a dungeon */
struct Room
{
    int roomHeight;
    int roomWidth;
    struct Position pos;
    struct Position center;
};

/*  Struct to store positions and representations of "objects"  */
struct Entity
{
    struct Position pos; //x,y coordinates
    char ch;      // what the object is represented as in ASCII form
    int color; // color of rendered character in axis 0 (black) - 7 (white)

     /*  NOTE THIS IS TEMPORARY, POSSIBLY...!    */
    bool visible;
    bool transparent;
};


/*      PLAYER STRUCT HERE :::  */

/*      ITEM STRUCT HERE :::    
INHERITS FROM ENTITY AND TILE

*/




// Draw.c
void mapDrawing();
void entityDrawing(struct Entity* entity);
void allDraw();
void infoBoxDraw();
void menuDraw();

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

// Room.c
struct Room roomCreation(int y, int x, int height, int width);
void addRoomToMap(struct Room room);
void roomConnections(struct Position centerSelf, struct Position centerOther);

// Fov.c
void createFOV(struct Entity* player);
void clearFOV(struct Entity* player);
int getDistance(struct Position origin, struct Position target);
bool isInMap(int y, int x);
bool lineOfSight(struct Position origin, struct Position target);
int getSign(int a);

// Items.c
struct Entity* coinCreation();

extern struct Entity* player;  // are externs good policy?
extern struct Tile** map;

extern struct Entity* coinArray;


#endif
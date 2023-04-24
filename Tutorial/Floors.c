/*
File:           Floors.c
Author:         Nestori Heiskanen
Description:    Core of the floor system
*/

#include "Rogue.h"

#define MAPDEPTH 5


//Creates a struct with floor and map data of all floors to the MAPDEPTH
struct Floor* generateFloor()
{
    struct Floor* floorArray = calloc(MAPDEPTH, sizeof(struct Floor));

    for(int i = 0; i < MAPDEPTH; i++)
    {
        (floorArray + i) -> map = mapTileCreation();
    }
}

/*
void freeFloorList(int mapDepth) {
    for (int i = 0; i < mapDepth; i++){
        free(floorList[i]->map);
    }
    free(floorList);
}




struct Floor generateFloor() {
    struct Floor floor;
    floor.map = mapTileCreation();
    //floor.player = playerCreation(mapSetup());
    return floor;
}

void generateFloorList(int mapDepth) {
    floorList = malloc(mapDepth * sizeof(struct Floor));
    for (int i = 0; i <= mapDepth; i++){
        floorList[i] = generateFloor(); 
    }
}

*/
//print();

//int floorlist[mapDepth] = generateFloorList();

// struct floorlist[currentFloor].map
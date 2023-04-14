/*
@File    :   Map.c
@Time    :   14.04.2023 18:28:12
@Author  :   Karri Korsu
@Version :   1.0
@Contact :   karri.korsu@edu.turkuamk.fi
@Desc    :   None
*/

#include "Rogue.h"

/*  Creates a 2d array of tiles for the map, returns pointer to pointer */
struct Tile** mapTileCreation()
{
    struct Tile** tiles = calloc(MAP_HEIGHT, sizeof(struct Tile*));

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        tiles[y] = calloc(MAP_WIDTH, sizeof(struct Tile));

        for (int x = 0; x < MAP_WIDTH; x++)
        {
            tiles[y][x].ch = '#';   // walls
            tiles[y][x].walkable = false;
        }
    }
    return tiles;
}

/*  Adding an area on the map to walk on    */
struct Position mapSetup()
{
    struct Position posStart = {10, 50};

    for (int y = 5; y < 15; y++)
    {
        for (int x = 40; x < 60; x++)
        {
            map[y][x].ch = '.';
            map[y][x].walkable = true;
        }
    }

    return posStart;
}

void releaseMap()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(map[y]);
    }
    free(map);
}
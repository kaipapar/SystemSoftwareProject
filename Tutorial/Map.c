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
            tiles[y][x].color = COLOR_PAIR(VISIBLE_COLOR);
            tiles[y][x].walkable = false;
            tiles[y][x].transparent = false;
            tiles[y][x].visible = false;
            tiles[y][x].seen = false;
            tiles[y][x].found = 0;
        }
    }
    return tiles;
}

/*  Adding an area on the map to walk on    */
struct Position mapSetup()
{
    int y = 0;
    int x = 0;
    int height = 0;
    int width = 0;
    int n_rooms = 0;

    n_rooms = (rand() % 11) + 5;

    struct Room* rooms = calloc(n_rooms, sizeof(struct Room));
    struct Position posStart;


    for (int i = 0; i < n_rooms; i++)
    {
        y = (rand() % (MAP_HEIGHT - 10)) + 1;
        x = (rand() % (MAP_WIDTH - 20)) + 1;
        height = (rand() % 7) + 3;
        width = (rand() % 15) + 5;
        rooms[i] = roomCreation(y, x, height, width);
        addRoomToMap(rooms[i]);

        if (i > 0)
        {
            roomConnections(rooms[i-1].center, rooms[i].center);
        }
    }

    posStart.y = rooms[0].center.y;
    posStart.x = rooms[0].center.x;

    free(rooms);

    return posStart;
}

// Frees the map array from memory
void releaseMap()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(map[y]);
    }
    free(map);
}
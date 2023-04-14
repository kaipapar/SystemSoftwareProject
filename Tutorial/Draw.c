/*
@File    :   Draw.c
@Time    :   14.04.2023 18:36:51
@Author  :   Karri Korsu
@Version :   1.0
@Contact :   karri.korsu@edu.turkuamk.fi
@Desc    :   None
*/

#include "Rogue.h"

void mapDrawing()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            mvaddch(y, x, map[y][x].ch);
        }
    }
}

void entityDrawing(struct Entity* entity)
{
    mvaddch(entity->pos.y, entity->pos.x, entity->ch);  //arguments (y,x,affected item)
}

void allDraw()
{
    clear();    // clears the screen before refreshing   
    mapDrawing();
    entityDrawing(player);
}
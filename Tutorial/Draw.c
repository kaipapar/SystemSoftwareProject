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
            if (map[y][x].visible)
            {
                mvaddch(y, x, map[y][x].ch | map[y][x].color);
            }
            else if (map[y][x].seen)
            {
                mvaddch(y, x, map[y][x].ch | COLOR_PAIR(SEEN_COLOR));
            }
            else
            {
                mvaddch(y, x, ' ');
            }
        }
    }
}

void entityDrawing(struct Entity* entity)
{
    mvaddch(entity->pos.y, entity->pos.x, entity->ch | entity->color);  //arguments (y,x,affected item)
}

void coinDrawing()
{
    for(int i = 0; i < COIN_COUNT; i++)
    {
        if ((coinArray + i)->visible == true)
        {
            mvaddch((coinArray + i) -> pos.y, (coinArray + i) -> pos.x, (coinArray + i) -> ch | (coinArray + i)-> color);
        }

    }
}

void allDraw(struct Entity* entity, int entitySize)
{
    clear();    // clears the screen before refreshing
    mapDrawing(); // renders the game map
    entityDrawing(player);
    coinDrawing(); // temporary testing function (replace later)
    infoBoxDraw(); // UI element rendering for controls info
}

void infoBoxDraw()
{
        /*  Subwindow for printing game information */
    WINDOW* subwindow = newwin(10,30,5,100);
    refresh();
    box(subwindow,0,0);

    char hintBoxContent[] = "Welcome to RoCue! \n" 
                            "RoCue is a roguelike game \n"
                            "where you battle creeps! \n"
                            "Movement - WASD \n"
                            "Quit - F1 \n"
                            "Interact - Q \n"
                            "Inventory - E";
    //mvwprintw(subwindow, 1, 1, "%s", &hintBoxContent);
    refresh();
    wrefresh(subwindow);
}



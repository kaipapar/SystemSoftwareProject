/*
@File    :   Engine.c
@Time    :   14.04.2023 18:09:18
@Author  :   Karri Korsu
@Version :   1.0
@Contact :   karri.korsu@edu.turkuamk.fi
@Desc    :   None
*/

#include "Rogue.h"

void setupCurses()
{
    initscr();
    noecho();
    curs_set(0);


    if (has_colors())
    {
        start_color();

        init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
        init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK);
    }
}

void gameLoop()
{
    int ch = 45; // init as '0'

    createFOV(player);
    allDraw();
    
    while(ch = getch())
    {
        if (ch == 'q')   // while q is not pressed create a 'character'
        {
            break;
        }
       
        inputHandling(ch);
        allDraw();
    }
}

void quitGame()
{
    endwin();
    free(player);
}
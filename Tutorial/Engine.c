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
    /*
    //printw("Welcome to RoCue!\n \tRoCue is a game where");
    WINDOW* subwindow = newwin(MAP_HEIGHT,MAP_WIDTH,5,15);
    box(subwindow,0,0);
    char str[] = "Welcome to RoCue! \n RoCue is a game where";
    mvwprintw(subwindow, 1, 1, "Welcome to RoCue! \n RoCue is a game where");
    //mvprintw(MAP_HEIGHT / 2, MAP_WIDTH / 2, "%s", &str);
    wrefresh(subwindow);
    */
    WINDOW* subwindow = newwin(20,30,5,100);

    refresh();

    box(subwindow,0,0);
    mvwprintw(subwindow, 1, 1, "Welcome to RoCue! \n RoCue is a game where");


    refresh();
    wrefresh(subwindow);

    getch();
    delwin(subwindow);
    while(ch = getch())
    {
        if (ch == 'q')   // while q is not pressed create a 'character'
        {
            break;
        }
       
        inputHandling(ch);
        //mvprintw(MAP_HEIGHT / 2, MAP_WIDTH / 2, "%s", &str);
        allDraw();
    }
}

void quitGame()
{
    endwin();
    free(player);
}
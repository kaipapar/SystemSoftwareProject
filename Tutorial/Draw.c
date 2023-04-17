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

void allDraw()
{
    clear();    // clears the screen before refreshing   
    mapDrawing();
    entityDrawing(player);
    infoBoxDraw();
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


void menuDraw()
{
    //WINDOW* menuWin = newwin(0,0,MAP_HEIGHT,MAP_WIDTH);
    //box(menuWin,0,0);
    refresh();
    ITEM **my_items[5];
	int c = 0;				
	MENU *my_menu;  // Cannot be initialized to null, causes seg fault
	int n_choices = 5;
	ITEM *cur_item = NULL;

    keypad(stdscr, TRUE);

    char *choices[] = {
                        "Play!",
                        "Settings",
                        "Choice 3",
                        "Choice 4",
                        "Exit",
                  };
    
    int choice = 0; //   used to select an item



    for(int i = 0; i < n_choices; ++i)
    {
        my_items[i] = new_item(choices[i], choices[i]);
    }
    
    my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	mvprintw(LINES - 2, 0, "F1 to Exit, Arrow-Right to select");
	post_menu(my_menu);
	refresh();

	while((c = getch()))
	{   switch(c)
	    {	case KEY_DOWN:
		        menu_driver(my_menu, REQ_DOWN_ITEM);
                choice++;
                if (choice == n_choices)
                {
                    choice--;
                }
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
                choice--;
                if (choice == -1)
                {
                    choice++;
                }
				break;
			case KEY_RIGHT:
				menu_driver(my_menu, REQ_TOGGLE_ITEM);
                if (choice == 0)
                {
                    gameLoop();
                }
                else 
                {
                    break;
                }
                free_item(my_items[0]);
				free_item(my_items[1]);
				//free_menu(my_menu);
                unpost_menu(my_menu);
				break;
			case KEY_F(1):
				free_item(my_items[0]);
				free_item(my_items[1]);
				//free_menu(my_menu);
                quitGame();
				break;
		}
	}
}
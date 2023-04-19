/*
@File    :   Player.c
@Time    :   14.04.2023 17:31:50
@Author  :   Karri Korsu
@Version :   1.0
@Contact :   karri.korsu@edu.turkuamk.fi
@Desc    :   None
*/
#include "Rogue.h"
/*                       CREATE CUSTOM  STRUCT FOR PLAYER WHICH INHERITS ENTITY STRUCT       */
struct Entity* playerCreation(struct Position posStart)
{
    struct Entity* newPlayer = calloc(1, sizeof(struct Entity)); //correct use of calloc?

    newPlayer->pos.y = posStart.y;
    newPlayer->pos.x = posStart.x;
    newPlayer->color = COLOR_PAIR(VISIBLE_COLOR);
    newPlayer->ch = '@';
 
    return newPlayer;
}

/*  Handle user input */
void inputHandling(int input)
{
    struct Position newPos = { player->pos.y, player->pos.x };

    switch (input)
    {
        case 'w':
            newPos.y--;
            break;
        case 's':
            newPos.y++;
            break;
        case 'a':
            newPos.x--;
            break;
        case 'd':
            newPos.x++;
            break;
        case KEY_F(1):
            quitGame();
            break;
        default:
            break;
    }

    playerMovement(newPos);
}

/*  Checks whether movement over a certain block is allowed */
void playerMovement(struct Position newPos)
{
    if (map[newPos.y][newPos.x].walkable)
    {
        clearFOV(player);
        player->pos.y = newPos.y;
        player->pos.x = newPos.x;
        createFOV(player);
    }
}
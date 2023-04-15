/*
@File    :   Player.c
@Time    :   14.04.2023 17:31:50
@Author  :   Karri Korsu
@Version :   1.0
@Contact :   karri.korsu@edu.turkuamk.fi
@Desc    :   None
*/
#include "Rogue.h"

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
        case 'k':
            newPos.y--;
            break;
        case 'j':
            newPos.y++;
            break;
        case 'h':
            newPos.x--;
            break;
        case 'l':
            newPos.x++;
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
/*
@File    :   Enemy.c
@Time    :   21.04.2023 12:56:08
@Author  :   Karri Korsu
@Version :   1.0
@Contact :   karri.korsu@edu.turkuamk.fi
@Desc    :   None
*/
#include "Rogue.h"
/*  Enemy creation, pathfinding, interaction with player    */

/*
Create enemy entity
    inherits from entity struct, 

*/
struct Entity* enemyCreation()
{
    struct Entity* orc = calloc(1, sizeof(struct Entity));

    orc -> ch = 'O';
    orc -> color = COLOR_PAIR(COIN_COLOR);
    orc -> visible = false;
    orc -> transparent = false;

    int flag = 0;

    while (true)
    {
        int randomx = rand() % 100;
        int randomy = rand() % 25;

        if (map[randomy][randomx].walkable && flag == 0)
        {
            orc -> pos.x = randomx;
            orc -> pos.y = randomy;
            flag = 1;
            break;
        }
    }
    return orc;
}



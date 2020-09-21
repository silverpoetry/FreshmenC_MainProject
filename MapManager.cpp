#include "MapManager.h"
#include "Player/Baseline.h"
#include "state.h"

int map[10][10];

void MapManger_Init()
{

    for(int i = 0; i < 10 ;i ++)
    {
        for(int j = 0; j < 10; j++)
        {
            map[i][j] = BLANK;
        }
    }
    map[4][4] = WHITE;
    map[5][5] = WHITE;
    map[4][5] = BLACK;
    map[5][4] = WHITE;
}
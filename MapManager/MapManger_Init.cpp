#include "MapManager.h"
#include "../state.h"

int MapManager_Map[10][10];
bool MapManager_GameFinished;
bool MapManager_GameWinner;


void MapManger_Init()
{

    for(int i = 0; i < 10 ;i ++)
    {
        for(int j = 0; j < 10; j++)
        {
            MapManager_Map[i][j] = BLANK;
        }
    }
    MapManager_Map[4][4] = WHITE;
    MapManager_Map[5][5] = WHITE;
    MapManager_Map[4][5] = BLACK;
    MapManager_Map[5][4] = WHITE;
}
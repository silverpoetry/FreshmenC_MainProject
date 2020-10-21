#include "MapManager.h"

int MapManager_Map[10][10];
bool MapManager_GameFinished;
bool MapManager_GameWinner;

void MapManger_Init()
{

    for (int i = 0; i < ColNumber; i++)
    {
        for (int j = 0; j < RowNumber; j++)
        {
            MapManager_Map[i][j] = BLANK;
        }
    }
    int mid =ColNumber/2;
    MapManager_Map[mid][mid] = WHITE;
    MapManager_Map[mid+1][mid+1] = WHITE;
    MapManager_Map[mid][mid+1] = BLACK;
    MapManager_Map[mid+1][mid] = WHITE;
}
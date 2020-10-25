#include "MapManager.h"

int MapManager_Map[12][12];
bool MapManager_GameFinished;
bool MapManager_GameWinner;

void MapManger_Init()
{

    for (int i = 0; i <= ColNumber+1; i++)
    {
        for (int j = 0; j <= RowNumber+1; j++)
        {
            MapManager_Map[i][j] = BLANK;
        }
    }
    int mid =ColNumber/2;
    MapManager_Map[mid][mid] = WHITE;
    MapManager_Map[mid+1][mid+1] = WHITE;
    MapManager_Map[mid][mid+1] = BLACK;
    MapManager_Map[mid+1][mid] = BLACK;
}
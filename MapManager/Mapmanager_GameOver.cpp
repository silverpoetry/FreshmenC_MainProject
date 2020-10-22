#include "MapManager.h"
#include "..\state.h"
//数黑白棋子数，判断胜负，写入文件
void Mapmanager_GameOver()
{
    int bcnt = 0,wcnt=0;
    for (int y = 1; y <= RowNumber; y++)
    {
        for (int x = 1; x <= ColNumber; x++)
        {
        
            if(MapManager_Map[x][y]==BLACK)
                bcnt++;
            else if (MapManager_Map[x][y]==WHITE)
                wcnt++;
        }
    }
    if(bcnt>=wcnt)MapManager_GameWinner=BLACK;
    else MapManager_GameWinner=WHITE;
    MapManager_GameFinished=true;
    
}
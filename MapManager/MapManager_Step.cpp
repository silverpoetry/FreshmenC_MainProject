#include "MapManager.h"
#include <cstdio>

void PrintMap(int, int, int);

//传入棋手和下棋位置，如果下棋位置不合法，游戏结束
//更新棋盘
//写入文件
//获取下一方的下棋位置列表
//如果不为空，切换下家，返回
//如果为空，获得本家列表
//如果本家还能下，本家继续
//否则游戏结束，GaneFinished置位
int cglst[64][2];
int MapManager_Step(int player, int x, int y)
{
    //吓到不该下的地方，对方赢
    if (!MapManager_CanGo(player, x, y))
    {
        MapManager_GameFinished = true;
        MapManager_GameWinner = !player;
        return 0;
    }

    //下到可以下的地方
    //更新棋盘并写入
    MapManager_Reverse(player, x, y);
    PrintMap(player, x, y);
    if (MapManager_GetCanGoList(!player, cglst))
        return !player;
    if (MapManager_GetCanGoList(player, cglst))
        return player;
    Mapmanager_GameOver();
    return player;
}

void PrintMap(int player, int x, int y)
{
    printf("%d %d %d\n", player, x, y);
    for (int yy = 1; yy <= RowNumber; yy++)
    {
        for (int xx = 1; xx <= ColNumber; xx++)
        {
        
            printf("%d ",MapManager_Map[xx][yy]);
        }
        putchar('\n');
    }
}

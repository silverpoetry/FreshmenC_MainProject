
#define Team1_Go Baseline_Go
#define Team2_Go TeamName_Go //这里换成参赛的队伍的函数名

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include "state.h"
#include "Player/Baseline.h"
#include "MapManager/MapManager.h"
#include "Player/Teamname.h"

using namespace std;
int cangolist[64][2];
int main()
{
    MapManger_Init();
    freopen("match1.txt", "w", stdout);
    printf("%s %s \n", "超级AI", "白棋队");

    int currentplayer = BLACK;
    MapManger_Init();
    while (!MapManager_GameFinished)
    {
        int ret[2] = {0, 0};

        int cangolength = MapManager_GetCanGoList(currentplayer, cangolist);
        if (currentplayer == BLACK)
            Team1_Go(BLACK, MapManager_Map, cangolist, cangolength, ret);
        else
            //Team1_Go(WHITE, MapManager_Map, cangolist, cangolength, ret);
            Team2_Go(WHITE, MapManager_Map, ret);

        currentplayer = MapManager_Step(currentplayer, ret[0], ret[1]);
    }
    //输出赢家
    printf("%d \n", MapManager_GameWinner);
    // system("pause");
    return 0;
}

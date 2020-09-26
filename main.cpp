
#define Team1_Go Baseline_Go
#define Team2_Go TeamName_Go //���ﻻ�ɲ����Ķ���ĺ�����

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "state.h"
#include "Player/Baseline.h"
#include "MapManager/MapManager.h"
#include "Player/Teamname.h"

using namespace std;
int cangolist[32][2];
int main()
{
    MapManger_Init();

    int currentplayer = BLACK;
    while (!MapManager_GameFinished)
    {
        int ret[2] = {0, 0};
        int cangolength = MapManager_GetCanGoList(currentplayer, cangolist);
        if (currentplayer == BLACK)
            Team1_Go(BLACK, MapManager_Map, cangolist, cangolength, ret);
        else
            Team2_Go(WHITE, MapManager_Map, cangolist, cangolength, ret);

        currentplayer = MapManager_Step(currentplayer, ret[0], ret[1]);
    }

    return 0;
}

#include "MapManager.h"

//判断某位置是否能走棋
bool MapManager_CanGo(int player, int x, int y)
{
    struct Direction
    {
        int x = 0;
        int y = 0;
    } direction;
    return false;
}

// int queryMap(int x, int y)
// {
//     if (x > 0 && x < 9 && y > 0 && y < 9)
//     {
//         return MapManager_Map[x][y];
//     }
//     else
//     {
//         printf("queryMap error: overflow");
//         return -1;
//     }
// }

#include "MapManager.h"
#include "../state.h"

#define RowNumber 8
#define ColNumber 8

//获取下棋位置列表
//player：黑骑或者白漆
//ret 返回坐标的二维数组
//返回值 ：列表长度，存储从0开始
int MapManager_GetCanGoList(int player, int ret[32][2])
{
    int ListLength = 0 ;
    for (int i = 1; i <= RowNumber; ++i){
        for (int j = 1; j <= ColNumber; ++j){
            if(MapManager_CanGo(player, i, j)){
                ret[ListLength][0]=i;
                ret[ListLength][1]=j;
                ListLength++;
            }
        }
    }
    return ListLength;
}

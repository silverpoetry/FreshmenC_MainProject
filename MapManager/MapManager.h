
#include "../state.h"

//文件读写采用stdio，在main里面freopen

//以左上角为原点 从（1,1）到 （8,8）
extern int MapManager_Map[10][10];

//游戏是否结束标记位
extern bool MapManager_GameFinished;

//游戏胜者
extern bool MapManager_GameWinner;

//初始化棋盘（中央黑白子）
void MapManger_Init();

//传入棋手和下棋位置，如果下棋位置不合法，游戏结束
//更新棋盘
//写入文件
//获取下一方的下棋位置列表
//如果不为空，切换下家，返回
//如果为空，获得本家列表
//如果本家还能下，本家继续
//否则游戏结束，GaneFinished置位
int MapManager_Step(int player, int x, int y);

//获取下棋位置列表
//player：黑骑或者白漆
//ret 返回坐标的二维数组
//返回值 ：列表长度，存储从0开始
int MapManager_GetCanGoList(int player, int ret[32][2]);

//判断某位置是否能走棋
bool MapManager_CanGo(int player, int x, int y);

//落子并完成地图的翻转
void MapManager_Reverse(int player, int x, int y);

//数黑白棋子数，判断胜负，写入文件
void Mapmanager_GameOver();

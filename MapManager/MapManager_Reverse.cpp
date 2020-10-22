#include "MapManager.h"

//落子翻转
void MapManager_Reverse(int player, int x, int y)
{
  bool dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
  for(int i=0;i<8;i++)
  {
    int Reverse_Step=1;
    int Reverse_Position_x=x+Reverse_Step_x*dir[i][0], Reverse_Position_y=y+Reverse_Step_y*dir[i][1];
    while()
  }
}

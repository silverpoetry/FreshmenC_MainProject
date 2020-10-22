#include "MapManager.h"

//落子翻转
void MapManager_Reverse(int player, int x, int y)
{
  bool dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
  for(int i=0;i<8;i++)
  {
    int Reverse_Step=1;
    int Reverse_x=x+Reverse_Step*dir[i][0], Reverse_y=y+Reverse_Step*dir[i][1];
    while(In_Range(Reverse_x,Reverse_y))
    {
      if(MapManager_Map[Reverse_x][Reverse_y]==BLANK) break;
      if(MapManager_Map[Reverse_x][Reverse_y]==player)
      {
        Reverse(x,y,Reverse_x,Reverse_y,i);
        break;
      }
      Reverse_x+=dir[i][0];
      Reverse_y+=dir[i][1];
    }
  }
}

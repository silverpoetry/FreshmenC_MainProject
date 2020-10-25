#include "MapManager.h"

int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

//判断在棋盘内
bool In_Range(int x,int y)
{
  return (1<=x && x<=ColNumber && 1<=y && y<=RowNumber);
}

//翻转操作
void Reverse(int x,int y,int xe,int ye,int d)
{
  int Reverse_x=x+dir[d][0], Reverse_y=y+dir[d][1];
  while(!(Reverse_x==xe && Reverse_y==ye))
  {
    MapManager_Map[Reverse_x][Reverse_y]^=1;
    Reverse_x+=dir[d][0];
    Reverse_y+=dir[d][1];
  }
}

//落子翻转调用接口
void MapManager_Reverse(int player, int x, int y)
{
  for(int i=0;i<8;i++)
  {
    int Reverse_x=x+dir[i][0], Reverse_y=y+dir[i][1];
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

#include "MapManager.h"
#include "../state.h"

#define RowNumber 8
#define ColNumber 8

//��ȡ����λ���б�
//player��������߰���
//ret ��������Ķ�ά����
//����ֵ ���б��ȣ��洢��0��ʼ
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

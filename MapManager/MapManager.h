#include <stdio.h>
#include "../state.h"

//�ļ���д����stdio����main����freopen

//�����Ͻ�Ϊԭ�� �ӣ�1,1���� ��8,8��
extern int MapManager_Map[10][10];

//��Ϸ�Ƿ�������λ
extern bool MapManager_GameFinished;

//��Ϸʤ��
extern bool MapManager_GameWinner;

//��ʼ�����̣�����ڰ��ӣ�
void MapManger_Init();

//�������ֺ�����λ�ã��������λ�ò��Ϸ�����Ϸ����
//��������
//д���ļ�
//��ȡ��һ��������λ���б�
//�����Ϊ�գ��л��¼ң�����
//���Ϊ�գ���ñ����б�
//������һ����£����Ҽ���
//������Ϸ������GaneFinished��λ
int MapManager_Step(int player, int x, int y);

//��ȡ����λ���б�
//player��������߰���
//ret ��������Ķ�ά����
//����ֵ ���б��ȣ��洢��0��ʼ
int MapManager_GetCanGoList(int player, int ret[32][2]);

//�ж�ĳλ���Ƿ�������
bool MapManager_CanGo(int player,unsigned int x,unsigned int y);

//���Ӳ���ɵ�ͼ�ķ�ת
void MapManager_Reverse(int player, int x, int y);

//���ڰ����������ж�ʤ����д���ļ�
void Mapmanager_GameOver();

# define _CRT_SECURE_NO_WARNINGS 1
# include "game.h"
void game()
{
	char showboard[ROW][COL], realboard[ROW][COL];   // showboard[ROW][COL]��չʾ�����̣�realboard��ʵ�ʵ�����
	initializeboard(showboard,ROW,COL,'*');     //��ʼ�����̼���������ȫ������ͬһ���ַ�,*�������
	initializeboard(realboard, ROW, COL, '0');  //��ʼ�����̼���������ȫ������ͬһ���ַ�
	putboard(realboard, ROWS, COLS);       //    ����
	improveboard(realboard,ROWS,COLS);    //  ����ʵ�������Ƽ������ּ���
	sweepmines(showboard,realboard,ROWS,COLS); //ɨ��
}
int main()
{
	srand((unsigned)time(NULL));
	int input;
	do
	{
	printf("******************************************\n");
	printf("*********1.��ʼ��Ϸ        0.�˳�*********\n");
	printf("******************************************\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("�ټ���\n");
			break;
		}
		default:
		{
			printf("������ѡ��\n");
		}
		}
	} while (input);
	return 0;
}

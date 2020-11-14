# define _CRT_SECURE_NO_WARNINGS 1
# include "game.h"
void game()
{
	char showboard[ROW][COL], realboard[ROW][COL];   // showboard[ROW][COL]是展示的棋盘，realboard是实际的棋盘
	initializeboard(showboard,ROW,COL,'*');     //初始化棋盘即把棋盘上全部放上同一个字符,*代表格子
	initializeboard(realboard, ROW, COL, '0');  //初始化棋盘即把棋盘上全部放上同一个字符
	putboard(realboard, ROWS, COLS);       //    布雷
	improveboard(realboard,ROWS,COLS);    //  把真实棋盘完善即把数字加上
	sweepmines(showboard,realboard,ROWS,COLS); //扫雷
}
int main()
{
	srand((unsigned)time(NULL));
	int input;
	do
	{
	printf("******************************************\n");
	printf("*********1.开始游戏        0.退出*********\n");
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
			printf("再见！\n");
			break;
		}
		default:
		{
			printf("请重新选择！\n");
		}
		}
	} while (input);
	return 0;
}

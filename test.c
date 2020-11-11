# define _CRT_SECURE_NO_WARNINGS 1
# include"game.h"
void menu()
{
	printf("***********************************\n");
	printf("*****1.玩游戏       0.退出游戏*****\n");
	printf("***********************************\n");
}
void game()
{
	char ret;
	char board[ROW][COL];
	initboard(board,ROW,COL);
	displayboard( board, ROW, COL);   //打印棋盘
	while (1)
	{
		playermove(board,ROW,COL);    //玩家下棋
		displayboard(board, ROW, COL);   // 打印棋盘
		ret= iswin(board,ROW,COL);
		if(ret!='c')
		{
			break;
		}
		computermove(board,ROW,COL);   //电脑下棋
		displayboard(board, ROW, COL); // 打印棋盘
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢。\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢。\n");
	}
	else
	{
		printf("平局。\n");
	}
}
void test()
{
	int input;
	do
	{
		menu();
		scanf("%d", &input);
		switch(input)
		{ 
			case 1:
			{
				game();
				break;
			}
			case 0:
			{
				printf("下次再见！\n");
				break;
			}
			default:
			{
				printf("请重新输入\n");
				break;
			}
		}
	} while (input);
}
int main()
{
	srand((unsigned)time(NULL));
    test();
	return 0;
}
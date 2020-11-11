# define _CRT_SECURE_NO_WARNINGS 1
# include "game.h"
void initboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j=0;j<col;j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("请您输入坐标：");
		scanf("%d%d", &x,&y);
		if (x > 0 && x <=row && y>0 && y <=col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("输入错误!\n");
			}
		}
		else
		{
			printf("输入错误!\n");
		}
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑下棋!\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
char iswin(char board[ROW][COL], int row, int col)
{
	int i,j;
	for (i = 0; i < row; i++)   //判断行是否胜
	{
		for (j = 0; j < (col - 2); j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (j = 0; j < col; j++)    //判断列是否胜
	{
		for (i = 0; i < (row - 2); i++)
		{
			if (board[i][j]==board[i+1][j]&&board[i+1][j]==board[i+2][j]&&board[i][j]!=' ')
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row-2; i++)       //正序对角线
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (i = 2; i < row; i++)       //倒序斜对角线
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i - 2][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row; i++)   //判断平局 还是继续
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'c';
			}
		}
	}
	return 'Q';
}

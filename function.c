# define _CRT_SECURE_NO_WARNINGS 1
# include "game.h"
void initializeboard(char board[][COL], int row, int col, char a)   // 初始化棋盘即把棋盘上全部放上同一个字符
{
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = a;
		}
	}
}

void putboard(char board[][COL], int row, int col)      //布雷
{
	int x, y,court=0;
	while(court<COURT)
	{
		x = rand()%row + 1;
		y = rand()%col + 1;
		board[x][y] = '#';
		court++;
	}
}

char num(char board[][ROW],int i,int j)     //点开的数字大小
{
	char a;
	int h, l,n=0;
	for (h = i - 1; h <= i + 1; h++)
	{
		for (l = j - 1; l<= j + 1; l++)
		{
			if (board[h][l] == '#')
			{
				n = n + 1;
			}
		}
	}
	a = '0' + n;
	return (a);
}
void improveboard(char board[][COL], int row, int col)    //完善棋盘
{
	int i, j;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if(board[i][j]!='#')
			{
				board[i][j] = num(board,i,j);
			}
		}
	}
}
void displayboard(char board[][COL], int row, int col)    //显示棋盘
{
	int i, j;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf(" %c ",board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void sweepmines(char showboard[][COL], char realboard[][COL], int row, int col)  //扫雷
{
	int x, y, t = 0;
	do
	{
		displayboard(showboard, row, col);
		printf("请输入坐标\n");
		scanf("%d%d", &x, &y);
		if (realboard[x][y] == '#')
		{
			printf("你被炸死了！\n");
			break;
		}
		else
		{
			showboard[x][y] = realboard[x][y];
			t = t + 1;
		}
	} while (t <((ROWS)*(COLS)-COURT));
	if (t == ((ROWS) * (COLS)-COURT))
	{
		printf("恭喜你，赢了！\n");
	}
}


# define _CRT_SECURE_NO_WARNINGS 1
# include"game.h"
void menu()
{
	printf("***********************************\n");
	printf("*****1.����Ϸ       0.�˳���Ϸ*****\n");
	printf("***********************************\n");
}
void game()
{
	char ret;
	char board[ROW][COL];
	initboard(board,ROW,COL);
	displayboard( board, ROW, COL);   //��ӡ����
	while (1)
	{
		playermove(board,ROW,COL);    //�������
		displayboard(board, ROW, COL);   // ��ӡ����
		ret= iswin(board,ROW,COL);
		if(ret!='c')
		{
			break;
		}
		computermove(board,ROW,COL);   //��������
		displayboard(board, ROW, COL); // ��ӡ����
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ�֡�\n");
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
				printf("�´��ټ���\n");
				break;
			}
			default:
			{
				printf("����������\n");
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
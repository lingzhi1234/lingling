#pragma once
# include<stdlib.h>
# include<stdio.h>
# include<time.h>
# define ROW 11   
# define COL 11
# define ROWS ROW-2  //������
# define COLS COL-2  //������
# define COURT 10  //�׵����� 
void initializeboard(char board[][COL], int row, int col, char a);
void putboard(char board[][COL], int row, int col);     //����
void displayboard(char board[][COL], int row, int col);   //��ʾ����
void improveboard(char board[][COL], int row, int col);   //��������
void sweepmines(char showboard[][COL], char realboard[][COL],int row,int col);    //ɨ��


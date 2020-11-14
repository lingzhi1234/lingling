#pragma once
# include<stdlib.h>
# include<stdio.h>
# include<time.h>
# define ROW 11   
# define COL 11
# define ROWS ROW-2  //棋盘行
# define COLS COL-2  //棋盘列
# define COURT 10  //雷的数量 
void initializeboard(char board[][COL], int row, int col, char a);
void putboard(char board[][COL], int row, int col);     //布雷
void displayboard(char board[][COL], int row, int col);   //显示棋盘
void improveboard(char board[][COL], int row, int col);   //完善棋盘
void sweepmines(char showboard[][COL], char realboard[][COL],int row,int col);    //扫雷


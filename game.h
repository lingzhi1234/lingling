#pragma once
# include<stdio.h>
# include<time.h>
# include<stdlib.h>
# define ROW 10
# define COL 10
void initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL],int row,int col);
char iswin(char board[ROW][COL], int row,int col);

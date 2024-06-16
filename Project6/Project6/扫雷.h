#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>
#include<time.h>



#define ROW 9
#define ROWS ROW+2 
#define COL 9
#define COLS COL+2 
#define easynum 10//简单模式的雷的个数



void initboard(char board[ROWS][COLS], int rows, int cols,char set);
void displayboard(char board[ROWS][COLS], int row, int col);
void set(char board[ROWS][COLS], int row, int col);
void find(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int getnum(char mine[ROWS][COLS],char show[ROWS][COLS],int x, int y,int win);
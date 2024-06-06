#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>//可以直接在头文件中引用 以免多次引用
#include<time.h>


#define ROW 3//这样定义 可以方便更改棋盘规格 只需要在这里进行修改就行
#define COL 3



void intboard(char board[ROW][COL], int row, int col);//函数声明
void display_board(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);


//我们需要这个函数返回四种状态 玩家win 电脑win 平局 继续  分别返回* # Q C 
char iswin(char board[ROW][COL], int row, int col);
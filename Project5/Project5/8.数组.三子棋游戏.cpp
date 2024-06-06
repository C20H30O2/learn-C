#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>
#include"8.数组.三子棋游戏.h"//记得引用头文件

void intboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0;j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);//打印一行数据  这里写的%c | %c | %c 会使得不管设定棋盘为什么样的规格 都只有三列
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//打印一行的数据
			printf(" %c ", board[i][j]);
			if (j < col - 1)//最后一列不打印|
				printf("|");
		}
		printf("\n");

		if (i < row - 1)
		{//打印分割行
			for (j = 0; j < col; j++) 
			{
				printf("---");
				if (j < col - 1)
					printf("|");
		    }
			printf("\n");
		}
		
	}
}


void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋\n");
	while (1)//输入坐标不合法重新输入
	{
		printf("输入要落子的坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')//如果该坐标没有被落过子
			{
				board[x - 1][y - 1] = '*';//填入*
				break;
			}
			else
			{
				printf("该坐标也被占用，请换一个\n");
			}
		}

		else
		{
			printf("该坐标非法，请换一个\n");
		}
	}
}


void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋");

	while (1)
	{
		x = rand() % row;//利用随机数%row 来生成一个合法的随机坐标
		y = rand() % col;//然后我们需要为随机数寻找一个时刻不同的种子 跟之前讲过的一样 种子的设置我们没有放在这个函数中 而是在被只调用一次的test函数中设置种子
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}
}



char iswin(char board[ROW][COL], int row, int col)
{
	return 0;
}
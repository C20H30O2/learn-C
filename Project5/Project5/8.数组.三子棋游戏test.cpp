#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>

#include "8.数组.三子棋游戏.h"//引用自己的头文件

void menu()
{
	printf("*****1.play 0.exit*****\n");
}


//整个游戏算法的实现
void game()
{
	char ret = 0;//用于接收判断输赢函数的返回值

	//利用数组存储游戏的棋盘信息
	//char board[3][3] = { 0 };//不这样设计 防止后期可能出现的一些问题
	char board[ROW][COL] = { 0 };//在头文件中定义相关的量（方便于更改 后期只要在头文件进行更改就行） 记得要引用头文件
    
	//开始时 棋盘上也就是数组上的内容是空格最好 便于玩家观察 所以在这里用一个函数对数组进行初始化
	intboard(board, ROW, COL);//这个函数属于游戏模块的内容 所以在头文件中进行声明 在游戏.cpp文件中定义
	//其实在初始化中给出的0 也是一种不可打印字符 这就使得在这里就算不用这个函数对数组初始化 打印出来的棋盘上也是没有东西的
	//如果把0换作其他字符 再屏蔽掉intboard 那么棋盘上就会有东西

	//希望打印出的棋盘的样子
	//    |   |       第一行  每一格的内容为 空格符号空格  
	// ---|---|---
	//    |   |       第二行
	// ---|---|---
	//    |   |       第三行  整体就是一个九宫格
	//测试 用函数打印看看初始化后的棋盘
	display_board(board,ROW,COL);//同样在头文件声明 在游戏.cpp中实现

	//下棋
	while (1)//直到分出胜负再跳出循环
	{
		//先玩家下棋
		playermove(board,ROW,COL);
		//显示玩家下过棋后的棋盘
		display_board(board, ROW, COL);

		//判断一次输赢
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}


		//电脑下棋
		computermove(board, ROW, COL);
		display_board(board, ROW, COL);

		//判断一次输赢
		ret = iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("玩家胜利\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}


}


void test()
{
	srand((unsigned int)time(NULL));//记得要引用头文件#include<stdlib.h>和#include<time.h>  利用时间戳生成种子

	int input = 0;
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);//将input作为执行判断条件 为0就会退出
}



int main()
{
	test();
	return 0;
}

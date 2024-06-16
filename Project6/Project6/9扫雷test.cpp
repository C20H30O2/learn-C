#include"扫雷.h"//记得引用头文件


void menu()
{
	printf("*********\n");
	printf("1.play  0.exit\n");

}



void game()
{
	printf("扫雷\n");
	char mine[ROWS][COLS] = { 0 };//游戏数组//设定游戏规模时 对于9*9的棋盘最好以11*11来设定 便于检测边缘格子四周有没有雷
	char show[ROWS][COLS] = { 0 };//用来显示信息的数组
	
	//初始化
	initboard(mine, ROWS, COLS,'0');
	initboard(show, ROWS, COLS,'*');//将要初始化的字符也作为参数传入 这样对于不同需求的表格可以用相同的函数得到不同结果

	//打印棋盘
	//displayboard(mine, ROW, COL);//只显示游戏规模大小的棋盘 为了方便而添加上去的部分不显示
	displayboard(show, ROW, COL);//只显示游戏规模大小的棋盘 为了方便而添加上去的部分不显示

	//布置雷
	set(mine, ROW, COL);
	//displayboard(mine, ROW, COL);//做测试使用 游戏时不打印


	//扫雷
	find(mine, show, ROW, COL);

}


void test()
{
	srand((unsigned int)time(NULL));//设定随机数种子

	int input = 0;
	do {
		menu();
		
		printf("please input\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit\n");
			break;
		default:
			printf("error,choose again\n");
			break;
		}
	} while (input);

	
}

int main()
{
	test();
	return 0;
}
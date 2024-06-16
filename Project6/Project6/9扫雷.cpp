#include"扫雷.h"//记得引用头文件

void initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

}


void set(char board[ROWS][COLS], int row, int col)
{
	int num = easynum;
	while (num)
	{
		int x = rand()%row+1;//1到9
		int y = rand()%col+1;//1到9
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			num--;
		}
		
	}
}


void find(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	int win = 0;
	int key = 0;

	while (win<row*col-easynum)
	{
		printf("请输入想要排查的坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y]=='*')
		{    
			if (mine[x][y] == '1')
			{
				printf("很遗憾踩雷了，你被炸死了\n");
				displayboard(mine, row, col);
				break;//跳出test里的do while循环
			}
			else {//如果不是雷就要统计周围有几个雷
				key=getnum(mine,show,x, y,win);
				displayboard(show, row, col);

			}
		}
		else {
			printf("坐标不合法，请重新输入\n");
		}
    }

	if (key == row * col - easynum)
	{
		printf("You Win\n");
	}
}


int getnum(char mine[ROWS][COLS], char show[ROWS][COLS],int x, int y,int win)
{
	int num = 0;
	int i = 0;
	int j = 0;

	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (i != x && j != y);
			{num += mine[i][j] - '0';//格子内是字符0 或者字符1 数字字符减去字符0等于该数字 即'1'-'0'=1
			//if (mine[i][j] == '0')
			//    {
			//	getnum(mine, show, i, j, win);
			//    }
			}
	    }
	}

	show[x][y] = num + '0';
	return win++;
}
#include"ɨ��.h"//�ǵ�����ͷ�ļ�

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
	//��ӡ�к�
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
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
		int x = rand()%row+1;//1��9
		int y = rand()%col+1;//1��9
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
		printf("��������Ҫ�Ų������\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y]=='*')
		{    
			if (mine[x][y] == '1')
			{
				printf("���ź������ˣ��㱻ը����\n");
				displayboard(mine, row, col);
				break;//����test���do whileѭ��
			}
			else {//��������׾�Ҫͳ����Χ�м�����
				key=getnum(mine,show,x, y,win);
				displayboard(show, row, col);

			}
		}
		else {
			printf("���겻�Ϸ�������������\n");
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
			{num += mine[i][j] - '0';//���������ַ�0 �����ַ�1 �����ַ���ȥ�ַ�0���ڸ����� ��'1'-'0'=1
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
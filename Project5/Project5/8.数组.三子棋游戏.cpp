#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>
#include"8.����.��������Ϸ.h"//�ǵ�����ͷ�ļ�

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
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);//��ӡһ������  ����д��%c | %c | %c ��ʹ�ò����趨����Ϊʲô���Ĺ�� ��ֻ������
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//��ӡһ�е�����
			printf(" %c ", board[i][j]);
			if (j < col - 1)//���һ�в���ӡ|
				printf("|");
		}
		printf("\n");

		if (i < row - 1)
		{//��ӡ�ָ���
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
	printf("�������\n");
	while (1)//�������겻�Ϸ���������
	{
		printf("����Ҫ���ӵ�����\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')//���������û�б������
			{
				board[x - 1][y - 1] = '*';//����*
				break;
			}
			else
			{
				printf("������Ҳ��ռ�ã��뻻һ��\n");
			}
		}

		else
		{
			printf("������Ƿ����뻻һ��\n");
		}
	}
}


void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��������");

	while (1)
	{
		x = rand() % row;//���������%row ������һ���Ϸ����������
		y = rand() % col;//Ȼ��������ҪΪ�����Ѱ��һ��ʱ�̲�ͬ������ ��֮ǰ������һ�� ���ӵ���������û�з������������ �����ڱ�ֻ����һ�ε�test��������������
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
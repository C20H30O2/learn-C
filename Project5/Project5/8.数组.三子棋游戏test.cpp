#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>

#include "8.����.��������Ϸ.h"//�����Լ���ͷ�ļ�

void menu()
{
	printf("*****1.play 0.exit*****\n");
}


//������Ϸ�㷨��ʵ��
void game()
{
	char ret = 0;//���ڽ����ж���Ӯ�����ķ���ֵ

	//��������洢��Ϸ��������Ϣ
	//char board[3][3] = { 0 };//��������� ��ֹ���ڿ��ܳ��ֵ�һЩ����
	char board[ROW][COL] = { 0 };//��ͷ�ļ��ж�����ص����������ڸ��� ����ֻҪ��ͷ�ļ����и��ľ��У� �ǵ�Ҫ����ͷ�ļ�
    
	//��ʼʱ ������Ҳ���������ϵ������ǿո���� ������ҹ۲� ������������һ��������������г�ʼ��
	intboard(board, ROW, COL);//�������������Ϸģ������� ������ͷ�ļ��н������� ����Ϸ.cpp�ļ��ж���
	//��ʵ�ڳ�ʼ���и�����0 Ҳ��һ�ֲ��ɴ�ӡ�ַ� ���ʹ����������㲻����������������ʼ�� ��ӡ������������Ҳ��û�ж�����
	//�����0���������ַ� �����ε�intboard ��ô�����Ͼͻ��ж���

	//ϣ����ӡ�������̵�����
	//    |   |       ��һ��  ÿһ�������Ϊ �ո���ſո�  
	// ---|---|---
	//    |   |       �ڶ���
	// ---|---|---
	//    |   |       ������  �������һ���Ź���
	//���� �ú�����ӡ������ʼ���������
	display_board(board,ROW,COL);//ͬ����ͷ�ļ����� ����Ϸ.cpp��ʵ��

	//����
	while (1)//ֱ���ֳ�ʤ��������ѭ��
	{
		//���������
		playermove(board,ROW,COL);
		//��ʾ����¹���������
		display_board(board, ROW, COL);

		//�ж�һ����Ӯ
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}


		//��������
		computermove(board, ROW, COL);
		display_board(board, ROW, COL);

		//�ж�һ����Ӯ
		ret = iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("���ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("����ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}


}


void test()
{
	srand((unsigned int)time(NULL));//�ǵ�Ҫ����ͷ�ļ�#include<stdlib.h>��#include<time.h>  ����ʱ�����������

	int input = 0;
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);//��input��Ϊִ���ж����� Ϊ0�ͻ��˳�
}



int main()
{
	test();
	return 0;
}

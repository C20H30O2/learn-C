#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>//����ֱ����ͷ�ļ������� ����������
#include<time.h>


#define ROW 3//�������� ���Է���������̹�� ֻ��Ҫ����������޸ľ���
#define COL 3



void intboard(char board[ROW][COL], int row, int col);//��������
void display_board(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);


//������Ҫ���������������״̬ ���win ����win ƽ�� ����  �ֱ𷵻�* # Q C 
char iswin(char board[ROW][COL], int row, int col);
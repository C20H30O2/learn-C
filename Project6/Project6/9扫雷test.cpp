#include"ɨ��.h"//�ǵ�����ͷ�ļ�


void menu()
{
	printf("*********\n");
	printf("1.play  0.exit\n");

}



void game()
{
	printf("ɨ��\n");
	char mine[ROWS][COLS] = { 0 };//��Ϸ����//�趨��Ϸ��ģʱ ����9*9�����������11*11���趨 ���ڼ���Ե����������û����
	char show[ROWS][COLS] = { 0 };//������ʾ��Ϣ������
	
	//��ʼ��
	initboard(mine, ROWS, COLS,'0');
	initboard(show, ROWS, COLS,'*');//��Ҫ��ʼ�����ַ�Ҳ��Ϊ�������� �������ڲ�ͬ����ı���������ͬ�ĺ����õ���ͬ���

	//��ӡ����
	//displayboard(mine, ROW, COL);//ֻ��ʾ��Ϸ��ģ��С������ Ϊ�˷���������ȥ�Ĳ��ֲ���ʾ
	displayboard(show, ROW, COL);//ֻ��ʾ��Ϸ��ģ��С������ Ϊ�˷���������ȥ�Ĳ��ֲ���ʾ

	//������
	set(mine, ROW, COL);
	//displayboard(mine, ROW, COL);//������ʹ�� ��Ϸʱ����ӡ


	//ɨ��
	find(mine, show, ROW, COL);

}


void test()
{
	srand((unsigned int)time(NULL));//�趨���������

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
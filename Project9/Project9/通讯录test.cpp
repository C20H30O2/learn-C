


#include<stdio.h>

#include"ͨѶ¼.h"
void menu()
{
	printf("*******************************\n");
	printf("*******1.add    2.del    ******\n");
	printf("*******3.search 4.modify ******\n");
	printf("*******5.show   6.sort   ******\n");
	printf("*******0.exit            ******\n");
	
}


int main()
{
	int input = 0;

	//����һ�����Դ洢MAX����Ϣ��ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��->");
		scanf_s("%d", &input);//��֪��Ϊʲô��������������scanf_s����
		switch (input)
		{
		case add:
			AddContact(&con);
			break;
		case del:
			DeleteContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case show:
			ShowContact(&con);
			break;
		case sort:
			SortContact(&con);
			break;
		case exit:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
#include"ͨѶ¼�Ľ���+д���ļ�.h"
void menu()
{
	printf("*******************************\n");
	printf("*******1.add    2.del    ******\n");
	printf("*******3.search 4.modify ******\n");
	printf("*******5.show   6.sort   ******\n");
	printf("*******7.save   0.exit    ******\n");

}


int main()
{
	int input = 0;

	//����һ��ͨѶ¼
	struct Contact con;//�����������һ��ָ��ͨѶ¼��ָ�룬һ����ʾ��ǰ��Ϣ������size��һ����ʾ��ǰ������capacity
	//��ʼ��ͨѶ¼������ȡ֮ǰ�����ͨѶ¼�ļ����ݣ���������Ҫ�������ʼ���������һЩ����
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
		case save:
			SaveContact(&con);
			break;
		case end:
			SaveContact(&con);//ѡ���˳�֮ǰҲ����һ�α���
			to_free(&con);//����Ҫ�������һ�����������ͷſռ�
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
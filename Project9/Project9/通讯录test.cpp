


#include<stdio.h>

#include"通讯录.h"
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

	//创建一个可以存储MAX条信息的通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择->");
		scanf_s("%d", &input);//不知道为什么这里的输入必须用scanf_s才行
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
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
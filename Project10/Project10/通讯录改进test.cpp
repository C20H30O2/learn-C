#include"通讯录改进版+写入文件.h"
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

	//创建一个通讯录
	struct Contact con;//现在里面包括一个指向通讯录的指针，一个表示当前信息条数的size，一个表示当前容量的capacity
	//初始化通讯录，并读取之前保存的通讯录文件数据，所以这里要对这个初始化函数添加一些功能
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
		case save:
			SaveContact(&con);
			break;
		case end:
			SaveContact(&con);//选择退出之前也进行一次保存
			to_free(&con);//还需要额外添加一个函数用来释放空间
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
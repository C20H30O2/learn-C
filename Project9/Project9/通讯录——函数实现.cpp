#include"通讯录.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));//利用memset函数直接将data里的元素初始化为0
	ps->size = 0;//此时通讯录中有0个元素
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", ps->data[ps->size].name);		
		printf("请输入年龄:>");
		scanf("%d",&(ps->data[ps->size].age));//对于字符串不用取地址，二age是int类型，不对它取地址就会报错
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);		
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);		
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].addr);
	
		ps->size++;
		printf("添加成功\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录中没有信息\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");// \t是水平制表符，可以让上下行对齐，符号和数字都是对齐的参数，符号表示左对齐，不加符号则默认右对齐
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
		
	}
}



static int find_by_name(const struct Contact* ps, char name[MAX_NAME])//因为这个查找函数只需要在本文件内部使用，不需要在头文件中声明，使用static修饰使得这个函数只能在本文件中被查找
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;//找到了就返回其下标
		}
	}
	return -1;//找不到的情况下返回-1
}


void DeleteContact(struct Contact* ps)//删除元素有两种实现方式，1：让要删除项后面的每个元素都向前移动一位，要删除项就被覆盖掉了 
                                                              //2：直接让最后一项信息（下标为size）替换到要删除项的位置  这里采用的是第一种方法
{
	char name  [MAX_NAME];
	printf("请输入要删除的姓名\n");
	scanf("%s", &name);
	
	//第一步查找到要删除元素的下标，可以遍历data中的size个元素，找到对应的name
	//注意：比较字符串使用的是strcmp，返回0时相等
	//因为要多次使用到查找的功能，为了避免代码冗余，我们将find封装为一个函数
	int pos = find_by_name(ps,name);//我们让这个函数找到时返回查找的元素的下标，没找到直接返回-1
	
	
	//第二步将查找到的元素之后的元素向前移动，将查找到的元素覆盖
	if (pos == -1)
	{
		printf("查找的姓名不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size -= 1;
		printf("删除成功\n");
	}
}


void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的姓名\n");
	int pos = find_by_name(ps, name);//利用函数查找

	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else//找到了就打印信息
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");// \t是水平制表符，可以让上下行对齐，符号和数字都是对齐的参数，符号表示左对齐，不加符号则默认右对齐
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);

	}

}


void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改的姓名\n");
	scanf("%s", &name);
	int pos = find_by_name(ps, name);
	if (-1 ==pos )
	{
		printf("该姓名不存在\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].addr);
	}
}

void SortContact(struct Contact* ps)
{

}
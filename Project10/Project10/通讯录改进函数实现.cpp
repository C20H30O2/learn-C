#include"通讯录改进版+写入文件.h"

void InitContact(struct Contact* ps)
{
	ps->data =(struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));//初始化时先向data指向的通讯录空间中开辟存储3条信息的空间
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;//设置默认值


	//将之前保存的数据加载
	LoadContact(ps);//需要再创建一个加载数据的函数

}




int checkcapacity(struct Contact* ps);//因为在Load函数中使用到了check函数，但是load函数写在了check函数之前，为了方便，直接进行声明即可
//新增函数读取文件
void LoadContact(struct Contact* ps)
{
	PeoInfo tmp = { 0 };//创建一个PeoInfo类型的临时变量，从文件中读取一条通讯录数据存储进该临时变量中，再把临时变量中的信息存储入当前的通讯录中

	FILE* pfread = fopen("contact.dat", "rb");//rb以二进制打开文件
	if (pfread == NULL)
	{
		printf("LoadContact：%s\n", strerror(errno));//为了区分Save函数和Load函数的报错，在打印时添加上其函数名LoadContact
	}

	//读取文件
	while (fread(&tmp, sizeof(PeoInfo), 1, pfread))//fread函数的返回值是其实际读取到的元素个数，比如如果我们将一次读取1条数据该为一次读取十条数据，而pfread指向的contact.dat文件中的剩余数据只有五条时，就会返回5，表示实际只读到了五条数据
	{                                           //利用fread的返回值，我们每次读取一条通讯录数据，当文件中没有剩余数据时就会返回0，此时就可以停止读取
		checkcapacity(ps);//当前的通讯录经过初始化，一开始只能存储三条通讯录数据，所以在读取时要进行容量判断，容量不够时就要扩容
		ps->data[ps->size]=tmp;
		ps->size += 1;//每存入一条数据记得让size增加
	}
	

	fclose(pfread);
	pfread = NULL;
}




int checkcapacity(struct Contact* ps)
{
	if (ps->capacity == ps->size)
	{
		struct PeoInfo* ptr=(struct PeoInfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));//容量加2
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("内存已满，但是扩容成功，可以继续添加信息");
			return 1;
		}
		else
		{
			printf("当下内存已满，而且扩容失败，无法添加新信息");
			return 0;
		}
	}
	return 1;
}



void AddContact(struct Contact* ps)
{
	//if (ps->size == MAX)
	//{
	//	printf("通讯录已满，无法添加\n");
	//}
	//else
	//{
	//	printf("请输入姓名:>");
	//	scanf("%s", ps->data[ps->size].name);
	//	printf("请输入年龄:>");
	//	scanf("%d", &(ps->data[ps->size].age));//对于字符串不用取地址，二age是int类型，不对它取地址就会报错
	//	printf("请输入性别:>");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("请输入电话:>");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("请输入地址:>");
	//	scanf("%s", ps->data[ps->size].addr);

	//	ps->size++;
	//	printf("添加成功\n");
	//}


	int ret=checkcapacity(ps);//判断容量是否足够，如果容量已满就进行扩容
	if (ret == 1)
	{
		printf("请输入姓名:>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));//对于字符串不用取地址，二age是int类型，不对它取地址就会报错
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].addr);
		
		
		ps->size++;
	    printf("添加成功\n");
	}
	else
	{
		printf("内存已满且扩容失败，无法继续添加信息");
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
	char name[MAX_NAME];
	printf("请输入要删除的姓名\n");
	scanf("%s", &name);

	//第一步查找到要删除元素的下标，可以遍历data中的size个元素，找到对应的name
	//注意：比较字符串使用的是strcmp，返回0时相等
	//因为要多次使用到查找的功能，为了避免代码冗余，我们将find封装为一个函数
	int pos = find_by_name(ps, name);//我们让这个函数找到时返回查找的元素的下标，没找到直接返回-1


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
	int pos;
	printf("请输入要查找的姓名\n");
	pos = find_by_name(ps, name);//利用函数查找

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
	int pos;
	printf("请输入要修改的姓名\n");
	scanf("%s", &name);
	pos = find_by_name(ps, name);
	if (-1 == pos)
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



void to_free(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}



void SaveContact(const struct Contact* ps)
{
	FILE* pfwrite = fopen("contact.dat","wb");//wb是以二进制打开文件
	if (pfwrite == NULL)
	{
		printf("SaveContact：%s\n", strerror(errno));//为了区分Save函数和Load函数的报错，在打印时添加上其函数名SaveContact
		return ;
	}

	//打开成功时就写入文件
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfwrite);
	}

	fclose(pfwrite);
	pfwrite = NULL;
}
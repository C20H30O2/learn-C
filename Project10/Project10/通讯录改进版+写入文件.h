#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

//利用动态内存分配改进程序
//默认存储三个人的信息，当内存满时可以扩容，一次增加两个信息的空间


//#define MAX 1000//因为要让内存可以动态变化，以提高内存利用率，所以这里不再为通讯录设置单一的大小
#define		DEFAULT_SZ 3  //设置默认的容量初始大小

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30//将一些参数在此设定，便于之后的修改


enum option//利用枚举使得操作选项和数字对应起来，方便自己查看
{
	end,
	add,
	del,
	search,
	modify,
	show,
	sort,
	save//我们添加了一个保存的选项，然后还要添加将数据保存入文件的函数，可以在用户选择save是调用，也可以在用户选择退出时自动调用
};

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};//创建一个结构体存储信息


struct Contact
{
	struct PeoInfo* data;//改为结构体指针
	int size;//size用来存储通讯录中已有的信息条数
	int capacity;//新加一个变量表示当前的总容量，结合已有信息条数，在适当的时候进行扩容
};


//声明函数
void InitContact(struct Contact* ps);//初始化通讯录
void AddContact(struct Contact* ps);//追加一条信息到通讯录
void ShowContact(const struct Contact* ps);//显示通讯录
void DeleteContact(struct Contact* ps);//删除指定姓名的信息
void SearchContact(const struct Contact* ps);//查找指定姓名的信息
void ModifyContact(struct Contact* ps);//修改指定姓名的信息
void SortContact(struct Contact* ps);//排序
void to_free(struct Contact* ps);//释放空间
void SaveContact(const struct Contact* ps);//保存数据到文件中
void LoadContact(struct Contact* ps);//读取文件
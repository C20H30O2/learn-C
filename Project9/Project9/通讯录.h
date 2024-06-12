#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30//将一些参数在此设定，便于之后的修改


enum option//利用枚举使得操作选项和数字对应起来，方便自己查看
{
	exit,
	add,
	del,
	search,
	modify,
	show,
	sort
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
	struct PeoInfo data[MAX];
	int size;//size用来存储通讯录中已有的信息条数
};


//声明函数
void InitContact(struct Contact* ps);//初始化通讯录
void AddContact(struct Contact* ps);//追加一条信息到通讯录
void ShowContact(const struct Contact* ps);//显示通讯录
void DeleteContact(struct Contact* ps);//删除指定姓名的信息
void SearchContact(const struct Contact* ps);//查找指定姓名的信息
void ModifyContact(struct Contact* ps);//修改指定姓名的信息
void SortContact(struct Contact* ps);//排序
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30//��һЩ�����ڴ��趨������֮����޸�


enum option//����ö��ʹ�ò���ѡ������ֶ�Ӧ�����������Լ��鿴
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
};//����һ���ṹ��洢��Ϣ


struct Contact
{
	struct PeoInfo data[MAX];
	int size;//size�����洢ͨѶ¼�����е���Ϣ����
};


//��������
void InitContact(struct Contact* ps);//��ʼ��ͨѶ¼
void AddContact(struct Contact* ps);//׷��һ����Ϣ��ͨѶ¼
void ShowContact(const struct Contact* ps);//��ʾͨѶ¼
void DeleteContact(struct Contact* ps);//ɾ��ָ����������Ϣ
void SearchContact(const struct Contact* ps);//����ָ����������Ϣ
void ModifyContact(struct Contact* ps);//�޸�ָ����������Ϣ
void SortContact(struct Contact* ps);//����
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

//���ö�̬�ڴ����Ľ�����
//Ĭ�ϴ洢�����˵���Ϣ�����ڴ���ʱ�������ݣ�һ������������Ϣ�Ŀռ�


//#define MAX 1000//��ΪҪ���ڴ���Զ�̬�仯��������ڴ������ʣ��������ﲻ��ΪͨѶ¼���õ�һ�Ĵ�С
#define		DEFAULT_SZ 3  //����Ĭ�ϵ�������ʼ��С

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30//��һЩ�����ڴ��趨������֮����޸�


enum option//����ö��ʹ�ò���ѡ������ֶ�Ӧ�����������Լ��鿴
{
	end,
	add,
	del,
	search,
	modify,
	show,
	sort,
	save//���������һ�������ѡ�Ȼ��Ҫ��ӽ����ݱ������ļ��ĺ������������û�ѡ��save�ǵ��ã�Ҳ�������û�ѡ���˳�ʱ�Զ�����
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
	struct PeoInfo* data;//��Ϊ�ṹ��ָ��
	int size;//size�����洢ͨѶ¼�����е���Ϣ����
	int capacity;//�¼�һ��������ʾ��ǰ�������������������Ϣ���������ʵ���ʱ���������
};


//��������
void InitContact(struct Contact* ps);//��ʼ��ͨѶ¼
void AddContact(struct Contact* ps);//׷��һ����Ϣ��ͨѶ¼
void ShowContact(const struct Contact* ps);//��ʾͨѶ¼
void DeleteContact(struct Contact* ps);//ɾ��ָ����������Ϣ
void SearchContact(const struct Contact* ps);//����ָ����������Ϣ
void ModifyContact(struct Contact* ps);//�޸�ָ����������Ϣ
void SortContact(struct Contact* ps);//����
void to_free(struct Contact* ps);//�ͷſռ�
void SaveContact(const struct Contact* ps);//�������ݵ��ļ���
void LoadContact(struct Contact* ps);//��ȡ�ļ�
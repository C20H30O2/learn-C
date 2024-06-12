#include"ͨѶ¼.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));//����memset����ֱ�ӽ�data���Ԫ�س�ʼ��Ϊ0
	ps->size = 0;//��ʱͨѶ¼����0��Ԫ��
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);		
		printf("����������:>");
		scanf("%d",&(ps->data[ps->size].age));//�����ַ�������ȡ��ַ����age��int���ͣ�������ȡ��ַ�ͻᱨ��
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);		
		printf("������绰:>");
		scanf("%s", ps->data[ps->size].tele);		
		printf("�������ַ:>");
		scanf("%s", ps->data[ps->size].addr);
	
		ps->size++;
		printf("��ӳɹ�\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼��û����Ϣ\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");// \t��ˮƽ�Ʊ���������������ж��룬���ź����ֶ��Ƕ���Ĳ��������ű�ʾ����룬���ӷ�����Ĭ���Ҷ���
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



static int find_by_name(const struct Contact* ps, char name[MAX_NAME])//��Ϊ������Һ���ֻ��Ҫ�ڱ��ļ��ڲ�ʹ�ã�����Ҫ��ͷ�ļ���������ʹ��static����ʹ���������ֻ���ڱ��ļ��б�����
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;//�ҵ��˾ͷ������±�
		}
	}
	return -1;//�Ҳ���������·���-1
}


void DeleteContact(struct Contact* ps)//ɾ��Ԫ��������ʵ�ַ�ʽ��1����Ҫɾ��������ÿ��Ԫ�ض���ǰ�ƶ�һλ��Ҫɾ����ͱ����ǵ��� 
                                                              //2��ֱ�������һ����Ϣ���±�Ϊsize���滻��Ҫɾ�����λ��  ������õ��ǵ�һ�ַ���
{
	char name  [MAX_NAME];
	printf("������Ҫɾ��������\n");
	scanf("%s", &name);
	
	//��һ�����ҵ�Ҫɾ��Ԫ�ص��±꣬���Ա���data�е�size��Ԫ�أ��ҵ���Ӧ��name
	//ע�⣺�Ƚ��ַ���ʹ�õ���strcmp������0ʱ���
	//��ΪҪ���ʹ�õ����ҵĹ��ܣ�Ϊ�˱���������࣬���ǽ�find��װΪһ������
	int pos = find_by_name(ps,name);//��������������ҵ�ʱ���ز��ҵ�Ԫ�ص��±꣬û�ҵ�ֱ�ӷ���-1
	
	
	//�ڶ��������ҵ���Ԫ��֮���Ԫ����ǰ�ƶ��������ҵ���Ԫ�ظ���
	if (pos == -1)
	{
		printf("���ҵ�����������\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size -= 1;
		printf("ɾ���ɹ�\n");
	}
}


void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ�����\n");
	int pos = find_by_name(ps, name);//���ú�������

	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else//�ҵ��˾ʹ�ӡ��Ϣ
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");// \t��ˮƽ�Ʊ���������������ж��룬���ź����ֶ��Ƕ���Ĳ��������ű�ʾ����룬���ӷ�����Ĭ���Ҷ���
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
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%s", &name);
	int pos = find_by_name(ps, name);
	if (-1 ==pos )
	{
		printf("������������\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		printf("����������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos].addr);
	}
}

void SortContact(struct Contact* ps)
{

}
#include"ͨѶ¼�Ľ���+д���ļ�.h"

void InitContact(struct Contact* ps)
{
	ps->data =(struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));//��ʼ��ʱ����dataָ���ͨѶ¼�ռ��п��ٴ洢3����Ϣ�Ŀռ�
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;//����Ĭ��ֵ


	//��֮ǰ��������ݼ���
	LoadContact(ps);//��Ҫ�ٴ���һ���������ݵĺ���

}




int checkcapacity(struct Contact* ps);//��Ϊ��Load������ʹ�õ���check����������load����д����check����֮ǰ��Ϊ�˷��㣬ֱ�ӽ�����������
//����������ȡ�ļ�
void LoadContact(struct Contact* ps)
{
	PeoInfo tmp = { 0 };//����һ��PeoInfo���͵���ʱ���������ļ��ж�ȡһ��ͨѶ¼���ݴ洢������ʱ�����У��ٰ���ʱ�����е���Ϣ�洢�뵱ǰ��ͨѶ¼��

	FILE* pfread = fopen("contact.dat", "rb");//rb�Զ����ƴ��ļ�
	if (pfread == NULL)
	{
		printf("LoadContact��%s\n", strerror(errno));//Ϊ������Save������Load�����ı����ڴ�ӡʱ������亯����LoadContact
	}

	//��ȡ�ļ�
	while (fread(&tmp, sizeof(PeoInfo), 1, pfread))//fread�����ķ���ֵ����ʵ�ʶ�ȡ����Ԫ�ظ���������������ǽ�һ�ζ�ȡ1�����ݸ�Ϊһ�ζ�ȡʮ�����ݣ���pfreadָ���contact.dat�ļ��е�ʣ������ֻ������ʱ���ͻ᷵��5����ʾʵ��ֻ��������������
	{                                           //����fread�ķ���ֵ������ÿ�ζ�ȡһ��ͨѶ¼���ݣ����ļ���û��ʣ������ʱ�ͻ᷵��0����ʱ�Ϳ���ֹͣ��ȡ
		checkcapacity(ps);//��ǰ��ͨѶ¼������ʼ����һ��ʼֻ�ܴ洢����ͨѶ¼���ݣ������ڶ�ȡʱҪ���������жϣ���������ʱ��Ҫ����
		ps->data[ps->size]=tmp;
		ps->size += 1;//ÿ����һ�����ݼǵ���size����
	}
	

	fclose(pfread);
	pfread = NULL;
}




int checkcapacity(struct Contact* ps)
{
	if (ps->capacity == ps->size)
	{
		struct PeoInfo* ptr=(struct PeoInfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));//������2
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("�ڴ��������������ݳɹ������Լ��������Ϣ");
			return 1;
		}
		else
		{
			printf("�����ڴ���������������ʧ�ܣ��޷��������Ϣ");
			return 0;
		}
	}
	return 1;
}



void AddContact(struct Contact* ps)
{
	//if (ps->size == MAX)
	//{
	//	printf("ͨѶ¼�������޷����\n");
	//}
	//else
	//{
	//	printf("����������:>");
	//	scanf("%s", ps->data[ps->size].name);
	//	printf("����������:>");
	//	scanf("%d", &(ps->data[ps->size].age));//�����ַ�������ȡ��ַ����age��int���ͣ�������ȡ��ַ�ͻᱨ��
	//	printf("�������Ա�:>");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("������绰:>");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("�������ַ:>");
	//	scanf("%s", ps->data[ps->size].addr);

	//	ps->size++;
	//	printf("��ӳɹ�\n");
	//}


	int ret=checkcapacity(ps);//�ж������Ƿ��㹻��������������ͽ�������
	if (ret == 1)
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->size].age));//�����ַ�������ȡ��ַ����age��int���ͣ�������ȡ��ַ�ͻᱨ��
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[ps->size].addr);
		
		
		ps->size++;
	    printf("��ӳɹ�\n");
	}
	else
	{
		printf("�ڴ�����������ʧ�ܣ��޷����������Ϣ");
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
	char name[MAX_NAME];
	printf("������Ҫɾ��������\n");
	scanf("%s", &name);

	//��һ�����ҵ�Ҫɾ��Ԫ�ص��±꣬���Ա���data�е�size��Ԫ�أ��ҵ���Ӧ��name
	//ע�⣺�Ƚ��ַ���ʹ�õ���strcmp������0ʱ���
	//��ΪҪ���ʹ�õ����ҵĹ��ܣ�Ϊ�˱���������࣬���ǽ�find��װΪһ������
	int pos = find_by_name(ps, name);//��������������ҵ�ʱ���ز��ҵ�Ԫ�ص��±꣬û�ҵ�ֱ�ӷ���-1


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
	int pos;
	printf("������Ҫ���ҵ�����\n");
	pos = find_by_name(ps, name);//���ú�������

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
	int pos;
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%s", &name);
	pos = find_by_name(ps, name);
	if (-1 == pos)
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



void to_free(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}



void SaveContact(const struct Contact* ps)
{
	FILE* pfwrite = fopen("contact.dat","wb");//wb���Զ����ƴ��ļ�
	if (pfwrite == NULL)
	{
		printf("SaveContact��%s\n", strerror(errno));//Ϊ������Save������Load�����ı����ڴ�ӡʱ������亯����SaveContact
		return ;
	}

	//�򿪳ɹ�ʱ��д���ļ�
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfwrite);
	}

	fclose(pfwrite);
	pfwrite = NULL;
}
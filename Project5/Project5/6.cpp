#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

//ͬʱ���������ֵ�д��
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d#%d#%d", &a, &b, &c);//Ҫע�������ʽ ����1 2 3   ���д����scanf("%d#%d#%d", &a, &b, &c);���밴1#2#3��ʽ���� #�Ż�����������ͬ��
//	printf("%d %d %d", a, b, c);//               ���1 2 3                                               �����������1 2 3
//}



//�������������Լ�� շת�����
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d", &a, &b);
//	if (a < b)
//	{
//		c = a;
//		a = b;
//		b = c;
//
//	}
//	//while (true)
//	//{
//	//	c = a % b;
//	//	if (c == 0)
//	//	{
//	//		printf("���Լ����%d", b);
//	//		break;
//	//	}
//	//	a = b;
//	//	b = c;
//	//}
//	//return 0;
//
//
//	//����Ч�ʵ�д��
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("���Լ����%d", b);
//}


//��ӡ�žų˷���

//int main()
//{
//	int a = 1;
//	int b = 0;
//	for (a = 1; a <= 9; a++)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			printf("%d*%d=%d\t", a, b, a * b);
//			if (b == a)
//			{
//				printf("\n");
//			}
//		}
//	 }
//	return 0;
//}



//��������Ϸ

//��������� rand()����
//void menu()
//int main()
//{
//	int a = 0;
//	int ran = 0;
//	//srand(1);//�������� ��������������� ������Ҫ����ʱ�̶��ڱ仯��ʱ�䴫��һ������������Ա�֤����� ʹ��ʱ���
//	//ʱ��� ���ü�����ĵ�ǰʱ���ȥ1970��һ��һ�յĲ�ֵ��ת��Ϊ��
//	//Ҫʹ��time����  Ҫ����#include<time.h>
//	srand((unsigned int)time(NULL)); //��time����NULL������ԭ����������˽�time������ ��time�����ķ���ֵת��Ϊunsigned int����  
//	//���ÿ�����������֮ǰ������һ������ ������Ի�Ƚ��� ����������while�Ѷ��߷ֿ���
//	while (true)
//	{
//		scanf("%d", &a);
//		if (a == 1)
//		{
//			ran = rand()%100;//�����ȡ�������� ��ͬ���ӵ��������ͬ %100�Ա�֤���ֽ�С �ò�
//			printf("%d\t", ran);
//		}
//	}
//	return 0;
//}
//���������ѵĲ��־�������� �����Ĳ����Ҿ�������




//C�����е�goto���
//int main()
//{
//	//again:
//	printf("nihao");
//	goto again;//�ص�goto��ı�Ǵ�  goto�����ܻᵼ�³��� һ���ܲ��þͲ��� 
//	           //��Ҳ�к��õĵط� �����ڶ��Ƕ���� ��Ҫ���������ʱ�������ʹ��break ֻ�����ڲ�������goto ����ȥ��Ҫȥ�ĵط�
//	printf("nihao1");
//again:
//	return 0;

//}

//for ()//ʹ��ʾ��
//{
//	for ()
//	{
//		for ()
//		{
//			if (��������)
//			{
//				goto fix;
//			}
//		}
//	}
//}
//fix:
//����





//��Ȥ�Ĺػ�����
//cmd command������
//int main()
//{
//	char input[20] = { 0 };
//	//shotdown -s -t 60//��cmd��������һ�л�ʹ��������ʮ���ػ�
//	//shotdown -a  ����ȡ���ػ�
//	//C��������һ��system���� ����ִ��ϵͳ����
//	system("shutdown -s -t 60");//ע��Ҫ����stdlib.h
//again:
//	printf("warning ��ĵ��Խ���60���ر�\t ������� ����** ����ȡ���ػ�");
//	scanf("%s", input);
//	if (strcmp("����**", input)==0)//�ַ����ıȽ�Ҫʹ������ĺ��� ��Ҫ����#include<string.h> 
//	{
//		system("shutdown -a");
//
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;//�������������ȫ������ѭ������goto
//}
//���Խ������д��һ��.exe�ļ�  �ٽ����ļ����� ϵͳ���� �� �������Ϊ�Զ����� ���ڿ���ʱ���Զ�����һ���Ӻ�ػ���ָ��




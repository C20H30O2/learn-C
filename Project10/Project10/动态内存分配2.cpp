#define _CRT_SECURE_NO_WARNINGS 
#include<stdlib.h>//malloc �ȶ�̬�ڴ���亯��
#include<string.h>//strcpy���ַ�������
#include<stdio.h>//printf


//��������
//C99�У��ṹ�е����һ��Ԫ��������δ֪��С�����飬��ͽ������������Ա
//struct s1
//{
//	int n;
//	int arr[];
//};
//
//struct s2
//{
//	int n;
//	int arr[0];
//};
////��������������������ַ�ʽ�������ַ�����ʹarr��Ϊ�������飬�����ַ�����һ���ģ����һ�ֲ����ÿ���������һ��
//
//int main()
//{
//	printf("%d\n", sizeof(s1));//�����С��ֻ������int��Ա�Ĵ�С
//	printf("%d\n", sizeof(s2));//���Է�����������Ĵ�С�ǲ����������ڵ�
//
//
//	//ʹ����������
//	struct s1* ps = (struct s1*)malloc(sizeof(struct s1) + 5 * sizeof(int));
//	//�������������mallocΪһ��struct s1���Ϳ�����һ�鶯̬�ռ䣬�����һ��ָ���struct s1���͵�ָ�룬����ռ��С�п��Կ���������Ϊarr�ṩ��5��int�Ŀռ�
//	//����Ҳ����֪�����ڸÿռ��У�n�ĺ��������arr������֮��û�н����ڴ����
//	
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;//�ڵ����е��ڴ��������ps���Կ���psָ��ռ���n�ı仯��arr�����ݵı仯
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//
//
//	//������С
//	realloc(ps, sizeof(struct s1) + 10 * sizeof(int));//ʹ�ö�̬�ڴ���亯��Ӧ����һ��ʼһ��С��һЩ������������Ϊ��ʾ��ʡ��һЩ����
//
//
//	//�ͷ�
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}






//�Լ�Ҳ������һ�ַ�ʽʵ����������
struct s
{
	int n;
	int* arr;
};

int main()
{
	struct s* ps = (struct s*)malloc(sizeof(struct s));
	ps->arr =(int*) malloc(5 * sizeof(int));
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ps->arr[i]);
	}


	//������С
	int* ret=(int*)realloc(ps->arr, 10 * sizeof(int));
	if (ret != NULL)
	{
		ps->arr = ret;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}

	//�ͷ��ڴ�
	free(ps->arr);
	free(ps);//ע�⣺һ��Ҫ���ͷ�ps->arr ��Ϊarr�洢��psָ��Ŀռ��У�������ͷ�ps��arr���޷��һ���
	return 0;
}
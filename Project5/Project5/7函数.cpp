#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>


//���������parameter���������return value������ֵ�� ����ͨ������װ
//int add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = 0;
//	sum=add(a, b);
//	printf("%d", sum);
//	return 0;
//}



//C�����к��������� �⺯����C�����Դ��ĺ����� �Զ��庯��  www.cplusplus.com���Բ鿴 ��ͺ�����function����˵���ĵ�   
//C�����г��õĺ��� IO������input��output �� ���ַ����������� ��strlen���ַ������������жϴ�Сд ��Сдת���ȣ��ڴ����������ʱ��/���ں�������ѧ��������ѧ����ȣ�
//Ҫѧ���Ķ��ĵ�ѧϰ����  Ҳ����ʹ��MSDN   cppreference.com     zh,cppreference.com���İ���վ


//int main()
//{   //strlen���� ���ַ�������
//	//strcpy���� �ַ������� ��www.cplusplus.com��strcpyҳ����Կ��� char * strcpy ( char * destination,conat char * source)�������������ʾ��source �����ַ�������destination��
//	char arr1[] = "hello";//�����в鿴�� ������Ϊ hello\0
//	char arr2[] = "#########";//                  #########\0
//	//���������arr1��arr2���� ������ �ͻ�bug
//	strcpy(arr2, arr1);//ʵ�ʿ�����arr2������Ϊ hello\0###  ����ӡֻ��ӡ��������־\0ǰ������ ���ַ�������ʱҲֻ���㵽\0֮ǰ
//	printf("%s\n", arr2);//�������Լ��� ���ֻ���ԭ�ַ��Ľ�����־\0һ�𿽱���Ŀ���ַ�����
//
//	//memset �ڴ����� 
//	//memory �ڴ�
//	char arr3[] = "#########";
//	memset(arr3, '*', 5);//��Ҫ����*�滻��arr3��ǰ����ַ� 
//	printf("%s\n", arr3);
//	return 0;
//}
//
//
//
////ѧ���Զ��庯��Ҳ����Ҫ
//
////���������
//int add(int x, int y)//addΪ������ int�Ǻ����ķ������ͣ�����˴���дvoid����˼�Ǹú���û�з���ֵ�� add���������ڵ�����ʽ����
//{//��������Ϊ������ ��������������ʵ�ֵ�
//	int z = 0;
//	z = x + y;
//	return z;//�����ķ���ֵ
//}


//�򵥺�������ϰ  1.��������Ľϴ�ֵ���ܼ򵥣����������   2.����������ֵ���н������˺����޷���ֵ������ֵ������void��

//void change(int* p1, int* p2)//�����Ĵ�ַ���� ע����������ȡ��Ҫ�޸ĵ����ĵ�ַ ��ͨ����ַ�����ֽ����޸� 
//{
//	int num = *p1;
//	*p1 = *p2;
//	*p2 = num;
//}
//
//
////void change* (int x, int y)//�����Ĵ�ֵ���� ����д��û���õ� �ں������õ�ʱ�����������Ŀռ䴢��x y �����a b����Ӱ��
////{
////	int num = x;
////	x = y;
////	y = num;
////}
//
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	change(&a, &b);
//	printf("%d %d", a, b);
//}


//�ж��Ƿ��������ĺ���
//#include<math.h>
//int if_prime(int a)
//{
//	int i = 0;
//	for (i = 2; i < sqrt(a); i++)//�������е�a ��a���п������Լ��ټ�����
//	{
//		if (a % i == 0)
//		{
//			return 0;//����������� �ͻ�ֱ�ӷ���0 return֮��Ͳ���ִ�к��������
//		}
//	}
//	return 1;
//}
//int main()
//{
//	if (if_prime(11) == 1)
//	{
//		printf("������");
//	}
//	return 0;
//}


//���ַ������������в�������
//int find(int arr[], int k, int sz)
//{  
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int ret = (left + right) / 2;
//		if (arr[ret]<k)
//		{
//			left = ret + 1;
//		}
//		else if (arr[ret]>k)
//		{
//			right = ret - 1;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr)/sizeof(arr[0]);//��һ��������ں����� sz��ֵ����� 
//	//printf("%d", sz);
//	if (find(arr, k, sz))
//		printf("�ҵ���");
//	else
//		printf("û��");
//	return 0;
//}



//���庯��ÿ������һ�ξͼ�һ
//void count(int* p)
//{
//	(*p)++;//++�����ȼ����� ������������p�� ����Ҫ�����Ű�*p��������
//}
//int main()
//{
//	int times = 0;
//	count(&times);
//	printf("%d",times);
//}


//������Ƕ�׵���
//void a()
//{
//	printf("a");
//}
//void b()
//{
//	printf("a");
//	printf("b");
//
//}
//
//int main()
//{
//	b();
//	return 0;
//}




//��������ʽ����  ��һ�������ķ���ֵ��Ϊ��һ�������Ĳ���
//int main()
//{
//	printf("%d\n", strlen("abc"));
//	printf("%d", printf("%d", printf("%d", 43)));//�����4321 printf()�����ķ���ֵ�Ǵ�ӡ���ַ��ĸ���  43Ϊ�����ַ�������2 ��ӡ2���ַ���1 ����ӡ1
//}


//����������
//int add(int, int);//add������main����  �����������Ա��ⱨ��  ���ⲻ�������������÷�
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum=add(a, b);
//	printf("%d", sum);
//	return 0;
//}
//
//int add(int a, int b)
//{
//	return a + b;
//}



//�������÷�
//�����Ķ������add,c�ļ��� ��������add.h�ļ��� �������ļ���ͬ������һ���ӷ�ģ�� �ڹ����г��������ֹ��ܲ�ֳ�ģ�� ��������һ�����ͷ�ļ���
//#include "add.h"
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum=add(a, b);
//	printf("%d", sum);
//	return 0;
//}




//�ݹ�
//int main()
//{
//	printf("abc");
//	main();
//	return 0;//������������һֱ������ȥ�ͻ��Զ�ֹͣ stack overflow ջ���  ջ�������洢�ֲ������ͺ������β� ����ջ�����ж�������̬���ٵ��ڴ棩�;�̬����ȫ�ֱ�����static���εı�����
//}



//��˳��������ֵ�ÿһλ��
//void print(int n)
//{
//	if (n > 9)//��ȷ�ĵݹ�һ������������ ��ÿһ�εݹ鶼Խ��Խ�ӽ�����
//	{
//		print(int(n / 10));
//	}
//	printf("%d\n", n % 10);
//}
//int main()
//{
//	int a = 1234;
//	print(a);
//	return 0;
//}


//��������ʱ���� ���ַ�������

//int len(char* str)
//{
//	int count = 0;
//	while (*str != '\0')//�����������\0��β ����\0�ͼ���ѭ��
//	{
//		count++;
//		str++;//�õ���һ��Ԫ�صĵ�ַ
//	}
//	return count;
//}//��������ĿҪ��



//int len(char* str)
//{
//	if (*str != '\0')
//	{
//		str++;
//		return 1 + len(str);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//{
//	char arr[] = "abcd";
//	printf("%d", len(arr));//ע�����鴫�β����������� ������Ԫ�صĵ�ַ
//	return 0;
//}



//���n��쳲�������
//int count = 0;
//int fib(int n)
//{
//    if (n == 3)
//    {
//        count++;
//    }
//    if (n <= 2)
//    {
//        return 1;
//    }
//    else 
//        return fib(n - 1) + fib(n - 2);
//}//��Ҫ���кܾ� �кܶ����ݱ��ظ�����  �������ⲻ�ʺ��õݹ����  ��ѭ�������ʺ�
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d", &a);
//    b = fib(a);
//    printf("%d", b);
//    return 0;
//}



//�ݹ�ľ�����Ŀ ��ŵ������ ������̨������  ���������о�
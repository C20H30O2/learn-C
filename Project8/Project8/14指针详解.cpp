#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>


//void test(int arr[])
//{
//	printf("%p\n", arr);
//	int sz = sizeof(arr) / sizeof(arr[0]);//��64λƽ̨�н��Ϊ2
//	printf("%d\n", sz);
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	test(arr);
//	return 0;
//}



//int main()
//{//�������ִ�ӡ֮��Ĳ�ͬ
//	int arr1[] = { 1,2,3 };
//	printf("%p\n", arr1);//���������޷�ֱ��������ӡ ����������ֵ
//	printf("%d\n", arr1[0]);
//
//	char arr[] = "abcdef";
//	char* pc = arr;
//	printf("%p\n", arr);
//	printf("%p\n", pc);
//
//	printf("%s\n", arr);
//	printf("%s\n", pc);//ע������Ҳ���Դ�ӡ���������ַ�����
//	return 0;
//}



//int main()
//{
//	char a[] = "abc";//�����ͣ����"abc"�� ������Ϊconst ���г����� 
//	a[0] = 'b';
//	printf("%s\n", a);//���Կ������������������޸Ĳ�û�б�������������ӡ
//
//
//	//char* p = "abcdef";//����ʦ����ʾ�� "abcdef"��Ϊһ�������ַ���  ����Ὣa�ĵ�ַ����p   ������������д�ᱨ�� 
//	const char* p = "abcdef";//����Ҫ����const���ܸ�ֵ  �������߶����г����� �Ͳ��ᱨ�� 
//	printf("%p\n", *p);
//
//	//*p=   �������޷�ͨ��pȥ�޸�
//	//printf("%p\n", *p);
//	return 0;
//}




//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//	if (arr1 == arr2)
//	{
//		printf("hehe");
//	}
//	else
//	{
//		printf("haha");
//	}
//	if (p1 == p2)//���Ƿ��� ��Ϊ"abcdef"����ͬ�ĳ����ַ��� ϵͳΪ�˽�ʡ�ռ�  �������ַ����ͬ���� 
//	{
//		printf("hehe");
//	}
//	else
//	{
//		printf("haha");
//	}
//
//	return 0;
//}
// 






//ָ������ ������ �������ָ��
//int main()
//{
//	int arr[10] = { 0 };//��������
//	char ch[5] = { 0 };//�ַ�����
//	int* parr[4];//�������ָ�������
//	char* pch[5];//����ַ�ָ�������  ������������ָ������
//	
//	
//
//	//ָ�������ʹ�÷���
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d\n", *(parr[i] + j));
//		}
//	}
//	return 0;
// }





//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//arrΪ��Ԫ�ص�ַ  &arr[0]Ҳ����Ԫ�ص�ַ    ע��&arr������ĵ�ַ
//	int(*p)[10] = &arr;//������ĵ�ַ�洢����  
//	//�����p��������ָ�� ָ��һ������
//	//ע�� []�����ȼ���*�� ����Ϊ�˱�֤p��һ��ָ������Ҫ��()��*p������  p��һ��ָ������ ָ����� int[10]���͵�����
//	//���д�� int *p{10]  �ͱ���p��һ������ �����ڴ洢���� int*���͵�Ԫ��
//
//
//	if (*p == arr)
//		printf("yes\n");
//
//
//	printf("%d\n", *(*p));
//
//
//
//	//ʹ�÷���
//
//	int i = 0;
//	int* pp = arr;
//	for (i = 0; i < 10; i++)
//	{
//		//1
//		//printf("%d ", (*p)[i]);//��p�����þ�ָ�������� *p=arr   
//
//
//		//2
//		//printf("%d", *(*p + i));
//
//
//		//3
//		printf("%d", *(pp + i));
//	}
//	return 0;
//}




//void print1(int arr[3][5], int x, int y)
//{
//	int j = 0;
//	int i = 0;
//	for(i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//
////������ָ�����ʽ
//void print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//
//			//���ж�����ͬ����Ĳ�ͬʹ�÷���
//			//printf("%d ", (*(p + i))[j]);//���p+i ��λ����������ڵĵ�i+1��С����  ��ʹ��[j]��λ��С�����ڵĵ�j+1��Ԫ��
//
//			//printf("%d ", *(*(p + i)+j));//*(p+i)=arr[i], arr[i]����arr�еĵ�i+1��С���� ����arr[i]��ʵ���Կ�����С�����ڵ���Ԫ�صĵ�ַ 
//		
//			printf("%d ", *(p[i] + j));//�������
//
//			printf("%d ", p[i][j]);//�������  p��Ϊָ���Ȼ����ֱ������ʹ�ã���������
//		}
//		printf("\n");
//	}
//}
//
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print1(arr, 3, 5);//int arr[3][5] ���������յ��������� 
//	print2(arr, 3, 5);//int(*p)[5] ���������յ������ڵĵ�һ��С����ĵ�ַ
//
//	return 0;
//}




//int main()
//{
//	int arr[5];//���������Ԫ�ص�����
//	int* parr1[10];//ָ������ ��10��Ԫ�� ÿ��Ԫ�ص�������int* 
//	int(*parr2)[10];//����ָ�� ָ��һ���洢��10��int���͵�����
//	int(*parr3[10])[5];//��һ������  
//	//һ��Ҫע�� �����ȥ��������[] ʣ�µľ��������д洢���������� 
//	//��������parr3��һ�����Ǹ�Ԫ�ص����� ��Ԫ��������int(*)[5]  ��ָ��һ���洢�����int����Ԫ�ص�����
//	//�ܽ᣺parr3 ��һ�����飬��������10��Ԫ�أ�ÿһ��Ԫ����һ������ָ�룬 ����ָ��ָ������������Ԫ�أ�ÿһ��Ԫ����int
//	return 0;
//}




//һά���鴫��
//void test(int* arr)
//{
//
//}
//void test2(int** arr)
//{
//
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);//test��()�п���дint arr[]��int arr[10]��int *arr  
//	test2(arr2);//test2��()�п���дint *arr[20]��int** arr     
//	//�������������ͽ��ղ��� ���Ը���ʵ�����ı�
//	return 0;
//}




//��ά���鴫��
//void test(int *arr)//����
//{}
//void test(int arr[][5])//ע�����ʡ���� ������ʡ����  �����д������ȷ��
//{}
//void test(int(*p)[5])//int(*p)[5] ��ȷ
//{}
//void test(int **arr)//����
//{}
//void test()
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//	return 0;
//}



//�������Ĳ���Ϊ����ָ���� �ܽ���ʲô������
//void test(char **p)
//{
//
//}
//
//int main()
//{
//	char c = 'b';
//	char* pc = &c;
//	char** ppc = &pc;
//	char* arr[10];
//	test(&pc);
//	test(ppc);
//	test(arr);//��û������
//}



//����ָ��
//int ADD(int x, int y)
//{
//	return x + y;
//}
//
//int main() 
//{
//	int a = 10;
//	int b = 20;
//	int arr[10]{ 0 };
//	int(*p)[10] = &arr;
//	
//
//	//&������ �� �����ĺ��������ܱ�ʾ�����ĵ�ַ
//	printf("%p\n", &ADD);
//	printf("%p\n", ADD);
//
//
//	//���ú���
//	printf("%d\n", ADD(a, b));
//	int (*pa)(int, int) = ADD;//*p��ʾp�Ǹ�ָ��  �Ҹú�������������int ������int��int
//	printf("%d\n", (*pa)(2, 3));//�Ƚ����� �������Ŵ������
//
//	return 0;
//
//}



//void print(const char* str)
//{
//	printf("%s\n", str);//�Ҹо��������str��Ȼ��ֱ�Ӵ�ӡ
//	printf("%p\n", str);
//	//printf("%s\n", *str);//����ͼ�������ٴ�ӡȴû���������
//}
//
//int main()
//{
//	void(*p)(const char*) = print;
//	(*p)("hello");//�������"hello"��Ϊ�ַ����鴫�뺯��������Ԫ�صĵ�ַ
//	return 0;
//}






#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>


//�Լ�дһ�����������ַ�������
#include<assert.h>
//int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str != '\n')
//	{
//		count++;
//		str++;
//	}
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = { 'a','b','c','d','e' };//����д��û��\0�� ʹ��strlen��ó����ֵ
//
//	printf("%d,%d", strlen(arr1), strlen(arr2));
//
//	//strlen���ص���size_t���� ��ʵ����unsigned int����
//	if (strlen("abc") - strlen("abcdef") > 0)//unsigned int ���͵�3-6�Ľ��Ҳ���޷�����  ���ж���Ҳ����Ϊ����0��
// 	{
//		printf("hehe\n");
//	}
//	else {
//		printf("haha\n");
//	}
//
//	//�Լ�д��my_strlen�������ص���int���� ��������������� ����int �ͷ���unsigned int ���͸��и������� ���ؿ������
//
//	return 0;
//}





//strcpy �����ַ���
//�Լ�дһ�������ַ����ĺ���

//char* my_strcpy(char* dest,const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	while (*dest++ = *src++)//����src�е�\0һ�𿽱���dest��
//	{
//		;
//	}
//	return ret;//����Ŀ�Ŀռ����ʼ��ַ
//}//���Ǿ����Ż��������⺯��strcpy�İ汾


//ע����ÿ⺯��strcpyʱ Դ�ַ���������\0���� �ú�������ͬ\0һ�𣬽�Դ�ַ����е��ַ�������Ŀ��ռ�
//���뱣֤Ŀ��ռ��㹻��ȷ���ܴ��Դ�ַ��� ��Ŀ��ռ����ɱ䣬�����ܼ���const���賣����




//strcat
//char* my_strcat(char*dest,const char*src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src);
//	while (*dest != '\0')
//	{
//		dest++;
//	}//��ָ��destָ��dest��\0 
//	while (*dest++ = *src++)//��dest��\0����ʼ����src
//	{
//		;
//	}
//	return ret;//��strcpy�Ŀ⺯��һ������dest����Ԫ�ص�ַ
//}
//ע��ʹ�ÿ⺯��stractʱ Դ�ַ���������\0����  Ŀ��ռ������޸����㹻�� 





//strcmp
//�ַ����ıȽϷ�������pythonѧ����һ��  �����˾�ȥ��
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//ȷ�������ַ�����Ϊ��
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//
//
//int main()
//{
//	const char* p1 = "abc";
//	const char* p2 = "abcd";
//	int ret = my_strcmp(p1, p2);
//	printf("ret=%d\n", ret);
//
//	return 0;
//}


//��vs�е���strcmp�Ƚ��ַ��� ��ͬʱ����0 p1>p2ʱ����1 p1<p2ʱ����-1
//���������ط� ���ܷ�������ֵ 
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//ȷ�������ַ�����Ϊ��
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;//�������ﷵ�صľ��Ǳ��Ƚϵ������ַ��İ�˹����ֵ֮�� 
//}
//
//
//int main()
//{
//	const char* p1 = "abce";
//	const char* p2 = "abcd";
//	int ret = my_strcmp(p1, p2);
//	printf("ret=%d\n", ret);
//
//	return 0;
//}





//strncpy  ���strcpy����һ������ 
//int main()
//{
//	char arr1[10] = "abcdefgh";
//	char arr2[] = "bit";
//    strncpy(arr1, arr2, 6);//n=6 ��arr2��6���ַ�������arr1�� ����չʾ����arr2��Ԫ������n����� ����\0��ȫ���Ȳ����Ĳ��� arr1���bit\0\0\0gh\0\0
//
//	char arr3[10] = "abcdef";
//	char arr4[] = "def";
//	strncpy(arr3, arr4,2);//arr3����decdef\0\0\0\0
//
//	int a = 1;
//	return 0;
//}


//���Բ鿴ѧϰ�⺯��strncpy��Դ��





//strncat
//int main()
//{
//	char arr1[30] = "hello\0xxxxxxx";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 3);//ֻ��arr1��\0����ʼ׷����arr2�е�3��Ԫ�� ��Ȼû�ж�ȡ��arr2��\0 ��׷����wor����Ȼ���һ��\0  ���������arr1�����hellowor\0xxxxxx\0\0����
//	printf("%s\n", arr1);
//
//
//	char arr3[30] = "hello\0xxxxxxxxxxxx";
//	char arr4[] = "world";
//	strncat(arr3, arr4, 8);//׷�ӵĸ�������arr4�е�Ԫ�ظ���ʱ ֻ��arr4�е�Ԫ��׷�� �����\0�Բ�����Ŀ ����arr3���helloworld\0xxxxxxx\0\0����
//	return 0;
//}
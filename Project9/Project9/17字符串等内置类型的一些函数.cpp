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




//strncmp �ַ����ȽϺ��� ����ָ���Ƚϵ��ַ�����
//int strncmp(const char*string1,const char* string2,size_t count)
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcqef";
//	int ret1= strcmp(p1, p2);
//	int ret2=strncmp(p1,p2,3);//�Ƚ������ַ� ������Ϊ0
//	printf("%d,%d\n", ret1, ret2);
//	return 0;
//}




//strstr �ַ������Һ��� ����һ���ַ������Ƿ������һ���ַ���

//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);//	ȷ��p1��p2��Ϊ��ָ��
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* cur =(char*) p1;
//	if (*p2 == '\0')
//	{
//		return (char*)p1;
//	}
//	while (*cur)
//	{
//		s1 = cur;//���ҵ�ʵ��ԭ��ܼ� ����p1�е�ÿһ���ַ����Ӹ��ַ���ʼ�Ƚ�p2���ȵ��ַ����� ��s1ָ��\0ʱ˵�������� 
//		s2 =(char*) p2;
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))//���Լ�Ϊ while(*s1 && *s2 && (*s1==*s2)) 
//		{
//			s1++;
//			s2++;
//
//		}
//		if (*s2 == '\0')
//		{
//			return cur;//�ҵ��Ӵ�
//		}
//		cur++;
//		//printf("hehe");
//	}
//	return NULL;//�Ҳ����Ӵ�
//
//}
//
//int main()
//{
//	const char* p1 = "abcdefabcdef";
//	const char* p2 = "def";
//	const char* ret1 = strstr(p1, p2);//ע���䷵�ص���const char* ����   ������ڸ��ַ������䷵�ص�������p2�ĵ�һ��Ԫ����p1�еĵ�ַ  �������򷵻�NULL   ��p1���ж��p2�ַ��������ص��ǵ�һ�γ��ֵĵ�ַ
//	const char* ret2 = my_strstr(p1, p2);//ע���䷵�ص���const char* ����   ������ڸ��ַ������䷵�ص�������p2�ĵ�һ��Ԫ����p1�еĵ�ַ  �������򷵻�p1��Ԫ�صĵ�ַ
//	if (ret2 != NULL)
//		printf("�ҵ���");
//	else
//		printf("û���ҵ�");
//}

//���кܾ����һ���ַ���ƥ���㷨����kmp�㷨 �漰�����ݽṹ��֪ʶ ���������˽�




//strtok �������ַ����и�ĺ���  char* strtok(char* str,const char* sep)  sep������һ���ַ����������������ָ���ַ�����
//int main()
//{
//	char arr[] = "abc@def.com@ppp";
//	const char* p = "@.";
//
//	char* ret = strtok(arr, p);//����һ�θú���ֻ����һ���и� ��������һ��p�е��ַ��ͽ����ַ��滻Ϊ\0 Ȼ��ֹͣ
//	printf("%s\n", ret);//��Ϊp�е��ַ����滻����\0,���Դ�ӡ���ڴ˴�ֹͣ
//
//	ret = strtok(NULL, p);//strtok�������ס�ϴ��и��λ��  ���Ҫ��������ַ��������ٴ��и�Ͳ�Ҫ�ٴ����ַ��ֻ��Ҫ����NULL����
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//
//
//
//	//����ʵ����strtok���ѭ���������и��ӷ����д��
//	char arr2[] = "abc@def.com@ppp";
//	char* ret2 = NULL;
//	for (ret2 = strtok(arr2, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret2);
//	}
//
//	return 0;
//}




//strerror   char* strerror(int errnum) �ú����᷵�ش���������Ӧ�ش�����Ϣ
//#include<errno.h>
//int main()
//{
//	//������ 0����NO error
//	//       1����Operation not permitted 
//	//       2����No such file or directory
//	//       ������������
//	//errno��һ��ȫ�ֵش�����ر��� 
//	//��C���Եؿ⺯����ִ�й����з����˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����븳ֵ��errno��
//
//
//	//���ļ�
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("no error");
//	}
// 	return 0;
//}



//�ж��ַ��ĺ��� ����������������ͷ�����
//iscntrl �����ַ�    isspace �հ��ַ�����' ','\f','\n','\r','\t','\v'    isdigit ʮ��������1����9   
// isxdigit ʮ����������1����f��A����F        islower Сд��ĸa����z    isupper ��д��ĸA����Z 
// isalpha ��ĸ         isalnum ��ĸ������     ispunct �����ţ��κβ��������ֻ�����ĸ�Ŀɴ�ӡ���ַ�   
// isgraph �κ�ͼ���ַ�    isprint �κο��Դ�ӡ���ַ������հ��ַ���ͼ���ַ�




//�ַ�ת��  
//int tolower (int c)  �Ʋ�int����Ӧ����ָ���ַ��İ�˹����ֵ    
//int toupper (int c)  

#include<ctype.h>
//int main()
//{
//
//	char ch = '2';
//	int ret = islower(ch);//�ж�ch�Ƿ���Сд��ĸ
//	int ret2 = isdigit(ch);
//	printf("%d,%d\n", ret,ret2); //Ϊ���򷵻�����
//
//	char ch1 = toupper(' ');
//	char ch2 = toupper('q');
//	printf("%d,%d\n", ch, ch2);//��int���ʹ�ӡ����ת������ַ��İ�˹����ֵ ����Q�İ�˹����ֵ��81
//	
//	return 0;
//}



//int main()
//{
//	char arr[] = "I Am A Student";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}







//�����ַ��������������ַ��� ����strcpy�޷�����int���͵�����
//memcpy������������int���͵������������������

//�����Լ�ʵ��memcpy�Ĺ���
//void* my_memcpy(void* dest,const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//struct S
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));//����Ҫ����sizeof(arr1)�Ϳ���֪�� �ú�����ʵ�ǽ�arr1�е�sizeof(arr1)���ֽڿ�����arr2��
//
//
//	struct S arr3[] = { {"a",10},{"b",20},{"c",30} };
//	struct S arr4[3] = { 0 };
//	memcpy(arr4, arr3, sizeof(arr3));//ͬ�����Կ���
//
//	
//	return 0;
//}





//memmove�����������ڴ��ص�����µĿ���   memmove(arr2, arr1, sizeof(arr1))
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int i = 0;
//	memmove(arr + 2, arr, 20);//��arr�е�1��2��3��4��5 ������arr��ԭ����3��4��5��6��7��λ��   �ܴ�С��20���ֽ�
//	//memcpy(arr + 2, arr, 20);//���Ƿ���vs�е�memcpy����Ҳ�������ڴ��ص�����µĿ�����������C������û��������Ҫ��C����ֻҪ��memcpy�ܹ������ص�����µĿ������У������ڱ�ı������п��ܾ��޷�ʵ�ָù���
//	for (i = 0; i < 9; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



//Ϊ��ʵ���Լ���memmove������������Ҫ֪�����ڴ��ص�����µĿ�����ʽ
//�������Ҫ��arr�е�ĳһ���ֿ�����arr�е���һ�����֣���ôdest��src�����λ�������������
//1:dest<src  ���ô�ǰ��󿽱�   2:dest>src && dest<src+count ���ôӺ���ǰ����   3:dest>src+count  ��ʱĿ�������Դͷ����û���ص������Բ������ⷽʽ���� 
//  

//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	if (dest < src)
//	{
//		//��ǰ��󿽱�
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			dest=(char*)dest+1;
//			src=(char*)src+1;
//			
//		}
//	}
//	else
//	{
//       //�Ӻ���ǰ����
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}







//memcmp����  int memcmp(const void* ptr1,const void* ptr2,size_t num)

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };//10 00 00 00 20 00 00 00 30 00 00 00 40 00 00 00 50 00 00 00  arr1���ڴ��еĴ洢
//	int arr2[] = { 1,2,5,4,3 };//10 00 00 00 20 00 00 00 50 00 00 00 40 00 00 00 30 00 00 00  arr2
//
//	int ret = memcmp(arr1, arr2, 9);//�Ƚ�arr1��arr2�еľŸ��ֽ�
//	printf("%d\n", ret);//����-1˵��arr2��ǰ�Ÿ��ֽڱ�arr1����
//	return 0;
//
//}




//memset �ڴ�����
//int main()
//{
//	char arr1[10] = "";
//	memset(arr1, 'a', 10);//��arr1�е�10���ֽ������޸�Ϊ�ַ�a
//
//	int arr2[10] = { 0 };
//	memset(arr2, 1, 10);//10ָ�����޸ĵ��ֽ�������arr2����40���ֽڣ��������ﲢ���ǽ�a�е�ȫ��ʮ��Ԫ�ض��޸�Ϊ1
//	return 0;
//}
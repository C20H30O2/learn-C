#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>


//�ṹ������
//struct MyStruct
//{
//	memberlist;
//}variable-list;


//struct stu
//{
//	char name[10];//�ṹ��һЩֵ�ļ��� ��Щֵ����Ϊ��Ա���� �ṹ��ÿ����Ա�����ǲ�ͬ���͵ı���
//	char id[10];
//}s1,s2,s3;//�������趨��s1 s2 s3 ����ȫ�ֵĽṹ�����  
//
//typedef struct STU
//{
//	char name[10];
//}Stu;//ʹ��typedef�����������Խṹ����������� ���Կ���������ֻ����Stu�Ϳ��Դ���һ���ṹ����� 
//
//
//int main()
//{
//	struct stu s1{'jack','1234' };
//
//	Stu s4{"tom"};//
//
//	printf("%s\n", s4.name);
//
//	return 0;
//}




//struct phone
//{
//	int phonemunber;
//};
//
//
//struct info
//{
//	char name[20];
//	struct phone p;//����Ƕ��
//};
//
//int main()
//{
//	struct info people1{"tom",{123} };
//	printf("%s\n", people1.name);//���÷�ʽ
//	printf("%s\n", people1.p.phonemunber);
//
//
//	return 0;
//}



//typedef struct stu
//{
//	char name[20];
//}stu;
//
//void print1(stu t)
//{
//	printf("name = % s\n", t.name);
//}
//
//void print2(stu* t)
//{
//	printf("name=%s\n", t->name);
//}
//
//int main()
//{
//	stu s1 = { 'jack'};
//	print1(s1);
//	print2(&s1);//����p1��p2��������ɴ�ӡ���� ����һ��ѡ��p2���� ��Ϊp2ֻ�����˵�ַ ��p1�ǽ����󿽱���һ�� 
//	            //���� �������ε�ʱ�� ��������Ҫѹջ�� ������Ĳ�����һ���ṹ�������ʱ�򣬽ṹ����󣬲���ѹջ��ϵͳ������Ƚϴ� �������ܵ��½� 
//	return 0;
//}





//���ڵ���
//�����Ϊdebug��release�汾
//debugΪ���԰汾 ����������Ϣ �����Ż� ���ڵ��Գ���
//releaseΪ�����汾 �����˸����Ż� �����û�ʹ��
//�������Ϸ����� ���Խ�������debug��release�汾���л� ����������64λƽ̨��32λƽ̨���л���

//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100; i++)
//	{
//		printf("%d\n",i);
//
//	}
//	return 0;
//}//���ֿ�����debug�汾��ͨ���������鿴i�ı仯 ����release�汾�л���ʾ�����ѱ��Ż� ����ʹ��



//���ÿ�ݼ�
//f5 �������� ��������ֱ��������һ���ϵ㴦
//f9 ������ĳһ�д����ϵ��ȡ���ϵ� �����ڳ��������λ�����öϵ� ʹ�ó�������Ҫ��λ��ִֹͣ��
//f10 ����̽��е��� 
//f11 �������е��� ���Խ��뺯���ڲ� 
//CTRL+f5 ʹ�ó���ֱ������ ��������



//����ʱ�鿴���ö�ջ ����ʱ�򿪵��� �򿪴��� ���Կ������ö�ջ ����ʹ�÷�����������
//void t2()
//{
//	printf("hehe\n");
//}
//void t1()
//{
//	t2();
//}
//void t()
//{
//	t1();
//}
//int main()
//{
//	t();
//	return 0;
//}



//����δ������һ�����Ľ׳� ���������� ���Ϊ15 ������9
//��δ������׳��д��� ��Ϊret������һ�κ�û�й���
//�����ڵڶ���for�����öϵ� ���Ҽ��ϵ� ��������Ϊi=3 ʱ��ͣ�� ��������f5����ֱ������i=3  ����һ���°���һ�����ٵ���
//���������ټ��Ӵ��ڷ���retΪ2 ���ִ���
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}





//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//    }
//	printf("%p\n", arr);
//	printf("%p\n", &i);//�����ڰ汾�ı������� ���ǻᷢ��arr[12]�ĵ�ַ����i�ĵ�ַ �������޸�arr[12]��Ԫ��ʱ�޸���i��ֵ ���Ի������ѭ�� 
//	//����ʦ����ʾ ����������ѭ�� ����vs2022�в��������ѭ�� ˵���Ѿ��������Ż�
//	return 0;
//}




//�ַ�������
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;
//}//����д��̫����





//����������
//#include<assert.h>
//char* my_strcpy(char* dest,const char* src)//����Ԫ�ص�ַ����  ��׼��strcpy����Ҳ�Ƿ��ص�ַ  ��constʹsrc�޷����޸� ������һЩ���ܲ����Ĵ���
//{
//	char* ret = dest;
//	assert(dest != NULL);//ʹ�õ�dest=NULLʱ����
//	assert(src != NULL);
//	while (*dest++ = *src++)//���ȼ��� �Ƚ����� ��++ 
//	{
//		;
//	}
//	return ret;
//}
//
//
//
//
//
//int main()
//{
//	char arr1[] = "##########";
//	char arr2[] = "bit";
//	char* a=my_strcpy(arr1, arr2);
//	printf("%p\n", my_strcpy(arr1, arr2));
//	printf("%s\n", arr1);//arr2�Ὣ��β����\0һ����arr1 ����arr1����Ĳ��־Ͳ��ᱻ��ӡ����
//	return 0;
//}






//int main()
//{
//	const int num = 10;
//	int n = 100;
//	const int* p = &num;//const����ָ�����*�����ʱ ���ε���*p Ҳ����˵ ����ͨ��p���ı�*p����num����ֵ
//	//*p=  //����д�ᱨ�� ˵��num�޷��������޸�
//	//p = &n;//����p��Ȼ���Ըı�
//
//
//	int* const p = &num;//const����ָ��������ұ�ʱ�����ε���ָ�����p��������p���ܱ��ı�  ��������Ϊ�������汾���� ��������д�ͻᱨ�� ����������һ��������
//	printf("%d\n", num);
//
//	return 0;
//}




//#include<assert.h>
//int my_strlen(const char* str)//���ڲ����޸ĵĴ������ ���Ը��賣���� ������д����Ĺ����в�С�ĶԸò��������޸�
//{
//	printf("%p\n", str);
//	int count = 0;
//	assert(str != NULL);//��ָ֤�����Ч��
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//
//int main()
//{
//	char arr[] = "abcd";
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}




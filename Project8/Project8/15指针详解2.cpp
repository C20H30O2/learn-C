#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>

//�������
//(*(void(*)())0)()  ��ʾ��0ǿ������ת��Ϊvoid(*)()  ��void(*)()���������Ǻ���ָ������  �����ܶ� void(*)())0���н����� ʹ����ָ��ĺ���

//void (*signal(int,void(*)(int)))(int)  
//���Կ���(int,void(*)(int))�Ǻ����Ĳ��� ��signal���Կ���������
//ע�� ���� int ADD(int,int)  ȥ���������ʹ��������ʣ�µľ��Ƿ�������int   
// �����ж�����void (*)(int) ���Ǻ����ķ�������
//Ҫע�� �� int ADD(int,int) ������д���Ǻ������� ��֮ǰ����������ɨ������������Ӧ��ͷ�ļ���Ҳ���й����������� 
//��������Ҳ���ڽ��к��������� 


//��Ҫע�� void(*)(int) signal(int,void(*)(int)) ���������������Ǵ���� 
//���Ҫ��signal(int,void(*)(int)) ����void(*)(int)���� ��ô*��ȻҪ���������� ����д��void (*signal(int,void(*)(int)))(int)

void(             *signal(int, void (*)(int))                )(int);
//�п��������򵥵�д��   ��Ҫ����typedef���м� 
typedef unsigned int uint;//��unsigned int������������Ϊuint 
typedef void(* pfun_t)(int);//��������������Ϊpfun_t    ע������ﲻ��д��typedef void(* )(int) pfun_t  ��ȻҪ��*��������

pfun_t signal(int, void (*)(int));//��������֮��Ϳ�������д��



//����ָ�� ����
//int ADD(int x, int y)
//{
//	return x + y;
//}
//
//
//int main()
//{
//	int a = 0;
//	int b = 20;
//	int (*p)(int, int) = ADD;
//	printf("%d\n", (*p)(2, 3));
//	printf("%d\n", (**p)(2, 3));
//	printf("%d\n", (***p)(2, 3));//��������ͬ  ˵�������*û���ô� û��Ч��
//	printf("%d\n", p(2, 3));//��������дҲ��
//	printf("%d\n", ADD(2, 3));//��֮���ADD���������Ϊһ����ַ �Ϳ����������һ�е�д��
//
//	return 0;
//}




//����ָ������  ��һ������ �洢�Ķ��Ǻ���ָ��
//int ADD(int x, int y)
//{
//	return x + y;
//}
//
//int SUB(int x, int y)
//{
//	return x - y;
//}
//
//int MUL(int x,int y)
//{
//	return x * y;
//}
//
//int DIV(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int (*p)(int, int) = ADD;//p��ֻ�ܴ洢һ����ַ
//	//��ʱ��Ҫһ������ ȥ�洢�ĸ������ĵ�ַ
//	int (*p_func[4])(int, int) = { ADD,SUB,MUL,DIV };//�����һ������ָ������� Ҫע��int (*) (int,int) p_func[4] ����д���Ǵ����
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", p_func[i](4, 2));
//	}
//
//	return 0;
//}




//����
char* my_strcpy(char* dest, const char* src);
//дһ������ָ��Ϊ��char* (*p) (char* dest,char* src)=my_strcpy;
//дһ������ָ������Ϊ��char* (*p[1]) (char* dest,char* src)={my_strcpy};
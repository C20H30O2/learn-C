#define _CRT_SECURE_NO_WARNINGS//��ֹscanf��������

#include<stdio.h>

//�����д�����/nʹ�ô��� ���Ҫ����Ӧ��ʹ��\n


//��    
//int num=20  //ȫ�ֱ��� �����ڴ����{}֮��ı��� 
int main()    //��������num����ͬʱ����   ��ӡ���Ĭ��Ϊ�ֲ�����  ������߲�Ҫ��ͬ���ײ���bug
//{int num = 10;//�ֲ����� �����ڴ�����ڲ��ı��� ֻ���ھֲ���������ʹ��
//	printf("%d/n", num);
//return 0;
//}



//��   
//	short age = 9;//���������ֽڵĿռ����ڴ洢age����
//	float num = 99.7;//ͬ��
//	printf("%f/n", num);
//	printf("%d/n", age);




//��
//{
//	printf("%d/n", sizeof(char));//1�ֽ�=�˸�����λ      bit����λ  bite�ֽ�
//	printf("%d/n", sizeof(short));//2�ֽ�       1kb=1024bite    mb   gb   tb   pb
//	printf("%d/n", sizeof(int));//4       ����1   ����0  һ������λ���ڴ��һ��������λ
//	printf("%d/n", sizeof(long));//4
//	printf("%d/n", sizeof(long long));//8
//	printf("%d/n", sizeof(float));//4
//	printf("%d/n", sizeof(double));//8
//}



//һ   //char ch = 'A';//char�ַ�����  
//printf("%c/n", ch);//%c��ӡ�ַ���ʽ������  %d��ӡ����ʮ�������� 
//return 0;

//int    long������    long long����������    short������    char    float   double 
//%f ��ӡС��  %p�Ե�ַ����ʽ��ӡ  %x��ӡ16��������  %o
//float�����ȸ�����   double˫���ȸ�����



//��
//{//�����������ĺ�  Ҫ�������ݡ���ʹ�����뺯��scanf()
	//int num1 = 3;
	//int num2 = 6;
	//scanf("%d%d", &num1, &num2); //&Ϊȡ��ַ����  �������������ݷ�����Ӧ��ַ��
	//int sum = 0;   //c�����﷨�涨  ������Ҫ�ڴ�������ǰ�� ��������һ��Ӧ����ǰ
//	sum = num1 + num2;
	//printf("sum=%d/n", sum);  //%dǰ��  sum=  Ϊ���ʱ��ǰ׺

//return 0;
//}

{
	int num1 = 6;
	int num2 = 7;
	int sum = 0;
	//scanf("%d%d", &num1, &num2); //&Ϊȡ��ַ����  �������������ݷ�����Ӧ��ַ��
	
	sum = num1 + num2;
	printf("sum=%d\n", sum);  //%dǰ��  sum=  Ϊ���ʱ��ǰ׺

	return 0;
}






//��   �������������޶����÷�Χ    �ֲ�������ȫ�ֱ���������������
//   extern  Ϊ�������ò�ͬԴ�ļ��ı���---ʹȫ�ֱ�������������������������
//ȫ�ֱ��������������������������������



//{
//	short num = 32767;//ע�� short��Ȼ�����������ֽڵĿռ� �������ֽ����ܱ�ʾ���������32767 ����num��ֵ���������32767 ���޷���ʾ��ȷ������
//	printf("%d", num);
//}
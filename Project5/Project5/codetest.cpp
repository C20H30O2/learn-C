#include<stdio.h>//ʹ��printf��Ҫ����ͷ�ļ�

//leetcode ��վ �кܶ��㷨��Ŀ  ����������һ��


int main()
{//����//���õ��������� ������������
	int a = 3;
	int b = 5;


	//a = a + b;
	//b = a - b;
	//a = a - b;
	//printf("%d,%d", a, b);//���ֽⷨ����������������⣨a+b���ܳ��������ܱ�ʾ�����ֵ�� ����ֻ�ܽ��һ��������


	//�Ľ�����ķ���  ����λ��������� ���ǿɶ��Բ� ִ��Ч�ʵ� һ��Ĺ����л���ʹ����ʱ����
	a = a ^ b;//^��ʾ���������ƣ�λ��� ��ͬΪ0 ����Ϊ1 3=011 5=101  a=3^5=110 b=5
	b = a ^ b;//a=110 b=011
	a = a ^ b;//a=101 b=011





	//����//�ҳ�ֻ����һ�ε���
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5 };

	//int i = 0;
	//int sz = sizeof(arr) / sizeof(arr[1]);
	//for (i = 0; i < sz; i++)
	//{
	//	int j = 0;
	//	int count = 0;
	//	for (j = 0; j < sz; j++)
	//	{
	//		if (arr[i] == arr[j])
	//		{
	//			count++;
	//		}
	//	}
	//	printf("%d", count);
	//	if (count == 1)
	//	{
	//		printf("%d",arr[i]);
	//	}
	//}



	//����ķ�������̫�鷳Ч�ʲ���
	//�Ľ�
	int i = 0;
	int num = 0;
	int sz = sizeof(arr) / sizeof(arr[1]);
	for (i = 0; i < sz; i++)
	{
		num = num ^ arr[i];//0^num=num  num^num=0 �������ڵ������ջ��Ϊ0 
	}
	printf("%d", num);

	
	return 0;

}
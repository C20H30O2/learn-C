#include<stdio.h>//使用printf需要引用头文件

//leetcode 网站 有很多算法题目  可以找来做一做


int main()
{//考题//不用第三个变量 交换两个整型
	int a = 3;
	int b = 5;


	//a = a + b;
	//b = a - b;
	//a = a - b;
	//printf("%d,%d", a, b);//这种解法存在整型溢出的问题（a+b可能超出整型能表示的最大值） 所以只能解决一部分问题


	//改进过后的方法  不进位，不会溢出 但是可读性差 执行效率低 一般的工程中还是使用临时变量
	a = a ^ b;//^表示按（二进制）位异或 相同为0 相异为1 3=011 5=101  a=3^5=110 b=5
	b = a ^ b;//a=110 b=011
	a = a ^ b;//a=101 b=011





	//考题//找出只出现一次的数
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



	//上面的方法还是太麻烦效率不高
	//改进
	int i = 0;
	int num = 0;
	int sz = sizeof(arr) / sizeof(arr[1]);
	for (i = 0; i < sz; i++)
	{
		num = num ^ arr[i];//0^num=num  num^num=0 两两存在的数最终会变为0 
	}
	printf("%d", num);

	
	return 0;

}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>



//解决买汽水的问题  每瓶汽水一元 每两个空瓶子可以换一瓶汽水  输入钱数求能喝的汽水总量
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//
//
//	total = money;
//	empty = money;
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//
//	//通过观察规律 可以得出这样的结论 直接算出总数 
//	//if (money == 0)
//	//	total = 0;
//	//else
//	//	total = 2 * money - 1;
//
//	printf("%d\n", total);
//
//	return 0;
//}



//int main()
//{	//unsigned char 大小为一个字节 8bit  表示的数字全为正数 范围时0-255
//	unsigned char a = 200;//200的原码为00000000000000000000000011001000   存到a中发生截断 只取到后面8个比特位 即11001000
//	unsigned char b = 100;//同理 b取到 01100100
//	unsigned char c = 0;
//	
//	c = a + b;//a和b相加时会发生整型提升 因为是无符号数 所有高位补0 
//	// a补0之后为 00000000000000000000000011001000
//	//b补0之后为  00000000000000000000000001100100
//	//     和为   00000000000000000000000100101100   这个值转化为十进制 就是a+b直接打印出的结果
//    //c取到后8个比特位 为00101100   打印c时会发生整型提升  高位补0   打印的值是00000000000000000000000000101100 的十进制
//	printf("%d,%d\n", a + b, c);//300 44
//	return 0;
//}


//int main()
//{
//	unsigned int a = 0x1234;//a=0x00 00 12 34  在小端字节序存储模式中 存储为34 12 00 00      大端字节序存储模式中存储为00 00 12 34 
//	unsigned char b = *(unsigned char*)&a;//b只能读取一个字节  在小段字节序存储模式中 读取到34   在大端存储模式中读取到00
//	printf("%d\n", b);//0x34 就是52
//	return 0;
//}



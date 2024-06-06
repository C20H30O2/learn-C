#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

//同时输入多个数字的写法
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d#%d#%d", &a, &b, &c);//要注意输入格式 输入1 2 3   如果写的是scanf("%d#%d#%d", &a, &b, &c);必须按1#2#3格式输入 #号换作其他符号同理
//	printf("%d %d %d", a, b, c);//               输出1 2 3                                               这样才能输出1 2 3
//}



//求两个数的最大公约数 辗转相除法
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d", &a, &b);
//	if (a < b)
//	{
//		c = a;
//		a = b;
//		b = c;
//
//	}
//	//while (true)
//	//{
//	//	c = a % b;
//	//	if (c == 0)
//	//	{
//	//		printf("最大公约数是%d", b);
//	//		break;
//	//	}
//	//	a = b;
//	//	b = c;
//	//}
//	//return 0;
//
//
//	//更高效率的写法
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("最大公约数是%d", b);
//}


//打印九九乘法表

//int main()
//{
//	int a = 1;
//	int b = 0;
//	for (a = 1; a <= 9; a++)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			printf("%d*%d=%d\t", a, b, a * b);
//			if (b == a)
//			{
//				printf("\n");
//			}
//		}
//	 }
//	return 0;
//}



//猜数字游戏

//生成随机数 rand()函数
//void menu()
//int main()
//{
//	int a = 0;
//	int ran = 0;
//	//srand(1);//设置种子 括号里必须是整数 这里需要利用时刻都在变化的时间传入一个随机的种子以保证随机性 使用时间戳
//	//时间戳 ：用计算机的当前时间减去1970年一月一日的差值再转换为秒
//	//要使用time函数  要引用#include<time.h>
//	srand((unsigned int)time(NULL)); //给time传入NULL（具体原因可以自行了解time函数） 将time函数的返回值转换为unsigned int类型  
//	//如果每次生成随机数之前都设置一次种子 则随机性会比较弱 所以这里用while把二者分开了
//	while (true)
//	{
//		scanf("%d", &a);
//		if (a == 1)
//		{
//			ran = rand()%100;//随机数取决于种子 相同种子的随机数相同 %100以保证数字较小 好猜
//			printf("%d\t", ran);
//		}
//	}
//	return 0;
//}
//猜数字最难的部分就是随机数 其他的部分我就跳过了




//C语言中的goto语句
//int main()
//{
//	//again:
//	printf("nihao");
//	goto again;//回到goto后的标记处  goto语句可能会导致出错 一般能不用就不用 
//	           //但也有好用的地放 比如在多层嵌套中 需要跳到最外层时不用逐个使用break 只需在内层中设置goto 就能去到要去的地方
//	printf("nihao1");
//again:
//	return 0;

//}

//for ()//使用示例
//{
//	for ()
//	{
//		for ()
//		{
//			if (发生错误)
//			{
//				goto fix;
//			}
//		}
//	}
//}
//fix:
//……





//有趣的关机程序
//cmd command命令行
//int main()
//{
//	char input[20] = { 0 };
//	//shotdown -s -t 60//在cmd中输入这一行会使电脑在六十秒后关机
//	//shotdown -a  可以取消关机
//	//C语言中有一个system函数 可以执行系统命令
//	system("shutdown -s -t 60");//注意要引用stdlib.h
//again:
//	printf("warning 你的电脑将在60秒后关闭\t 如果输入 我是** 就能取消关机");
//	scanf("%s", input);
//	if (strcmp("我是**", input)==0)//字符串的比较要使用这里的函数 还要引用#include<string.h> 
//	{
//		system("shutdown -a");
//
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;//在这个程序中完全可以用循环代替goto
//}
//可以将程序编写成一个.exe文件  再将该文件放入 系统服务 中 如果设置为自动启动 则在开机时会自动运行一分钟后关机的指令




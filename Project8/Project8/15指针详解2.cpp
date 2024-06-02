#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>

//解读代码
//(*(void(*)())0)()  表示将0强制类型转换为void(*)()  而void(*)()类型明显是函数指针类型  所以能对 void(*)())0进行解引用 使用其指向的函数

//void (*signal(int,void(*)(int)))(int)  
//可以看出(int,void(*)(int))是函数的参数 而signal可以看作函数名
//注意 像函数 int ADD(int,int)  去掉函数名和传入参数后剩下的就是返回类型int   
// 所以判断这里void (*)(int) 就是函数的返回类型
//要注意 如 int ADD(int,int) 这样的写法是函数声明 在之前设计三子棋和扫雷中我们在相应的头文件中也进行过函数的声明 
//所以这里也是在进行函数的声明 


//还要注意 void(*)(int) signal(int,void(*)(int)) 这样的声明方法是错误的 
//如果要让signal(int,void(*)(int)) 返回void(*)(int)类型 那么*仍然要靠近函数名 所以写作void (*signal(int,void(*)(int)))(int)

void(             *signal(int, void (*)(int))                )(int);
//有看起来更简单的写法   需要利用typedef进行简化 
typedef unsigned int uint;//将unsigned int类型重新命名为uint 
typedef void(* pfun_t)(int);//将类型重新命名为pfun_t    注意对这里不能写作typedef void(* )(int) pfun_t  仍然要让*靠近名称

pfun_t signal(int, void (*)(int));//重新命名之后就可以这样写了



//函数指针 补充
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
//	printf("%d\n", (***p)(2, 3));//输出结果相同  说明这里的*没有用处 没有效果
//	printf("%d\n", p(2, 3));//所以这样写也行
//	printf("%d\n", ADD(2, 3));//将之类的ADD函数名理解为一个地址 就可以理解上面一行的写法
//
//	return 0;
//}




//函数指针数组  是一个数组 存储的都是函数指针
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
//	int (*p)(int, int) = ADD;//p中只能存储一个地址
//	//此时需要一个数组 去存储四个函数的地址
//	int (*p_func[4])(int, int) = { ADD,SUB,MUL,DIV };//这就是一个函数指针的数组 要注意int (*) (int,int) p_func[4] 这种写法是错误的
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", p_func[i](4, 2));
//	}
//
//	return 0;
//}




//连续
char* my_strcpy(char* dest, const char* src);
//写一个函数指针为：char* (*p) (char* dest,char* src)=my_strcpy;
//写一个函数指针数组为；char* (*p[1]) (char* dest,char* src)={my_strcpy};
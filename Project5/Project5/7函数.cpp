#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>


//有输入参数parameter和输出参数return value（返回值） 函数通常被封装
//int add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = 0;
//	sum=add(a, b);
//	printf("%d", sum);
//	return 0;
//}



//C语言中函数有两种 库函数（C语言自带的函数） 自定义函数  www.cplusplus.com可以查看 库和函数（function）的说明文档   
//C语言中常用的函数 IO函数（input和output ） ，字符串操作函数 如strlen，字符操作函数（判断大小写 大小写转换等，内存操作函数，时间/日期函数，数学函数（数学计算等）
//要学会阅读文档学习函数  也可以使用MSDN   cppreference.com     zh,cppreference.com中文版网站


//int main()
//{   //strlen函数 求字符串长度
//	//strcpy函数 字符串拷贝 在www.cplusplus.com的strcpy页面可以看到 char * strcpy ( char * destination,conat char * source)两个传入参数表示将source 处的字符拷贝到destination处
//	char arr1[] = "hello";//监视中查看到 其内容为 hello\0
//	char arr2[] = "#########";//                  #########\0
//	//如果拷贝的arr1比arr2更长 则会溢出 就会bug
//	strcpy(arr2, arr1);//实际拷贝后arr2的内容为 hello\0###  但打印只打印出结束标志\0前的内容 求字符串长度时也只计算到\0之前
//	printf("%s\n", arr2);//经过调试监视 发现会连原字符的结束标志\0一起拷贝到目标字符串中
//
//	//memset 内存设置 
//	//memory 内存
//	char arr3[] = "#########";
//	memset(arr3, '*', 5);//将要更改*替换到arr3的前五个字符 
//	printf("%s\n", arr3);
//	return 0;
//}
//
//
//
////学会自定义函数也很重要
//
////函数的组成
//int add(int x, int y)//add为函数名 int是函数的返回类型（如果此处填写void则意思是该函数没有返回值） add（）括号内的是形式参数
//{//大括号内为函数体 交代函数是怎样实现的
//	int z = 0;
//	z = x + y;
//	return z;//函数的返回值
//}


//简单函数的练习  1.输出两数的较大值（很简单，这个跳过）   2.对两个数的值进行交换（此函数无返回值，返回值类型用void）

//void change(int* p1, int* p2)//函数的传址调用 注意这里必须获取到要修改的数的地址 再通过地址对数字进行修改 
//{
//	int num = *p1;
//	*p1 = *p2;
//	*p2 = num;
//}
//
//
////void change* (int x, int y)//函数的传值调用 这样写是没有用的 在函数调用的时候会利用另外的空间储存x y 不会对a b产生影响
////{
////	int num = x;
////	x = y;
////	y = num;
////}
//
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	change(&a, &b);
//	printf("%d %d", a, b);
//}


//判断是否是素数的函数
//#include<math.h>
//int if_prime(int a)
//{
//	int i = 0;
//	for (i = 2; i < sqrt(a); i++)//不用运行到a 对a进行开方可以减少计算量
//	{
//		if (a % i == 0)
//		{
//			return 0;//如果不是素数 就会直接返回0 return之后就不会执行后面的内容
//		}
//	}
//	return 1;
//}
//int main()
//{
//	if (if_prime(11) == 1)
//	{
//		printf("是素数");
//	}
//	return 0;
//}


//二分法在有序数组中查找数字
//int find(int arr[], int k, int sz)
//{  
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int ret = (left + right) / 2;
//		if (arr[ret]<k)
//		{
//			left = ret + 1;
//		}
//		else if (arr[ret]>k)
//		{
//			right = ret - 1;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr)/sizeof(arr[0]);//这一句如果放在函数里 sz的值会错误 
//	//printf("%d", sz);
//	if (find(arr, k, sz))
//		printf("找到了");
//	else
//		printf("没有");
//	return 0;
//}



//定义函数每被引用一次就加一
//void count(int* p)
//{
//	(*p)++;//++的优先级更高 会抢先作用在p上 所以要用括号把*p当作整体
//}
//int main()
//{
//	int times = 0;
//	count(&times);
//	printf("%d",times);
//}


//函数的嵌套调用
//void a()
//{
//	printf("a");
//}
//void b()
//{
//	printf("a");
//	printf("b");
//
//}
//
//int main()
//{
//	b();
//	return 0;
//}




//函数的链式访问  将一个函数的返回值作为另一个函数的参数
//int main()
//{
//	printf("%d\n", strlen("abc"));
//	printf("%d", printf("%d", printf("%d", 43)));//结果是4321 printf()函数的返回值是打印的字符的个数  43为两个字符，返回2 打印2后又返回1 最后打印1
//}


//函数的声明
//int add(int, int);//add函数在main后定义  这里声明可以避免报错  但这不是声明真正的用法
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum=add(a, b);
//	printf("%d", sum);
//	return 0;
//}
//
//int add(int a, int b)
//{
//	return a + b;
//}



//真正的用法
//函数的定义放入add,c文件中 声明放入add.h文件中 这两个文件共同构成了一个加法模块 在工程中常常将各种功能拆分成模块 函数声明一般放在头文件中
//#include "add.h"
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum=add(a, b);
//	printf("%d", sum);
//	return 0;
//}




//递归
//int main()
//{
//	printf("abc");
//	main();
//	return 0;//如果让这个程序一直运行下去就会自动停止 stack overflow 栈溢出  栈区用来存储局部变量和函数的形参 除了栈区还有堆区（动态开辟的内存）和静态区（全局变量和static修饰的变量）
//}



//按顺序输出数字的每一位数
//void print(int n)
//{
//	if (n > 9)//正确的递归一定有限制条件 且每一次递归都越来越接近条件
//	{
//		print(int(n / 10));
//	}
//	printf("%d\n", n % 10);
//}
//int main()
//{
//	int a = 1234;
//	print(a);
//	return 0;
//}


//不创建临时变量 求字符串长度

//int len(char* str)
//{
//	int count = 0;
//	while (*str != '\0')//传入的数组以\0结尾 不是\0就继续循环
//	{
//		count++;
//		str++;//得到下一个元素的地址
//	}
//	return count;
//}//不符合题目要求



//int len(char* str)
//{
//	if (*str != '\0')
//	{
//		str++;
//		return 1 + len(str);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//{
//	char arr[] = "abcd";
//	printf("%d", len(arr));//注意数组传参不是整个数组 而是首元素的地址
//	return 0;
//}



//求第n个斐波那契数
//int count = 0;
//int fib(int n)
//{
//    if (n == 3)
//    {
//        count++;
//    }
//    if (n <= 2)
//    {
//        return 1;
//    }
//    else 
//        return fib(n - 1) + fib(n - 2);
//}//需要运行很久 有很多数据被重复计算  这种问题不适合用递归计算  用循环更加适合
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d", &a);
//    b = fib(a);
//    printf("%d", b);
//    return 0;
//}



//递归的经典题目 汉诺塔问题 青蛙跳台阶问题  可以自行研究
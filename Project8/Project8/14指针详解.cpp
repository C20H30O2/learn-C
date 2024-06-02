#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>


//void test(int arr[])
//{
//	printf("%p\n", arr);
//	int sz = sizeof(arr) / sizeof(arr[0]);//在64位平台中结果为2
//	printf("%d\n", sz);
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	test(arr);
//	return 0;
//}



//int main()
//{//这样各种打印之间的不同
//	int arr1[] = { 1,2,3 };
//	printf("%p\n", arr1);//整型数组无法直接这样打印 结果会是随机值
//	printf("%d\n", arr1[0]);
//
//	char arr[] = "abcdef";
//	char* pc = arr;
//	printf("%p\n", arr);
//	printf("%p\n", pc);
//
//	printf("%s\n", arr);
//	printf("%s\n", pc);//注意这样也可以打印出完整的字符数组
//	return 0;
//}



//int main()
//{
//	char a[] = "abc";//将鼠标停留在"abc"上 发现其为const 具有常属性 
//	a[0] = 'b';
//	printf("%s\n", a);//可以看到在这里这样进行修改并没有报错，且能正常打印
//
//
//	//char* p = "abcdef";//在老师的演示中 "abcdef"作为一个常量字符串  这里会将a的地址赋给p   但是现在这样写会报错 
//	const char* p = "abcdef";//必须要带上const才能赋值  这样两边都具有常属性 就不会报错 
//	printf("%p\n", *p);
//
//	//*p=   这样就无法通过p去修改
//	//printf("%p\n", *p);
//	return 0;
//}




//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//	if (arr1 == arr2)
//	{
//		printf("hehe");
//	}
//	else
//	{
//		printf("haha");
//	}
//	if (p1 == p2)//我们发现 因为"abcdef"是相同的常量字符串 系统为了节省空间  就让其地址是相同的了 
//	{
//		printf("hehe");
//	}
//	else
//	{
//		printf("haha");
//	}
//
//	return 0;
//}
// 






//指针数组 是数组 用来存放指针
//int main()
//{
//	int arr[10] = { 0 };//整型数组
//	char ch[5] = { 0 };//字符数组
//	int* parr[4];//存放整型指针的数组
//	char* pch[5];//存放字符指针的数组  这两个都叫做指针数组
//	
//	
//
//	//指针数组的使用方法
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d\n", *(parr[i] + j));
//		}
//	}
//	return 0;
// }





//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//arr为首元素地址  &arr[0]也是首元素地址    注意&arr是数组的地址
//	int(*p)[10] = &arr;//将数组的地址存储起来  
//	//这里的p就是数组指针 指向一个数组
//	//注意 []的优先级比*高 所以为了保证p是一个指针类型要用()将*p括起来  p是一个指针类型 指向的是 int[10]类型的数组
//	//如果写成 int *p{10]  就表明p是一个数组 数组内存储的是 int*类型的元素
//
//
//	if (*p == arr)
//		printf("yes\n");
//
//
//	printf("%d\n", *(*p));
//
//
//
//	//使用方法
//
//	int i = 0;
//	int* pp = arr;
//	for (i = 0; i < 10; i++)
//	{
//		//1
//		//printf("%d ", (*p)[i]);//对p解引用就指向了数组 *p=arr   
//
//
//		//2
//		//printf("%d", *(*p + i));
//
//
//		//3
//		printf("%d", *(pp + i));
//	}
//	return 0;
//}




//void print1(int arr[3][5], int x, int y)
//{
//	int j = 0;
//	int i = 0;
//	for(i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//
////参数是指针的形式
//void print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//
//			//还有多种相同结果的不同使用方法
//			//printf("%d ", (*(p + i))[j]);//如果p+i 定位到打大数组内的第i+1个小数组  再使用[j]定位到小数组内的第j+1个元素
//
//			//printf("%d ", *(*(p + i)+j));//*(p+i)=arr[i], arr[i]就是arr中的第i+1个小数组 所以arr[i]其实可以看作该小数组内的首元素的地址 
//		
//			printf("%d ", *(p[i] + j));//较难理解
//
//			printf("%d ", p[i][j]);//更难理解  p作为指针居然可以直接这样使用！！！！！
//		}
//		printf("\n");
//	}
//}
//
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print1(arr, 3, 5);//int arr[3][5] 作参数接收到整个数组 
//	print2(arr, 3, 5);//int(*p)[5] 作参数接收到数组内的第一个小数组的地址
//
//	return 0;
//}




//int main()
//{
//	int arr[5];//有五个整型元素的数组
//	int* parr1[10];//指针数组 有10个元素 每个元素的类型是int* 
//	int(*parr2)[10];//数组指针 指向一个存储了10个int类型的数组
//	int(*parr3[10])[5];//是一个数组  
//	//一定要注意 数组除去数组名和[] 剩下的就是数组中存储的数据类型 
//	//所以这里parr3是一个有是个元素的数组 其元素类型是int(*)[5]  即指向一个存储了五个int类型元素的数组
//	//总结：parr3 是一个数组，该数组有10个元素，每一个元素是一个数组指针， 数组指针指向的数组有五个元素，每一个元素是int
//	return 0;
//}




//一维数组传参
//void test(int* arr)
//{
//
//}
//void test2(int** arr)
//{
//
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);//test的()中可以写int arr[]或int arr[10]或int *arr  
//	test2(arr2);//test2的()中可以写int *arr[20]或int** arr     
//	//具体以那种类型接收参数 可以根据实际来改变
//	return 0;
//}




//二维数组传参
//void test(int *arr)//错误
//{}
//void test(int arr[][5])//注意可以省略行 不可以省略列  这里的写法是正确的
//{}
//void test(int(*p)[5])//int(*p)[5] 正确
//{}
//void test(int **arr)//错误
//{}
//void test()
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//	return 0;
//}



//当函数的参数为二级指针是 能接收什么参数？
//void test(char **p)
//{
//
//}
//
//int main()
//{
//	char c = 'b';
//	char* pc = &c;
//	char** ppc = &pc;
//	char* arr[10];
//	test(&pc);
//	test(ppc);
//	test(arr);//都没有问题
//}



//函数指针
//int ADD(int x, int y)
//{
//	return x + y;
//}
//
//int main() 
//{
//	int a = 10;
//	int b = 20;
//	int arr[10]{ 0 };
//	int(*p)[10] = &arr;
//	
//
//	//&函数名 和 单纯的函数名都能表示函数的地址
//	printf("%p\n", &ADD);
//	printf("%p\n", ADD);
//
//
//	//调用函数
//	printf("%d\n", ADD(a, b));
//	int (*pa)(int, int) = ADD;//*p表示p是个指针  且该函数返回类型是int 参数是int和int
//	printf("%d\n", (*pa)(2, 3));//先解引用 在用括号传入参数
//
//	return 0;
//
//}



//void print(const char* str)
//{
//	printf("%s\n", str);//我感觉神奇的是str居然能直接打印
//	printf("%p\n", str);
//	//printf("%s\n", *str);//而试图解引用再打印却没有内容输出
//}
//
//int main()
//{
//	void(*p)(const char*) = print;
//	(*p)("hello");//可以理解"hello"作为字符数组传入函数的是首元素的地址
//	return 0;
//}






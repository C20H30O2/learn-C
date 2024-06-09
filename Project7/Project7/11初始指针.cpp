#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>


//int main()
//{
//	int a = 1;
//	int* p = &a;//取出a的地址放在p中，p就是一个指针变量，存放在指针中的值都当做地址来处理 
//	return 0;
//}



//指针的意义
//int main()
//{
//
//	int a = 0x11223344;
//	int* pa = &a;
//	*pa = 0;
//
//	//printf("%d", sizeof(pa));//指针的大小与所在平台有关
//	printf("%p\n", pa);
//
//	//char* pc = &a;
//	//*pc = 0;
//	//printf("%p\n", pc);//现在这样写会直接报错“初始化”: 无法从“int *”转换为“char *”  但老师那个时候好像没问题
//
//
//	//原本这里可以看出 指针类型决定了指针进行解引用操作的时候，能够访问空间的大小 比如double类型的指针能访问八个字节 而char类型只能访问一个字节
//	//在老师的视频里可以看出 int类型的指针可以将int类型的a赋值为0 但char类型的指针只能访问a的一个字节 所以只有一个字节被改变
//	return 0;
//}



//int main()
//{
//
//	int a = 0x11223344;
//	int* pa = &a;
//	char* pc = &a;
//	printf("%p\n", pa);
//	printf("%p\n", pa+1);
//
//	printf("%p\n", pc);
//	printf("%p\n", pc+1);
//
//	//原本这里可以看出 指针类型决定了指针加一向后跳几个字节 比如这里的char类型指针加一只向后跳了一个字节 而int跳了四个字节
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;//首元素的地址
//	//char* p = arr;//原本老师也将int改成了char进行测试 
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + 1) = 1;
//	}
//	return 0;
//}





//野指针

//1.指针未初始化
//int main()
//{
//	int a;//这里未初始化的int会被赋予随机值
//	int* p;//局部指针变量未初始化 默认为随机值
//	return 0;
//}



//2.指针越界访问
//int main()
//{
//	int a[10] = { 0 };
//	int* p = a;
//	int i = 0;
//	for (i = 0; i < 12; i++)
//	{
//		//当指针指向的范围超出数组arr的范围时，p是野指针
//		*(p ++)=1;
//	}
//	return 0;
//}



//3.指针指向的空间释放
//int* fun()
//{
//	int a = 0;//这里的a作为局部变量 在超出范围时就被销毁 并将占用的地址释放 所以下面的p的地址指向的 不是a
//	/*int* p = &a;*/
//	/*return p;*/aswe4
//	return &a;
//}
//int main()
//{
//	int* p = fun();
//	*p = 20;
//	return 0;
//}


//避免野指针
//int main()
//{
//	int a = 10;
//	int* p=&a ;
//	*p = 20;
//	p = NULL;//如果不再需要使用时可以赋给一个NULL
//
//	if (p != NULL)//在使用指针前可以进行判断 
//	{
//		……
//	}
//	return 0;
//}




//指针运算
//1.指针加减整数 2.指针减指针
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *p);
//		p++;
//	}//利用指针的加法访问到每一个元素的地址 并将对应的元素其打印出来
//
//
//	int* vp;
//	for (vp = &arr[0]; vp < &arr[10];)
//	{
//		*vp++ = 0;//这里的vp会先被解引用然后把0赋给vp处的元素 再执行vp++  这个程序会把arr内的元素都变成0
//	}
//
//
//	int num = &arr[9] - &arr[0];//指针减去指针
//	printf("%d\n", num);//结果不是36 而是9  说明相减得到的数与元素个数相关 而不是内存大小
//
//
//	return 0;
//}


//利用指针求字符串长度
//int len(char* str)
//{
//	char* start = str;//说明str其实是第一个元素的地址
//	char* end = str;
//	while (*end != '\n')
//	{
//		end++;
//	}
//	return end - start;//相减的结果就是元素个数
//}
//int main()
//{
//
//
//	char arr[] = "bit";
//	int count = len(arr);
//	printf("%d\n", count);
//	return 0;
//}


//3.指针的关系运算
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p;
//	for (p = &arr[10]; p > &arr[0];)//这里下标为10的地址再arr之外 但对其--就是指向arr中下标为9的元素的地址 ，判断当p大于下标为0的元素的地址时条件满足
//	{
//		*--p = 0;
//	}//p > &arr[0]就是指针的关系运算
//	return 0;
//}//这里p初始指向数组最后一个元素后面的那个内存位置 这时与&arr[0]进行比较是被允许的



//C语言中允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针作比较，但是不允许与指向第一个元素之前的那个内存位置的指针作比较
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int* p;
//	for (p = &arr[5 - 1]; p >= &arr[0]; p--)
//	{
//		*p = 0;
//	}//当p指向数组的第一个元素之前的那个内存位置时条件不再满足 使用循环停止 但根据上面那句话知道要避免这样写 因为C语言的标准不能保证这种写法可行
//	return 0;
//}





//数组和指针
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);//1
//	printf("%p\n", arr+1);//2
//
//	printf("%p\n", &arr[0]);//3
//	printf("%p\n", &arr[0]+1);//4
//
//	printf("%p\n", &arr); //5
//	printf("%p\n", &arr+1);//6
//	//我们会发现1，3，5的结果相同   1，3的意义是一样的，所以加一后结果也相同 但是&arr+1后变化40 是一个arr的大小 所以在被取地址时 arr表示的是整个数组 
//	return 0;//arr不表示首个元素地址有两种情况 其一是被取地址时 其二是 被sizeof求大小的时候 求的是整个数组的大小
//}



//二级指针
//int main()
//{
//	int a=  0 ;
//	int* p1 = &a;
//	int** p2 = &p1;//二级指针
//	**p2 = 10;
//	printf("%d", a);
//	int*** p3 = &p2;//三级
//	return 0;
//}



//指针数组 用于存放指针
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr[3] = { &a,&b,&c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", *(arr[i]));
//	}
//	return 0;
//}

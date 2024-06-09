#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>


//结构的声明
//struct MyStruct
//{
//	memberlist;
//}variable-list;


//struct stu
//{
//	char name[10];//结构是一些值的集合 这些值被称为成员变量 结构的每个成员可以是不同类型的变量
//	char id[10];
//}s1,s2,s3;//在这里设定的s1 s2 s3 都是全局的结构体变量  
//
//typedef struct STU
//{
//	char name[10];
//}Stu;//使用typedef后可以在这里对结构体进行重命名 可以看到在下面只用了Stu就可以创建一个结构体对象 
//
//
//int main()
//{
//	struct stu s1{'jack','1234' };
//
//	Stu s4{"tom"};//
//
//	printf("%s\n", s4.name);
//
//	return 0;
//}




//struct phone
//{
//	int phonemunber;
//};
//
//
//struct info
//{
//	char name[20];
//	struct phone p;//可以嵌套
//};
//
//int main()
//{
//	struct info people1{"tom",{123} };
//	printf("%s\n", people1.name);//调用方式
//	printf("%s\n", people1.p.phonemunber);
//
//
//	return 0;
//}



//typedef struct stu
//{
//	char name[20];
//}stu;
//
//void print1(stu t)
//{
//	printf("name = % s\n", t.name);
//}
//
//void print2(stu* t)
//{
//	printf("name=%s\n", t->name);
//}
//
//int main()
//{
//	stu s1 = { 'jack'};
//	print1(s1);
//	print2(&s1);//发现p1和p2都可以完成打印任务 但是一般选择p2更好 因为p2只传入了地址 而p1是将对象拷贝了一份 
//	            //另外 函数传参的时候 参数是需要压栈的 当传入的参数是一个结构体变量的时候，结构体过大，参数压栈的系统开销会比较大 导致性能的下降 
//	return 0;
//}





//关于调试
//程序分为debug和release版本
//debug为调试版本 包含调试信息 不做优化 便于调试程序
//release为发布版本 进行了各种优化 便于用户使用
//可以在上方看到 可以将程序在debug和release版本中切换 （还可以在64位平台和32位平台间切换）

//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100; i++)
//	{
//		printf("%d\n",i);
//
//	}
//	return 0;
//}//发现可以在debug版本中通过监视来查看i的变化 但在release版本中会提示变量已被优化 不可使用



//常用快捷键
//f5 启动调试 经常用于直接来到下一个断点处
//f9 可以在某一行创建断点和取消断点 可以在程序的任意位置设置断点 使得程序在想要的位置停止执行
//f10 逐过程进行调试 
//f11 逐语句进行调试 可以进入函数内部 
//CTRL+f5 使得程序直接运行 而不调试



//调试时查看调用堆栈 调试时打开调试 打开窗口 可以看到调用堆栈 具体使用方法自行搜索
//void t2()
//{
//	printf("hehe\n");
//}
//void t1()
//{
//	t2();
//}
//void t()
//{
//	t1();
//}
//int main()
//{
//	t();
//	return 0;
//}



//用这段代码计算一到三的阶乘 输入三后发现 结果为15 而不是9
//这段代码计算阶乘有错误 因为ret计算完一次后没有归零
//可以在第二个for处设置断点 并右键断点 设置条件为i=3 时才停下 这样按下f5可以直接来到i=3  不用一下下按从一到二再到三
//来到三后再监视窗口发现ret为2 发现错误
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}





//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//    }
//	printf("%p\n", arr);
//	printf("%p\n", &i);//在早期版本的编译器中 我们会发现arr[12]的地址就是i的地址 所以在修改arr[12]的元素时修改了i的值 所以会产生死循环 
//	//按老师的演示 这里会进入死循环 但在vs2022中不会出现死循环 说明已经进行了优化
//	return 0;
//}




//字符串拷贝
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;
//}//这种写法太初级





//最终升级版
//#include<assert.h>
//char* my_strcpy(char* dest,const char* src)//将首元素地址返回  标准的strcpy函数也是返回地址  加const使src无法被修改 避免了一些可能产生的错误
//{
//	char* ret = dest;
//	assert(dest != NULL);//使得当dest=NULL时报错
//	assert(src != NULL);
//	while (*dest++ = *src++)//优先级是 先解引用 再++ 
//	{
//		;
//	}
//	return ret;
//}
//
//
//
//
//
//int main()
//{
//	char arr1[] = "##########";
//	char arr2[] = "bit";
//	char* a=my_strcpy(arr1, arr2);
//	printf("%p\n", my_strcpy(arr1, arr2));
//	printf("%s\n", arr1);//arr2会将结尾处的\0一起传入arr1 所以arr1后面的部分就不会被打印出来
//	return 0;
//}






//int main()
//{
//	const int num = 10;
//	int n = 100;
//	const int* p = &num;//const放在指针变量*的左边时 修饰的是*p 也就是说 不能通过p来改变*p（即num）的值
//	//*p=  //这样写会报错 说明num无法被这样修改
//	//p = &n;//但是p仍然可以改变
//
//
//	int* const p = &num;//const放在指针变量的右边时，修饰的是指针变量p本身，所以p不能被改变  可能是因为编译器版本更新 这里这样写就会报错 所以跳过这一部分内容
//	printf("%d\n", num);
//
//	return 0;
//}




//#include<assert.h>
//int my_strlen(const char* str)//对于不用修改的传入参数 可以赋予常属性 避免在写代码的过程中不小心对该参数进行修改
//{
//	printf("%p\n", str);
//	int count = 0;
//	assert(str != NULL);//保证指针的有效性
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//
//int main()
//{
//	char arr[] = "abcd";
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}




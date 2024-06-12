#define _CRT_SECURE_NO_WARNINGS 
#include<stdlib.h>//malloc 等动态内存分配函数
#include<string.h>//strcpy等字符串函数
#include<stdio.h>//printf
#include<errno.h>//调用strerror判断错误种类


//struct s
//{
//	char name[10];
//	int age;
//};
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	struct s arr[n];//这样设置的数组叫做变长数组，其长度可以在程序运行时指定， C语言在C99中增加了变长数组，但是有些编译器没有适配，比如这里vs是不允许这样写的
//	return 0;
//}
//在gcc中支持这种变长数组的写法



//动态内存分配
//已经了解的内存开辟方式比如：int a;  char arr[10];  
// 这种内存开辟方式的特点：1：空间的开辟大小是固定的
//                       2：数组在声明的时候，必须指定数组的长度
//但是有时候我们需要的空间大小在程序运行时才能知道，此时只能使用动态内存分配




//栈区：存放局部变量和函数的形式参数
//堆区：动态内存分配
//静态区：存放全局变量和静态变量

//动态内存分配函数：malloc,free,calloc,realloc


//void* malloc(size_t size)   在堆区开辟size个字节的空间，返回这个空间的地址,返回的类型是void*，所以使用时要先进行类型转换
//注意：当size很大时，如果空间不足，开辟会失败，此时会返回NULL

//void free(void* memblock)   输入指向动态开辟的内存的指针，将这块空间释放，还给系统
//当传入free的指针为NULL时，该函数不会进行任何操作
//如果传入的指针指向的空间不是动态开辟的，free函数的行为将是未知的


//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));//转换为int*类型
//	if (p == NULL)//内存开辟失败的情况
//	{
//		printf("%s\n", strerror(errno));//当函数运行失败是会将信息存储在error中，可以将其打印出来看看是什么错误 
//	}
//	else//开辟成功就可以使用
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//
//	//当开辟的内存不再使用时，一定要记得将空间释放
//	free(p);
//	p = NULL;//空间释放后，p仍然指向之前那个位置的指针，为了避免其成为野指针和越界访问，一定要将其设置为空指针
//
//
//	return 0;
//}




//void* calloc(size_t num,size_t size) 传入个数和每一个的大小，在堆区中开辟num*size个字节的空间，并将里面的num个元素（每个size个字节）全部初始化为0，返回指向这个空间的指针,
//开辟失败是仍然返回NULL

//void* realloc(void* memblock,size_t size) 原来动态开辟的空间太大或者太小可以使用该函数进行修改，
//传入指向原动态开辟空间的指针和想要的改变之后的大小，返回指向size大小的动态开辟空间的指针
//当想要扩大空间时，函数会先考虑在原空间之后补上增加的空间，此时返回的指针和原指针相同，
// 如果紧接着原空间之后的空间不够，函数会在堆区找另外的地方开辟size大小的空间，此时返回的指针和原指针不同，注意，在这种情况下函数会将原空间中的内容拷贝到新空间，然后将原空间释放。还给系统
//如果真的没有空间，函数会返回NULL
//如果我们传入空指针，那么此时realloc的功能和malloc相似，会在堆区开辟size个字节的空间，返回这个空间的地址

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));//输出值全部为0，因为已经被初始化为0
//		}
//	}
//
//	//如果我们觉得空间不够，可以使用realloc函数开辟更大的空间
//	int* ret;
//	ret=(int*)realloc(p, 50);//注意，有可能会开辟失败，如果直接将返回值交给p，p可能会变成NULL，此时就丢失了指向动态开辟空间的指针
//	if (ret != NULL)
//	{
//    	p = ret;
//		int i = 0;
//		for (i = 10; i < 15; i++)//使用增加的空间
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 15; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//
//	return 0;
//}





//常见的动态内存错误
//1；对NULL指针的解引用操作，要注意，在使用动态内存开辟函数返回的指针之前要进行判断是否为NULL
//2：对动态开辟的空间越界访问，要注意开辟的空间的大小，不要访问到空间之外

//3：使用free释放动态开辟内存的一部分
//举例：
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 1; i++)
//	{
//		*p++ = i;
//	}//注意如果这样使用p在动态开辟的内存中存储内容，p的位置会被改变
//	free(p);//p被改变了，此时释放空间会导致程序崩溃
//	p = NULL;
//
//	return 0;
//}

//4：对同一块动态内存的多此释放，解决方法：我们在每一次释放后就将指向原动态内存的指针设置为NULL，这样如果在之后的代码中不小心再次该指针进行释放，free函数接收到NULL就不会进行操作

//5：动态开辟内存忘记释放（内存泄漏）
//举例1：
//int main()
//{
//	while (1)
//	{
//		malloc(1);//在死循环中每次开辟一个字节的空间，如果在运行时打开计算机的内存界面，会发现内存被占用量快速增加
//	}
//	return 0;
//}



//举例2：
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
//在函数中开辟空间后，一旦走出函数，p就被销毁了，但是内存并没有被释放
//一定要避免写出这样的代码




//动态内存分配经典面试题

//1
//void test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	//str=NULL;//解决方法是在这里将str设置为NULL，这提醒我们在释放动态空间之后要记得将指针设置为NULL
//	if (str != NULL)
//	{
//		strcpy(str, "world");//发现可以打印出world但是代码存在很大的问题，str被释放之后又拷贝明显是非法访问内存了
//		                     //（str被释放后直接打印str也没有hello，因为这一块内存已经被系统收回）
//		printf(str);
//	}
//
//}
//int main()
//{
//	test();
//	return 0;
//}




//2

//在看题前先看一中字符串的打印方式：
//int main()
//{
//	const char* str = "abcdef";
//	printf("%s\n", str);
//	printf(str);//这种打印方式和上面的一种结果是一样的，可以采用这种方式打印字符串
//	printf("abcdef");
//	return 0;
//}


//题目：
//void getmemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void test(void)
//{
//	char* str = NULL;
//	getmemory(str);
//	strcpy(str, "hello world");//结果没有内容被打印出来，因为上面的p只相当于str地拷贝，一旦出了getmemory函数，p就会被销毁
//	printf(str);               //实际上没有传入str地地址，str就没有被改变，仍然是NULL，将字符拷贝到空指针处，再将空指针打印，程序会出错
//}                            //动态内存不但没有被释放，因为p被销毁，所以动态内存无法被找到，会造成内存泄漏
//int main()
//{
//	test();
//	return 0;
//}



//修改1
//void getmemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void test(void)
//{
//	char* str = NULL;
//	getmemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}                  
//int main()
//{
//	test();
//	return 0;
//}




//修改2
//char* getmemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void test(void)
//{
//	char* str = NULL;
//	str=getmemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}                  
//int main()
//{
//	test();
//	return 0;
//}





//3
//char* getmemory(void)
//{
//	char p[] = "hellp world";
//	return p;
//}
//void test(void)
//{
//	char* str = NULL;
//	str = getmemory();//char p[]只在函数getemory内部存在，一旦走出函数就被销毁了，即使str能取到相应地地址，再打印str不但取不到字符串，而且是非法访问内存
//	printf(str);      //解决方法:在char p前加上static延长其生命周期，被static修饰的量会被放入静态区
//}
//int main()
//{
//	test();
//	return 0;
//}







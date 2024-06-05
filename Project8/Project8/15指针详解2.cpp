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




//函数指针数组的使用


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
//void menu()
//{
//	printf("**********");
//	printf("*1.ADD 2.SUB*");
//	printf("*3.MUL 4.DIV*");
//	printf("*    0.exit*");
//}
// 
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do 
//	{
//		menu();
//		printf("请选择");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数");
//			scanf("%d%d", &x, & y);
//			printf("%d\n", ADD(x, y));
//			break;
//		case 2:
//			printf("请输入两个操作数");
//			scanf("%d%d", &x, & y);
//			printf("%d\n", SUB(x, y));
//			break;		
//		case 3:
//			printf("请输入两个操作数");
//			scanf("%d%d", &x, & y);
//			printf("%d\n", MUL(x, y));
//			break;	
//		case 4:
//			printf("请输入两个操作数");
//			scanf("%d%d", &x, & y);
//			printf("%d\n", DIV(x, y));
//			break;
//		case 0:
//			break;
//		default:
//			printf("输入错误，请重新输入");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//可以感受到用这种方法编写一个简易的计算器很麻烦，通过使用函数指针数组可以简化步骤



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
//int MUL(int x, int y)
//{
//	return x * y;
//}
//
//int DIV(int x, int y)
//{
//	return x / y;
//}
//
//void menu()
//{
//	printf("**********");
//	printf("*1.ADD 2.SUB*");
//	printf("*3.MUL 4.DIV*");
//	printf("*    0.exit*");
//}
//
//void Calc(int (*pf)(int , int ))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}//转移表
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(ADD);
//      	case 2:
//			Calc(SUB);	
//		case 3:
//			Calc(MUL);
//		case 4:
//			Calc(DIV);
//		case 0:
//			break;
//		default:
//			printf("输入错误");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//以上还涉及到回调函数的内容 回调函数是一个通过函数指针调用的函数， 如果你把一个函数的指针作为参数传入另一个函数，
// 当这个指针被用来调用其所指向的函数时，我们就说这是回调函数





//利用转移表的相关内容 写一个能给浮点型等类型排序的冒泡排序
//之前写的冒泡排序只能用来给整型排序 
//可以尝试了解库函数中的qsort函数来得出解决方法 只要能比较大小的类型qsort函数都能为其排序


//原冒泡排序
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[+1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//
//struct stu
//{
//	char naem[20];
//	int age;
//};
//
//int cmp_int(const void* e1, const void* e2)//为qsort函数定义比较两个整型的方法
//{                                          //qsort函数会根据该函数的返回值来判断所比较的两个元素的大小 
//	                                       //返回0视作相等 返回<0视作e2>e1  返回>0 视作e1>e2     
//	return *(int*)e1 - *(int*)e2;          //然后qsort函数会根据得到的大小关系决定比较的两个元素是否交换顺序 自动进行排序
//}
//
//
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz);//只能用来排序整型数组
//
//	struct stu s[3] = { {"a",10},{"b",20},{"c",30} };
//	float f[] = { 9.0,8.0,7.0 };
//	//qsort-- quick sort  快速排序
//	//void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*));//查看到的函数信息文档的内容
//	
//	//这里涉及到void*类型的指针
//	int a = 10;
//	void* p = &a;
//	//*p //发现void*类型的指针可以接收任意类型的地址
//	     //但是不能进行解引用操作 
//     //p+=1
//		 //也不能进行加减操作
//	*(int*)p = 20;
//	printf("%d\n",a);//可以成功改变a的值，说明使用void*类型的指针时要进行强制类型转换
//
//
//
//
//	//再来解读qsort函数的参数 记得引用头文件stdlib.h
//	//这里给出使用举例
//	//qsort(arr,sz,sizeof(arr[0],) 前三个参数分别为要排序的数组，数组的大小，和数组内一个元素的大小
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);//第四个参数为int (*compar)(const void*, const void*)类型 作用是传入我们自定义的排序的方法 
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;//发现使用qsort排序成功 如果不注释掉bubble_sort结果可能会有错误，不知道这是为什么
//}




//尝试模仿qsort写一个函数实现不同类型数组的排序  以加深理解

//struct stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_int(const void* e1, const void* e2)//为整型定制的比较方法
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//
//
//int cmp_float(const void* e1, const void* e2)//比较float类型的返回值千万不能像比较int一样
//{
//	if (*(float*)e1 == *(float*)e2)
//		return 0;
//	else if (*(float*)e1 > *(float*)e2)
//		return 1;
//	else
//		return -1;
//}
//
//
//
//int cmp_struct_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);//比较字符串要使用strcmp函数 之后会再讲字符串相关内容
//}
//
//
//
//int cmp_struct_age(const void* e1, const void* e2)
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//
//
//
//void swap(char* buf1,char*buf2,int width)//自定义的交换函数  传入的是要交换的两个元素的地址 width是每个元素的长度 这里交换的原理是将两个元素每个字节都相互交换 直到交换了width个字节，此时这两个元素被完全交换
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;//保存元素1的某个字节
//		*buf1 = *buf2;//将元素2的对应字节给到元素1
//		*buf2 = tmp;//将保存下的元素1的对应字节给到元素2
//		buf1++;
//		buf2++;//这两个地址都向下走一个字节 准备下一个字节的交换
//	}
//}
//
//void my_sort(void* base,int sz,int width,int (*cmp)(const void*e1,const void*e2))
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)//比较的趟数
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1; j++)//每一趟比较的次数
//		{       //自定义比较函数                                                                //可以知道width是数组的每个元素所占的字节数 
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)// base就是数组第一个元素的地址 将该地址强制转换为char*类型 其加上多少就前进多少个字节 加上若干倍的width就能得到数组中其他元素的地址 这样就能将不同元素的地址传入比较函数中进行比较
//			{
//               //如果条件成立，就要进行交换位置  自定义交换函数  
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//
//}
//
//void test_for_int()
//{
//	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//}
//
//
//void test_for_float()
//{
//	float arr[] = { 2.0,4.0,5.5,5.3,4.4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_sort(arr, sz, sizeof(arr[0]), cmp_float);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%f\n", arr[i]);
//	}
//}
//
//void test_for_struct()
//{
//	struct stu s[3] = { {'a',15},{'c',10},{'b',20} };
//	printf("%s\n", s[0].name);
//	printf("%s\n", s[1].name);
//	printf("%s\n", s[2].name);
//	int sz = sizeof(s) / sizeof(s[0]);
//	my_sort(s, sz, sizeof(s[0]), cmp_struct_name);
//	printf("%s\n", s[0].name);
//	printf("%s\n", s[1].name);
//	printf("%s\n", s[2].name);
//}
//int main()
//{
//	//test_for_int();//执行my_sort函数对整型数组排序的测试
//	test_for_float();
//	test_for_struct();//该排序结果可以在监视中查看
//	//test_for_age 就不再演示了
//	return 0;
//}
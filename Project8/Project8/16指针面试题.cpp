#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>



//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d\n", *(a + 1), *(ptr - 1));
//	return 0;
//}


//struct test
//{
//	int num;
//	char* pcname;
//	short sdate;
//	char cha[2];
//	short sba[4];
//}*p;
////这里的p是一个结构体指针  假设p的值是0x100000  如下表达式的结果是什么  已知结构体test类型的变量大小是32个字节
//
//int main()
//{
//	printf("%d\n", sizeof(struct test));
//	p = (struct test*)0x100000;//0x1 是十六进制表示的 转换成十进制就是1
//	printf("%p\n", p + 0x1);//因为p是结构体指针 而结构体的大小是32个字节 所以加上一后 就是0x100020  而0x20就是十进制的二十
//	printf("%p\n", (unsigned long)p + 0x1);//p先被转换成了unsigned int 类型 再加一 相当于1*16**5+1 其十六进制为0x100001 所以以地址形式打印就是这个十六进制 即0x100001
//	printf("%p\n", (unsigned int *)p + 0x1);//p被转换成了unsigned int * 加一会跳过四个字节 所以结果是0x100004
//	return 0;
//}




//int main()
//{
//	int a[4] = { 1,2,3,4 };//在小端存储中 a内的数据存储为 |01 00 00 00 |02 00 00 00 |03 00 00 00 |04 00 00 00|
//	int* ptr1 = (int*)(&a + 1);//&a取到的是整个数组的地址 加一后跳过整个数组的大小的字节数  
//	int* ptr2 = (int*)((int)a + 1);//先将a转化为int 加一后再转换为int*类型 相当于把数组首元素的地址a向后移动一个字节 所以由指向01 变为指向00
//	printf("%x,%x", ptr1[-1], *ptr2);//对ptr2解引用 会从00向后读取四个字节 即读取到00 00 00 02 转化为16进制为02000000 十进制为2*16**6
//	//以引用数组元素的方法arr[n] 去理解ptr1[-1]  ptr1[-1]=*(ptr1-1)  所以读取到04 00 00 00  十进制为4
//	return 0;
//}




//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };//注意：这里面使用的是小括号 所以应该将其解读为逗号表达式 其结果是最后一个表达式的值
//	//所以实际上a中存储的是{1,3,5},其余位置系统会补上0
//
//	int* p;
//	p = a[0];//所以p取到的是1的地址
//	printf("%d\n", p[0]);//p[0]=*(p+0) 即1
//	return 0;
//}




//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;//现在vs已经不支持这样赋值 
//	printf("%p,%d\n", &p{ 4][2] - &a[4][2],& p[4][2] - &a[4][2] });
//	return 0;
//}



//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);//&aa+1后跳过整个aa数组 转换为int*类型后 加减1只跳过一个整型 即4个字节 所以ptr1 - 1指向10 
//	int* ptr2 = (int*)(*(aa + 1));//aa即aa首元素的地址 即数组aa[0]={1,2,3,4,5}的地址 加一后来到aa的第二个元素 aa[1]={6,7,8,9,10} 所以ptr2得到的地址指向6 向前退一个字节后指向5
//
//
//	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));//10，5
//	return 0;
//}




//int main()
//{//这个题目原本不出现const  但是现在版本的vs不加const就不能赋值 
//	const char* a[] = { "work" ,"at","alibaba" };
//	//像"work"这样的，其类型为const char[5], 数组a中存放的元素是const char*类型 所以传入的是每个字符串首元素的地址
//
//	const char* pstr = "abc";//像这样的赋值，会将str的首元素的地址赋给指针变量  
//
//	const char** pa = a;//pa得到了a的首元素——‘w’的地址  的地址
//	pa++;//pa变成了a的第二个元素“a”的地址 的地址 
//	printf("%s\n", *pa);//pa解引用就是a的地址 从a的地址打印出at结束
//	return 0;
//}



//写解析太麻烦了  复习时自行解读——by 2024 6 5 myself
//int main()
//{
//	const char* c[] = { "enter","new","point","first" };
//	const char** cp[] = { c + 3,c + 2,c + 1,c };
//	const char*** cpp = cp;
//
//	printf("%s\n", **++cpp);//注意 ++cpp的结果会被保留 即cpp=cpp+1
//	printf("%s\n", *--*++cpp+3);
//	printf("%s\n", *cpp[-2]+3);//*(*(cpp-2))+3
//	printf("%s\n", cpp[-1][-1]+1);  //*(*(cpp-1)-1)+1     
//
//	return 0;
//}





//利用指针实现逆序字符串

#include<assert.h>
//void reverse(char* str)
//{
//	assert(str);//确保str不为空
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;//同时取到字符串左右两边的字符的地址 并进行交换 
//	while (left < right)//交换条件 
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[256] = { 0 };
//	//scanf("%s", arr);//如果输入的内容存在空格 scanf只会读取空格之前的内容 
//	gets_s(arr);//可以读取一整行的输入
//	reverse(arr);
//	return 0;
//}






//判断一个数是否为水仙花数（自幂数）
#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100000; i++)//这里直接计算出100000以内的所有自幂数
//	{
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp /= 10)//使用这种方式判断i是个几位数  当tmp变成个位数的时候 tmp/=10 返回0
//		{
//			n++;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);//pow 用于求某个数的n次方 引入math.h头文件
//			tmp /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//}





//打印指定字符排列的菱形图案
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);//输入要打印的菱形图案的上半部分的行数
//	int i = 0;
//	for (i = 0; i < line; i++)//打印上半部分
//	{
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)//至于什么时候打印空格 什么时候打印* 只要观察图案中空格和*跟行数的关系就能知道
//		{
//			printf(" ");//打印空格
//		}
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0; i < line - 1; i++)//打印下半部分
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * (line - 1 - i)-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}











//int main()
//{
//	int a = 10;
//	int const* p;
//	const int* pp;//p和pp相同 const修饰 使得指针指向的元素不能被改变
//	int* const ppp=&a;//这里的const修饰 使得ppp不能被改变  但其指向的元素能被修改
//	const int* const pppp = &a;//都不能被修改
//
//	*ppp = 20;
//	printf("%d\n", a);
//	return 0;
//}



//调整数组中奇数和偶数的顺序  将奇数全部放在前面 偶数放在后面

//void move(int* arr,int sz)
//{
//	int* left = arr;
//	int* right = arr + sz - 1;
//	int i = 0;
//	while (left < right)
//	{
//		if (*left % 2 == 0)
//		{
//			if (*right % 2 != 0)
//			{
//				int tmp = *right;
//				*right = *left;
//				*left = tmp;
//				left++;
//				right--;
//			}
//			else
//				right--;
//		}
//		else
//			left++;
//    }
//}
//
//void print(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int arr2[] = { 1,1,1,1,1,1,1,1,1,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//printf("%d\n", *(arr + sz - 1));
//	move(arr,sz);
//	print(arr, sz);
//	return 0;
//}






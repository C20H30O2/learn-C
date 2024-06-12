#define _CRT_SECURE_NO_WARNINGS 
#include<stdlib.h>//malloc 等动态内存分配函数
#include<string.h>//strcpy等字符串函数
#include<stdio.h>//printf


//柔性数组
//C99中，结构中的最后一个元素允许是未知大小的数组，这就叫做柔性数组成员
//struct s1
//{
//	int n;
//	int arr[];
//};
//
//struct s2
//{
//	int n;
//	int arr[0];
//};
////这是设置柔性数组的两种方式，这两种方法都使arr成为柔性数组，这两种方法是一样的，如果一种不可用可以试试另一种
//
//int main()
//{
//	printf("%d\n", sizeof(s1));//结果大小中只计算了int成员的大小
//	printf("%d\n", sizeof(s2));//所以发现柔性数组的大小是不被计算在内的
//
//
//	//使用柔性数组
//	struct s1* ps = (struct s1*)malloc(sizeof(struct s1) + 5 * sizeof(int));
//	//在这里，我们利用malloc为一个struct s1类型开辟了一块动态空间，获得了一个指向该struct s1类型的指针，从其空间大小中可以看出，我们为arr提供了5个int的空间
//	//我们也可以知道，在该空间中，n的后面紧跟着arr，他们之间没有进行内存对齐
//	
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;//在调试中的内存界面输入ps可以看到ps指向空间中n的变化和arr的内容的变化
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//
//
//	//调整大小
//	realloc(ps, sizeof(struct s1) + 10 * sizeof(int));//使用动态内存分配函数应该像一开始一样小心一些，但是这里作为演示就省略一些内容
//
//
//	//释放
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}






//自己也可以用一种方式实现柔性数组
struct s
{
	int n;
	int* arr;
};

int main()
{
	struct s* ps = (struct s*)malloc(sizeof(struct s));
	ps->arr =(int*) malloc(5 * sizeof(int));
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ps->arr[i]);
	}


	//调整大小
	int* ret=(int*)realloc(ps->arr, 10 * sizeof(int));
	if (ret != NULL)
	{
		ps->arr = ret;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}

	//释放内存
	free(ps->arr);
	free(ps);//注意：一定要先释放ps->arr 因为arr存储在ps指向的空间中，如果先释放ps，arr就无法找回了
	return 0;
}
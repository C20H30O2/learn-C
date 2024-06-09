#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>


//自己写一个函数计算字符串长度
#include<assert.h>
//int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str != '\n')
//	{
//		count++;
//		str++;
//	}
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = { 'a','b','c','d','e' };//这样写是没有\0的 使用strlen会得出随机值
//
//	printf("%d,%d", strlen(arr1), strlen(arr2));
//
//	//strlen返回的是size_t类型 其实就是unsigned int类型
//	if (strlen("abc") - strlen("abcdef") > 0)//unsigned int 类型的3-6的结果也是无符号数  在判断中也是认为大于0的
// 	{
//		printf("hehe\n");
//	}
//	else {
//		printf("haha\n");
//	}
//
//	//自己写的my_strlen函数返回的是int类型 不会出现上面的情况 返回int 和返回unsigned int 类型各有各的利弊 不必刻意更改
//
//	return 0;
//}





//strcpy 拷贝字符串
//自己写一个拷贝字符串的函数

//char* my_strcpy(char* dest,const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	while (*dest++ = *src++)//包含src中的\0一起拷贝到dest中
//	{
//		;
//	}
//	return ret;//返回目的空间的起始地址
//}//这是经过优化的贴近库函数strcpy的版本


//注意调用库函数strcpy时 源字符串必须以\0结束 该函数会连同\0一起，将源字符串中的字符拷贝入目标空间
//必须保证目标空间足够大，确保能存放源字符串 且目标空间必须可变，即不能加上const赋予常属性




//strcat
//char* my_strcat(char*dest,const char*src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src);
//	while (*dest != '\0')
//	{
//		dest++;
//	}//让指针dest指向dest的\0 
//	while (*dest++ = *src++)//在dest的\0处开始加入src
//	{
//		;
//	}
//	return ret;//和strcpy的库函数一样返回dest的首元素地址
//}
//注意使用库函数stract时 源字符串必须以\0结束  目标空间必须可修改且足够大 





//strcmp
//字符串的比较方法和在python学到的一样  忘记了就去查
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//确保两个字符串不为空
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//
//
//int main()
//{
//	const char* p1 = "abc";
//	const char* p2 = "abcd";
//	int ret = my_strcmp(p1, p2);
//	printf("ret=%d\n", ret);
//
//	return 0;
//}


//在vs中调用strcmp比较字符串 相同时返回0 p1>p2时返回1 p1<p2时返回-1
//但在其他地方 可能返回其他值 
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//确保两个字符串不为空
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;//比如这里返回的就是被比较的两个字符的阿斯克码值之差 
//}
//
//
//int main()
//{
//	const char* p1 = "abce";
//	const char* p2 = "abcd";
//	int ret = my_strcmp(p1, p2);
//	printf("ret=%d\n", ret);
//
//	return 0;
//}





//strncpy  相比strcpy多了一个参数 
//int main()
//{
//	char arr1[10] = "abcdefgh";
//	char arr2[] = "bit";
//    strncpy(arr1, arr2, 6);//n=6 将arr2中6个字符拷贝到arr1中 这里展示的是arr2中元素少于n的情况 会用\0补全长度不够的部分 arr1变成bit\0\0\0gh\0\0
//
//	char arr3[10] = "abcdef";
//	char arr4[] = "def";
//	strncpy(arr3, arr4,2);//arr3会变成decdef\0\0\0\0
//
//	int a = 1;
//	return 0;
//}


//可以查看学习库函数strncpy的源码





//strncat
//int main()
//{
//	char arr1[30] = "hello\0xxxxxxx";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 3);//只向arr1的\0处开始追加了arr2中的3个元素 虽然没有读取到arr2的\0 但追加完wor后仍然会加一个\0  所以这里的arr1变成了hellowor\0xxxxxx\0\0……
//	printf("%s\n", arr1);
//
//
//	char arr3[30] = "hello\0xxxxxxxxxxxx";
//	char arr4[] = "world";
//	strncat(arr3, arr4, 8);//追加的个数大于arr4中的元素个数时 只将arr4中的元素追加 不添加\0以补齐数目 所以arr3变成helloworld\0xxxxxxx\0\0……
//	return 0;
//}
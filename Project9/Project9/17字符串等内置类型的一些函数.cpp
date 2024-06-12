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




//strncmp 字符串比较函数 可以指定比较的字符个数
//int strncmp(const char*string1,const char* string2,size_t count)
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcqef";
//	int ret1= strcmp(p1, p2);
//	int ret2=strncmp(p1,p2,3);//比较三个字符 输出结果为0
//	printf("%d,%d\n", ret1, ret2);
//	return 0;
//}




//strstr 字符串查找函数 查找一个字符串中是否存在另一个字符串

//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);//	确保p1和p2不为空指针
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* cur =(char*) p1;
//	if (*p2 == '\0')
//	{
//		return (char*)p1;
//	}
//	while (*cur)
//	{
//		s1 = cur;//查找的实现原理很简单 对于p1中的每一个字符都从该字符开始比较p2长度的字符个数 当s1指向\0时说明不存在 
//		s2 =(char*) p2;
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))//可以简化为 while(*s1 && *s2 && (*s1==*s2)) 
//		{
//			s1++;
//			s2++;
//
//		}
//		if (*s2 == '\0')
//		{
//			return cur;//找到子串
//		}
//		cur++;
//		//printf("hehe");
//	}
//	return NULL;//找不到子串
//
//}
//
//int main()
//{
//	const char* p1 = "abcdefabcdef";
//	const char* p2 = "def";
//	const char* ret1 = strstr(p1, p2);//注意其返回的是const char* 类型   如果存在该字符串则其返回的内容是p2的第一个元素在p1中的地址  不存在则返回NULL   若p1中有多个p2字符串，返回的是第一次出现的地址
//	const char* ret2 = my_strstr(p1, p2);//注意其返回的是const char* 类型   如果存在该字符串则其返回的内容是p2的第一个元素在p1中的地址  不存在则返回p1首元素的地址
//	if (ret2 != NULL)
//		printf("找到了");
//	else
//		printf("没有找到");
//}

//还有很经典的一种字符串匹配算法叫做kmp算法 涉及到数据结构的知识 可以自行了解




//strtok 是用于字符串切割的函数  char* strtok(char* str,const char* sep)  sep参数是一个字符串，定义了用作分割的字符集合
//int main()
//{
//	char arr[] = "abc@def.com@ppp";
//	const char* p = "@.";
//
//	char* ret = strtok(arr, p);//调用一次该函数只进行一次切割 即遇到第一个p中的字符就将该字符替换为\0 然后停止
//	printf("%s\n", ret);//因为p中的字符被替换成了\0,所以打印会在此处停止
//
//	ret = strtok(NULL, p);//strtok函数会记住上次切割的位置  如果要对上面的字符串进行再次切割就不要再传入地址，只需要传入NULL就行
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//
//
//
//	//但是实际上strtok配合循环，可以有更加方便地写法
//	char arr2[] = "abc@def.com@ppp";
//	char* ret2 = NULL;
//	for (ret2 = strtok(arr2, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret2);
//	}
//
//	return 0;
//}




//strerror   char* strerror(int errnum) 该函数会返回错误码所对应地错误信息
//#include<errno.h>
//int main()
//{
//	//错误码 0——NO error
//	//       1——Operation not permitted 
//	//       2——No such file or directory
//	//       ………………
//	//errno是一个全局地错误码地变量 
//	//当C语言地库函数在执行过程中发生了错误，就会把对应的错误码赋值到errno中
//
//
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("no error");
//	}
// 	return 0;
//}



//判断字符的函数 如果参数符合条件就返回真
//iscntrl 任意字符    isspace 空白字符包括' ','\f','\n','\r','\t','\v'    isdigit 十进制数字1——9   
// isxdigit 十六进制数字1——f，A——F        islower 小写字母a——z    isupper 大写字母A——Z 
// isalpha 字母         isalnum 字母和数字     ispunct 标点符号，任何不属于数字或者字母的可打印的字符   
// isgraph 任何图形字符    isprint 任何可以打印的字符包括空白字符和图形字符




//字符转换  
//int tolower (int c)  推测int类型应该是指的字符的阿斯克码值    
//int toupper (int c)  

#include<ctype.h>
//int main()
//{
//
//	char ch = '2';
//	int ret = islower(ch);//判断ch是否是小写字母
//	int ret2 = isdigit(ch);
//	printf("%d,%d\n", ret,ret2); //为真则返回正数
//
//	char ch1 = toupper(' ');
//	char ch2 = toupper('q');
//	printf("%d,%d\n", ch, ch2);//以int类型打印的是转化后的字符的阿斯克码值 比如Q的阿斯克码值是81
//	
//	return 0;
//}



//int main()
//{
//	char arr[] = "I Am A Student";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}







//以上字符串函数作用于字符串 比如strcpy无法拷贝int类型的数组
//memcpy可以用来拷贝int类型的数组和其他各种类型

//尝试自己实现memcpy的功能
//void* my_memcpy(void* dest,const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//struct S
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));//看需要传入sizeof(arr1)就可以知道 该函数其实是将arr1中的sizeof(arr1)个字节拷贝到arr2中
//
//
//	struct S arr3[] = { {"a",10},{"b",20},{"c",30} };
//	struct S arr4[3] = { 0 };
//	memcpy(arr4, arr3, sizeof(arr3));//同样可以拷贝
//
//	
//	return 0;
//}





//memmove可用来处理内存重叠情况下的拷贝   memmove(arr2, arr1, sizeof(arr1))
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int i = 0;
//	memmove(arr + 2, arr, 20);//将arr中的1，2，3，4，5 拷贝到arr中原本是3，4，5，6，7的位置   总大小是20个字节
//	//memcpy(arr + 2, arr, 20);//我们发现vs中的memcpy函数也能做到内存重叠情况下的拷贝，但是在C语言中没有这样的要求，C语言只要求memcpy能够处理不重叠情况下的拷贝就行，所以在别的编译器中可能就无法实现该功能
//	for (i = 0; i < 9; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



//为了实现自己的memmove函数，我们需要知道在内存重叠情况下的拷贝方式
//如果我们要将arr中的某一部分拷贝到arr中的另一个部分，那么dest和src的相对位置有三种情况，
//1:dest<src  采用从前向后拷贝   2:dest>src && dest<src+count 采用从后向前拷贝   3:dest>src+count  此时目标区域和源头区域没有重叠，可以采用任意方式拷贝 
//  

//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	if (dest < src)
//	{
//		//从前向后拷贝
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			dest=(char*)dest+1;
//			src=(char*)src+1;
//			
//		}
//	}
//	else
//	{
//       //从后向前拷贝
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}







//memcmp函数  int memcmp(const void* ptr1,const void* ptr2,size_t num)

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };//10 00 00 00 20 00 00 00 30 00 00 00 40 00 00 00 50 00 00 00  arr1在内存中的存储
//	int arr2[] = { 1,2,5,4,3 };//10 00 00 00 20 00 00 00 50 00 00 00 40 00 00 00 30 00 00 00  arr2
//
//	int ret = memcmp(arr1, arr2, 9);//比较arr1和arr2中的九个字节
//	printf("%d\n", ret);//返回-1说明arr2的前九个字节比arr1更大
//	return 0;
//
//}




//memset 内存设置
//int main()
//{
//	char arr1[10] = "";
//	memset(arr1, 'a', 10);//将arr1中的10个字节内容修改为字符a
//
//	int arr2[10] = { 0 };
//	memset(arr2, 1, 10);//10指的是修改的字节数，而arr2中有40个字节，所以这里并不是将a中的全部十个元素都修改为1
//	return 0;
//}
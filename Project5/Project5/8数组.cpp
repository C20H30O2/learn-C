#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>
//数组是一组相同类型元素的集合
//
// 
// 



// int main()
//{
//	//type_t arr_name  [const_n];//数组创建方式 类型 数组名 数组大小 []内必须是一个常量
//
//	//int a = 10;
//	//char arr[a];//不能这样写 a不是常量
//
//	char arr1[10];
//	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };//完全初始化
//	int arr3[10] = { 1,2,3,4 };//数组的初始化 在创建数组时赋值 这里是不完全初始化 剩下的元素默认为0 可以使用监视窗口查看剩下的元素
//	char arr4[5] = { 'a','b','c',97};//这里面出现的数字代表其在阿斯克码表中代表的字符
//	printf("%s", arr4);
//	char arr5[5] = "abc";//元素为；a b c \0 0    可以看出与下面的arr6有所不同  存储的结果是一样的 但是方式不一样
//	char arr6[5] = { 'a','b','c' };//元素为；a b c 0 0           通过修改发现 arr5的[]中不能填3 但是arr6可以 
//
//
//
//	char arr7[] = "abcdef";//元素为；a b c d e f \0  其对应下标分别为0 1 2 3 4 5 6   系统自动将大小设定为了7
//	printf("%d", sizeof(arr7));//7  sizeof 计算arr7所占空间的大小  计算变量 数组 类型的大小 单位是字节
//	printf("%d", strlen(arr7));//6  strlen计算字符串长度 遇到\0就会停止 不计入\0   strlen只能计算字符串的长度
//
//	return 0;
//}



//int main()
//{
	////一维数组
	//char arr1[] = "abc";
	//char arr2[] = { 'a','b','c' };
	//printf("%d", sizeof(arr1));//要注意arr1中有四个元素 a b c \0 所以这里是4
	//printf("%d", sizeof(arr2));//这里没有\0所以是3
	//printf("%d", strlen(arr1));//3
	//printf("%d", strlen(arr2));//strlen识别到\0后停止 但这里没有\0 所以一直随机 直到随机到\0 所以结果为随机数

	//int i = 0;
	//for (i = 0; i<int(strlen(arr1)); i++)//strlen返回的是一个无符号数 所以要转化为int类型
	//{
	//	printf("%c", arr1[i]);//利用下标访问内容 和之前学的python一样
	//	printf("%p", &arr1[i]);//观察打印出的地址发现数组中存储的数据的地址是相连的 地址是以十六进制表示的 这些数据的地址前后都差4 正好是每个数据的大小
	//}



	//二维数组
	//int arr3[2][2] = { 1,2,3 };//二行二列  从第一行开始填入数据 不足的用0补上 
	//int arr4[2][2] = { {1},{2,3} };//自己定义不同的行 这里第一行为1 0 第二行为2 3
	//int arr5[][2] = { 1,2,3 };//发现行数可以省略 但是列数不能省略 
	//
	//
	////二维数组的使用也是利用下标
	//int j = 0;
	//for (j = 0; j < 2; j++)
	//{
	//	int k = 0;
	//	for (k = 0; k < 2; k++)
	//	{
	//		printf("%d\n", arr4[j][k]);
	//		printf("%p\n", &arr4[j][k]);//发现二位数组的数据也是连续的 每个地址都相差4 即使是上一行的末尾和下一行的开头也是连续的
	//	}//实际上可以直接用arr4[i]来引用第i行的内容 
	//	printf("\n");
	//}
//	return 0;
//}




//冒泡排序 比如arr[]={9,8,7,6,5,4,3,2,1} 要让他从小到大排序 z先取9 9比8大 所以9与8交换位置 再取到9和7 又进行交换 直到9排到最右边 
//9排完后就保持不动 重新取到最左边的8 
//所以对于有n个元素的数组 要进行sz-1次循环 其中第i次循环内还要进行sz-1-i次循环  

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
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);//仍然要注意sz不能放到函数里去算 因为传入的arr是arr的第一个元素的地址
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);//检验一下排序后的数组
//	}
//	return 0;
//}



//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//相比上面的优化部分 如果有一次没有进行任何交换 flag就会保持为1 此时数组肯定已经完成排序 所以在下面进行判断如果==1就直接跳出
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);//仍然要注意sz不能放到函数里去算 因为传入的arr是arr的第一个元素的地址
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);//检验一下排序后的数组
//	}
//	return 0;
//}




//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);//发现这两个是一样的 所以单纯的数组名就是数组首个元素的地址
//	printf("%d\n", *arr);
//
//
//	//两个例外 数组名不代表首元素地址
//	int sz = sizeof(arr) / sizeof(arr[0]);//sizeof（数组名） 计算的是整个数组的大小 单位是字节
//	printf("%p\n", &arr);//结果与printf("%p\n", arr);  和  printf("%p\n", &arr[0]);  相同 但此时代表的是整个数组的地址  
//
//
//
//	printf("%p\n", arr+1);//这样做可以看出具体的差别 前两个加一后 取到的是第二个元素的地址（相比第一个元素的地址加上了4） 
//	                         //但是第三个加上了16 arr的大小是16 所以这里整整差了一个等大小的数组
//	printf("%p\n", &arr[0]+1);
//	printf("%p\n", &arr+1);
//	return 0;
//}
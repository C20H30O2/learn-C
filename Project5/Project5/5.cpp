#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行
#include<Windows.h>
#include<stdlib.h>

//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe/n");
//		else  printf("haha/n");//这里else与最近且未被匹配的if匹配
//	return 0;//结果为什么都不打印，因为第一个if未满足，后面的都不执行
//}


//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe/n");
//	}//这样打括号使得else与第一个if相匹配
//		else  printf("haha/n");
//	
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)//必须用两个等号来判断是否相等，一个等号是赋值
//	{
//		if (b == 2)
//			printf("hehe/n");
//		else  printf("haha/n");
//	}
//	return 0;
//}



//代码1
//int main()
//{
//	if (false)
//	{
//		return 3;
//	}
//	return 2;//如果if成立就直接返回x，不返回y
//}
// 
// 
// 
//代码2
// if(condition)
//{
//	return x
//}
// else
//{return y;}//1与2等同



//判断100以内奇数并输出
//int main()
//{
//	int a = 1;
//	while (a <= 100)
//	{
//		if (a % 2 == 1)//%取模输出余数
//			printf("%d/n", a);
//		a++;
//	}
//	return 0;
//}





//switch语句
//int main()
//{
//	int day = 0;
//		scanf("%d", &day);
//		switch (day)//判断括号里的值运行相应的case，里面只能是整型
//		{
//		case 1:
//			printf("星期一/n");
//			break;//不加break就会从开始的那个case一直往下运行直到遇到break为止
//		case 2:
//			printf("星期2/n");
//			break;
//		case 3:
//			printf("星期3/n");
//			break;
//		case 4:
//			printf("星期4/n");
//			break;
//		case 5:
//			printf("星期5/n");
//			break;
//		case 6:
//			printf("星期6/n");
//			break;
//		case 7:
//			printf("星期7/n");
//			break;
//		}
//		return 0;
//
//}


//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)//判断括号里的值运行相应的case，里面只能是整型
//	{
//	case 1:
//		if (day == 1)
//			printf("工作日/n");
//	case 2:
//		switch (day)//switch可以嵌套
//		{
//		case 2:
//			printf("工作日/n");
//		}
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日/n");
//		break;
//	case 6:
//	case 7:
//		printf("休息日/n");
//		break;
//	default://应对输入值不为1-7的数的方法
//		printf("输入错误/");
//	}
//	
//	
//			return 0;
//}





//循环语句while  for   do while
//int main()
//{
//	if (1)
//		printf("hehe/n");
//
//	while(1)
//		printf("hehe/n");//死循环
//	return 0;
//}

//while(表达式)  每次执行完循环语句都要判断表达式是否为真，真则继续执行循环语句
//循环语句
//int main()
//{
//	int i = 1;
//	while (i < 10)
//	{
//		if (i == 5)
//		break;//可以这样使得整个循环提前结束，跳出whlie循环
//		printf("%d/n", i);
//		i++;
//		}
//	return 0;
//}


//int main()
//{
//	int i = 1;
//	while (i < 10)
//	{
//		if (i == 5)
//			continue;//continue使其进入死循环，i=5时因为continue，程序回到了while       达到continue时直接认为本次循环结束然后回到while处判断要不要执行下一次循环
//		printf("%d/n", i);
//		i++;//如果将i++提前到if之前，则只有5不打印出来
//	}
//	return 0;
//}


//int main()
//{
//	int ch = getchar();//从键盘输入一个字符放入ch
//	putchar(ch);//输出ch，同下面的打印一样
//	printf("%c/n", ch);
//	return 0;
//}
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)// 逻辑取反    如果输入的不是EOF（end of file——文件结束标志）则不会停止    输入ctrl+z时getchar回直接获取到一个EOF(用这种方式使这个while停止，而不是直接输入EOF,这样没用，会被读取为输入了三个字符再打出这三个字符） 
//	{
//		putchar(ch);
//	}
//	return 0;
//}







//int main()
//{
//	int ret = 0;
//	int ch = 0;
//		char password[20] = { 0 };
//	printf("请输入密码:>");
//	scanf("%s", password);//只读取空格之前的数据，
//	//getchar()           如果没有这一行输入密码最后敲的回车会被放入输入缓冲区，然后被下一个getchar读取导致直接放弃确认-------getchar之类的输入函数会先读取输入缓冲区的数据，所以这里getchar先将回车代表的字符/n读走，清空了输入缓冲区
//	while (ch = getchar() != '/n');//用这个循环清空输入缓冲区里的数据比上一行更好，更全面
//	printf("请确认(Y/N):>");
//	ret = getchar();
//	if(ret=='Y')
//	{
//		printf("确认成功/n");
//	}
//	else {
//		printf("放弃确认/n");
//	}
//	return 0;
//}





//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')
//			continue;//只打印出字符1到字符9之间的字符
//		putchar(ch);
//	}
//	return 0;
//}


//for 循环
//int main()
//{
////for(表达式1，表达式2，表达式3)123分别为初始化；判断；调整
////循环语句
//	int i = 0;//(初始化；判断；调整)
//		   for (i = 1; i <=10;i++)
//		{
//			   if (i == 5)
//				   break;// continue;这里用continue不会像whlie一样进入死循环，这里跳过后才会执行i++，也就是执行完括号内容后再进行调整部分
//			printf("%d", i);
//		}
//	return 0;
//}




//for的使用建议
//1不可在for循环内更改循环变量，防止循环失去控制，可能进入死循环
//2建议for循环的变量采用前闭后开区间的写法如(i=0,i<10,i++),可以简单地看出循环次数



//int main()
//{
//	for (;;)//for循环的初始化，调整和判断都可以省略，判断条件如果被省略则判断结果默认为 恒为真，所以这里进入死循环，所以不要随便省略
//	{
//		printf("hehe/n");
//}
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (; i < 10; i++)
//	{
//		for (; j < 10; j++)//这里省略j=0会使结果只打出10个hehe，不省略则有100个，省略会使一轮循环后j一直为10，就不再打印
//		{
//			printf("hehe\n");
//		}
//	}
//	printf("%d", j);//j的值已经变成了10
//	printf("%d", i);//都保留了循环对值的改变
//	return 0;
//}


//int main()
//{
//	int x, y;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)//包含两个变量的循环
//	{
//		printf("hehe");
//	}
//	printf("%d", y);
//	printf("%d", x);
//	return 0;
//}




	//判断下面的循环循环几次
	//int i = 0;
	//int k = 0;
	//for (i = 0, k = 0; k = 0; i++, k++)
	//	k++;
	//return 0;//答案为0次，因为在判断区域变成了给k赋值为0，判断为假，循环不进行，若赋值为一个非0的数，则死循环







	//do while循环，使用较少，该循环至少会被执行一次
	//int i = 0;
	//do
	//{
	//	//if (i == 5)
	//		//break;

	//	//if (i == 5)
	//		//continue;//do while 循环也存在break和continue的使用
	//	printf("%d/n", i);
	//	i++;
	//} while (i <= 10);//whlie条件满足时继续循环
	//return 0;



//}


	//写一个代码计算n的阶乘
//int main()
//{
//	int a=1;
//	int i=1;
//	int n;
//	//char b;
//	//int n;
//	//b = getchar();
//	//n = (int)b;
//	//printf("%d", n);
//	scanf_s("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		a *= i;
//		
//	}
//
//	printf("%d", a);
//	
//	return 0;
//
//}


//int main()
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int  d = 0;
//	for (a = 1; a <= 3; a++)
//	{
//		for (b = 1,c=1; b <= a; b++)
//			c *= b;
//		d += c;
//}
//	printf("%d", d);
//	return 0;



//	int a = 1;
//	int b = 0;
//	int c = 1;
//	for (a = 1; a <= 10; a++)
//	{
//		c *= a;
//		b += c;
//}
//	printf("%d", b);


//}




//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,8,9,10 };
//	int k = 7;  //0,1,2,3,4,5,6,7,8
//	int sz = sizeof(arr) / sizeof(arr[0]);
	////写代码查找指定的数字k

	//int i = 0;
	//for (i = 0; i < sz; i++)
	//{
	//	if (arr[i] == k)
	//	{		printf("找到了，下标是%d", i);
	//	break;
	//    }
	//}
	//if (i == sz)
	//	printf("没找到");


	//但是以上的代码效率太低 对于这种有序的数组（从小到大 从大到小）  一般采用折半查找算法 也叫二分查找算法  就是将原来的数据对半分 从其中一半开始找
	// 对于这里的数组arr 取得中间元素的下标4 发现其对应的值是5 通过有序判断要查找的7如果存在的话肯定在5的右边  再取下标4和下标8的中间下标 取得其对应的元素 ……
	//对于这种有序的数组 使用二分法查找 如果其中有2^n个元素 则最多只要查找n次 


	//int left = 0;
	//int right = sz - 1;
	//
	//while (true)//可以加入left<=right条件使得当数组中不存在要找的数时 循环会停止   但是这里使用了下面的if中的语句来判断 效果相同
	//{
	//	int mid = (right + left) / 2; //4  6  5                  
	//	printf("%d", mid);

	//	if (arr[right] < k)
	//		break;
	//	else if (arr[mid] > k)                                      
	//	{
	//		right = mid - 1;//8  5  5
	//	}
	//	else if (arr[mid] < k)
	//	{
	//		left = mid + 1;//5  5  6
	//	}

	//	
	//	else
	//	{
	//		printf("找到了，下标是%d", mid);
	//		break;
	//	}
	//	printf("%d", right);
	//	printf("%d", left);

	//}
	//if (right < left || arr[right] < k)
	//printf("找不到");
	//return 0;
//} //4 8 5 6 5 5 5 5 6



//int main()
//{
//	char arr1[] = "BangDream It's MyGO !!!!!";
//	char arr2[] = "#########################";
//	int left = 0;
//	//int right = sizeof(arr1) / sizeof(arr) - 2;     //char arr[]="abc"   实际上arr中有a b c \0 四个元素 下标分别是0 1 2 3 所以这里减去2 才是最后一个！的下标 
//	int right = strlen(arr1) - 1;//上面的求right方法不好用 所以用这种方法直接求出长度再减去一就是最后一个！对应下标
//	while (left<=right)
//	{
//
//
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//		Sleep(1000);//休眠1000毫秒 就是一秒 使得效果更佳明显 使用sleep库函数需要引入头文件#include<Windows.h>
//		system("cls");//执行系统命令的函数system（） 引入头文件#include<stdlib.h> "cls"是清空屏幕的指令 
//	}
//	return 0;
//}


//编写代码模拟用户登录 
//int main()
//{
//	int i = 0;
//	char password[20] = "";//如果不给定[]内的数值 会再在程序运行结束时报错 
//	//printf("%s\n", password);  //使用password[20]={0}结果也一样 同样是定义一个空字符
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码-》》");
//		scanf("%s", password);
//		if (strcmp(password,"123456789") == 0)//注意等于号不能拿来比较字符串是否相等 应该使用一个库函数 strcmp 头文件是#include<string.h>
//		{                                    //相等会返回0 若str1小于str2会返回负数 反之则返回正数
//			printf("登陆成功\n");
//				break;
//		}
//		else
//		{
//			printf("error\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("登陆失败\n");
//	}
//	return 0;
//}
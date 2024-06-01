#define _CRT_SECURE_NO_WARNINGS//防止scanf函数报错

#include<stdio.h>

//这里有大量的/n使用错误 如果要换行应该使用\n


//四    
//int num=20  //全局变量 定义在代码块{}之外的变量 
int main()    //上下两个num可以同时存在   打印结果默认为局部变量  建议二者不要相同，易产生bug
//{int num = 10;//局部变量 定义在代码块内部的变量 只能在局部大括号内使用
//	printf("%d/n", num);
//return 0;
//}



//三   
//	short age = 9;//申请两个字节的空间用于存储age数据
//	float num = 99.7;//同理
//	printf("%f/n", num);
//	printf("%d/n", age);




//二
//{
//	printf("%d/n", sizeof(char));//1字节=八个比特位      bit比特位  bite字节
//	printf("%d/n", sizeof(short));//2字节       1kb=1024bite    mb   gb   tb   pb
//	printf("%d/n", sizeof(int));//4       正电1   负电0  一个比特位用于存放一个二进制位
//	printf("%d/n", sizeof(long));//4
//	printf("%d/n", sizeof(long long));//8
//	printf("%d/n", sizeof(float));//4
//	printf("%d/n", sizeof(double));//8
//}



//一   //char ch = 'A';//char字符类型  
//printf("%c/n", ch);//%c打印字符格式的数据  %d打印整型十进制数据 
//return 0;

//int    long长整型    long long更长的整型    short短整型    char    float   double 
//%f 打印小数  %p以地址的形式打印  %x打印16进制数字  %o
//float单精度浮点数   double双精度浮点数



//五
//{//计算两个数的和  要输入数据——使用输入函数scanf()
	//int num1 = 3;
	//int num2 = 6;
	//scanf("%d%d", &num1, &num2); //&为取地址符号  把上面两个数据放入相应地址处
	//int sum = 0;   //c语言语法规定  定义量要在代码块的最前面 所以这这一步应该提前
//	sum = num1 + num2;
	//printf("sum=%d/n", sum);  //%d前的  sum=  为输出时的前缀

//return 0;
//}

{
	int num1 = 6;
	int num2 = 7;
	int sum = 0;
	//scanf("%d%d", &num1, &num2); //&为取地址符号  把上面两个数据放入相应地址处
	
	sum = num1 + num2;
	printf("sum=%d\n", sum);  //%d前的  sum=  为输出时的前缀

	return 0;
}






//六   变量的作用域（限定作用范围    局部变量和全局变量）和生命周期
//   extern  为声明调用不同源文件的变量---使全局变量的作用域扩大至整个工程
//全局变量的生命周期是整个程序的生命周期



//{
//	short num = 32767;//注意 short既然是申请两个字节的空间 而两个字节所能表示的最大数是32767 所以num的值如果超过了32767 会无法显示正确的数字
//	printf("%d", num);
//}
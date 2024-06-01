#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//使strlen可以运行

//int main()
//{
	//一
	//int num = 4;//const--常属性
	//printf("%d/n", num);
	//5;//字面常量
	//num = 6;
	//	printf("%d/n", num);//这里num可以反复赋值     若开始用 const int num=8----const修饰的常变量（有常属性，但依旧是变量）就不可改变
	// return 0
//}



//二#define  定义的标识符常量
//#define MAX 100  //让MAX代表100
//int main()
//{
//
//	int arr[MAX] = {1,2};//arr为创建数组 []内需为常量 代表arr内允许存储的数据个数
//	printf("%d\t", MAX);
//	printf("%d", arr[1]);
//return 0;
//}


//三   枚举常量   枚举---一一列举   比如性别可列举出男女  三原色红黄蓝   星期等
//枚举关键字---enum
//enum Sex
//{MALE,
//FAMALE,
//SECRET
//};//以上MALE 等为枚举常量
//int main()
//{ enum Sex  s =FAMALE;
//printf("%d/n", MALE);//打印出的默认值为0
//printf("%d/n", FAMALE);//1
//printf("%d/n", SECRET);//2
//printf("%d/n", s);
//return 0;
//}








//四   字符  串转义字符  注释
//字符串是由双引号引起的一串字符
//int main()
//{
//	char D =  'abc';//这样定义的char只能存储3个字符
//	"hello";
//	"";//空字符串
//	char arr1[] = "abcd";//数组  将字符串存起来
//	char arr2[] = {'a','b','cd'};
//	printf("%s", arr1);//%s打印字符串
//	printf("%s", arr2);
//	return 0;
//}


//int main()
//{
//	"abcdef";
//	"hello";
//	"";//空字符串
//	char arr1[] = "abc";//数组  将字符串存起来
//	char arr2[] = { 'a','b','c',0 };//由单引号引起表示单个字符   此处多一个0才使得arr1与arr2输出结果相同   说明arr1中不只有abc 
//	printf("%s\n", arr1);//%s打印字符串                              还有一个 /0  代表字符串的结束标志  arr2中可以加0或者'/0'
//	printf("%s", arr2);
//	return 0;
//}


//数据在计算机上存储的时候 存储的是二进制  每一个字符都有一个号  如a--97 A--65 这种存储方式叫ASCII编码  字符对应的值叫ASCII码值  可以查询ASCII码表

//{
//
//	char arr1[] = "abc";
//	char arr2[] = { 'a','b','c' };
//	printf("%d/n", strlen(arr1));//strlen---string  length  计算字符长度的函数   结果：3  隐藏的/0没有被计入
//	printf("%d/n", strlen(arr2));                                                  //  42等随机值(随机到/0后停止计算)    arr2加0后结果变为3
//	return 0;
//} 
//转义字符  转变字符原来的意思



//int main()
//{ 
//	printf("abc\n");//不同于"abc"与"abcn"    \n意为换行
//	printf("c:\test\32\test.c");//不能完整打出""内的内容因为  \t-水平制表符
//	//各种转义字符  \? 防止?被解析成三字母词     \\防止\被解析成转义序列符    printf("%c/n",''');不能打印出单引号 需要用'\''的格式  \"同理
//	printf("%c\n", '\32');  //这里的\32表示  32由八进制数转变为十进制数26 找到ASCII码值26代表的字符 并将其打印出来
//	printf("%c\n", '\x61');//十六进制转十进制后为97 对表得到97代表a  
//	printf("%c\n", '\'');
//	
//	return 0;
//}
	//    \ddd  ddd表示一到三个八进制的数字  ; \xdd    dd表示一个十六进制的数字   转义字符都数作一个字符  
	//用双斜杠屏蔽不需要的文字和代码或者以此添加注释 
	//  在C语言中还可以以/*开头*/结尾来屏蔽一段代码或文字  缺点是不能嵌套





	//五选择语句
//int main()
//{
//	int  input = 0;
//	printf("来到电子科技大学\n");
//	printf("你要好好学习吗？(在零和一中选择)");
//	scanf("%d", &input);//可以理解为将输入的值存入input中，用于之后靠input的值来判断输出内容
//	if (input == 1)
//		printf("好offer\n");
//	else
//		printf("卖红薯\n");
//		return 0;
//}




//六循环语句          while循环     for循环      do……while语句    下面为while循环
//int main()
//{
//	int line = 0;
//	printf("来到大学\n");
//	while (line < 20000)//大于等于20时跳出循环,小于时按照括号内顺序不断循环
//	{
//		printf("敲一行代码;%d\n",line);
//			line++;//为增加line代表的数量的指令
//	}
//	if(line >= 20000)
//	printf("好offer");
//
//	return 0;
//}




//七函数    分为库函数和自定义函数
//int Add(int num1, int num2)//定义add为加法函数
//{
//	int z = num1 + num2;//{}内为函数体
//	return z;
//
//}
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	int sum = 0;
//	sum = Add(num1, num2);
//	sum = Add(4, 5);
//	printf("%d/n", sum);
//	return 0;//最终打出来的是9
//	return 0;//最终打出来的是9
//}



//数组
//int main()
//{
////char ch[10] 字符组
//	//float arr[10]  浮点数组
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//[10]意思是这个数组最多存储10个元素     每个数字按照顺序下标为0开始到n-1结束
//	printf("%d/n", arr[4]);//最终打印出5，用下标的形式访问元素
//	int i = 0;//要打出所you数字可以用循环语句
//		while(i<10)
//{
//			printf("%d/n", arr[i]);
//			i++;
//	}
//	return 0;
//}





//操作符
//算数操作符+ - * / %--取余数如3%2为1
//移位操作符>>  <<  输出将数字的二进制位整体向左或向右移动后的值
//位操作符&按位与               |按位或           ^按位异或            (都按二进制位)
// 赋值操作符=   +=     -=      &=       *=      ^=       |=    <<=    >>=           
//按操作数的数量分为单目操作符  双目操作符 三目操作符
//单目操作符！逻辑反操作  ！1=0     ！0=1
//-负值  +正值
//&取地址符
//sizeof求大小
//~对一个数的二进制取反  0变1   1变0     int a=0  (int为32个比特位所以实际上   a=00000000000000000000000000000000  ~a=1111……111    但是~a输出的值为-1  原因涉及到原码 反码 补码
//--     ++      前置后置    a=10    b=a++=11（后置加加）  b=++a=11 这一步之后a变为11（因为前置加加）
//*间接访问操作符
// (类型)   强制类型转换  int a=(int)3.14    3.14是double不是整型，前面加（int）使其转化为整型再输出  
// 关系操作符  <  >        <=    >=    !=用于测试不相等    ==用于测试相等
// 逻辑操作符   &&逻辑与  a=2 b=3 c=a&&b=1(&&两边都不为0，则c为真 输出1)        
//        ||逻辑或
// 
// 
// 
// 
// 
// 
// 
//int main()
//{
//	int a = 10;
//	int arr1[] = { 1,2,3,4,5,6 };
//	printf("%d/n", sizeof(a));
//	printf("%d/n", sizeof(int));
//		printf("%d/n", sizeof a);
//		//printf("%d/n", sizeof int)无法正常输出大小
//		printf("%d/n", sizeof(arr1));//计算数组大小
//		printf("%d/n", sizeof(arr1) / sizeof(arr1[0]));//计算数组中数据个数
//		return 0;
//}








//条件操作符
//exp 1?exp 2:exp 3  int a=10 int b=20   int max=0   max=(a>b?a:b)  a如果大于b则将a值赋给max 否则将b值赋给max
//逗号表达式exp1，exp2，exp3
//

//原码     反码（源码取反，0变1，1变0，符号位不变）     补码（反码加一得到）     100000000000000000000000000000001=-1（最左边一位是符号位0为正，1为负数）
//负数要转为补码储存，正数的储存中源码等于反码等于补码

//常见关键字
//auto   break    case      char      const      continue      default     do     double       else     enum     extern(声明引用不同源文件中的全局变量或函数)     float   for    int    long 
//register       register  int a=10    将a变量储存到寄存器中  需要时可以快速提取数据      struct   switch   union  while  等关键字
//变量名跟关键字不能冲突
//typedef    类型定义  类型重定义     typedef unsigned int=u int    将unsigned int 取一个别名为u int代替 效果一样
//void
//void test()
//{
//	static int a = 1;//加了static后使局部变量a变为静态变量，使其生命周期变长，修饰全局变量时使其不可在不同源文件中被引用，也可以修饰函数同样使其不能被跨源文件引用（改变了变量的作用域，或改变函数的外部连接属性为内部连接属性）
//	a++;
//	printf("a=%d", a);
//}
//int main()
//{
//
//	int i = 0;
//	while (i< 5)
//	{
//		test();
//		i++;
//	}
//	return 0;
//}//无static时输出结果为五个a=2，加上后为23456，a++的效果累计了
//f10加ctrl进入调试   再就可以打开监视窗口 输入要监视的变量
    













//#define 定义常量和宏
//#define max=100//定义标识符常量
//#define MAX(x,y) (x>y?x:y)//用宏的方式取代函数求较大值
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = 0;
//	max= MAX(a, b);
//	printf("Max=%d/n", max);
//}
    






//指针
//如何产生地址      32位（32根地址线/数据线 分别通正电负电  )  产生2^32个地址  一个地址给一个字节的内存，共4个gb内存  
//    64位
int main()
//{
//	int a = 10;//申请四个字节
//int*p=&a;//取出a的地址   用p存a的地址 p为一种变量，int*为一种类型  有一种变量是用来储存地址的——指针变量   指针的大小 在32位中是四个字节，64位则是8     
//	printf("%p\n", &a);//直接打印出a变量的地址
//	printf("%p\n", p);//结果相同
//	*p=20;//*-解引用操作符或者叫间接访问操作符      找到a的地址把a改成20
//	printf("%d\n", a);//结果变为20
//	return 0;//
//}

//{
//	char ch = 'w';
//	char* pc = &ch;
//	*pc = 'a';
//	printf("%c\n", ch);
//	printf("%d\n", sizeof(pc));
//	return 0;
//}

//{
//	double d = 3.14;
//	double* pd = &d;
//	*pd = 5.23;
//	printf("%lf/n", d);
//	printf("%lf/n", *pd);
//	return 0;
//}       


//结构体--描述一种复杂对象时自己创造出的一种类型  比如书和人
//struct  结构体关键字
#include <string.h>//下面的strcpy为库函数，使用时要引用头文件
//创建一个结构体类型
struct book
{
	char name[20];
		short price;
};
int main()
{//利用结构体类型创建一个该类型的结构体变量
	struct book b1 = { "ni  hao",55 };
	printf("书名:%s/n", b1.name);//结构体变量.成员
	printf("价格:%d/n", b1.price);
	b1.price= 50;
	//b1.name=……(name不能这样修改，因为name本质上是数组名，而price是变量)
	//strcpy(b1.name,"C++");//string copy-字符串拷贝-库函数  要这样修改name
	printf("修改后的价格:%d/n", b1.price);
	struct book* pb1 = &b1;//用指针打出书名和价格
	printf("%s/n", (*pb1).name);
	printf("%d/n", pb1->price);//用箭头的形式   更加简便
	printf("%s/n", pb1->name);//结构体指针->成员
}





//C语言是一种结构化的程序设计语言
//1顺序结构
//2选择结构
//3循环结构

//分支语句if switch                                     
//int main()
//{
//	int a = 1;//一个分号一个语句
//	;//空语句
	//int age = 10;
	//if (age < 18)//()里放表达式
	//	printf("未成年/n");
	//else 
	//	printf("成年/n");





	//int age = 10;
	//if (age < 18)//()里放表达式
	//	printf("未成年/n");
	//else if(age>=18&&age<28)//18<=age<28的写法是错的，会使得结果为青年
	//	printf("青年/n");
	//else if (age >= 28 && age < 50)
	//	printf("壮年/n");
	//else if (age>50)
	//	/*printf("中老年/n");*/


//	int age = 10;
//	if (age < 18)//()里放表达式
//		{printf("未成年/n");
// 	   printf("不能谈恋爱");}//有多条要执行的语句时要放入一个代码块
//	else {
//		if (age >= 18 && age < 28)//18<=age<28的写法是错的，会使得结果为青年
//			printf("青年/n");
//		else if (age >= 28 && age < 50)
//			printf("壮年/n");
//		else if (age > 50)
//			printf("中老年/n");
//	}//效果同上
//	return 0;
//}





	//0表示假,非0表示真

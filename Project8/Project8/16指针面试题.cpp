#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
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
////�����p��һ���ṹ��ָ��  ����p��ֵ��0x100000  ���±��ʽ�Ľ����ʲô  ��֪�ṹ��test���͵ı�����С��32���ֽ�
//
//int main()
//{
//	printf("%d\n", sizeof(struct test));
//	p = (struct test*)0x100000;//0x1 ��ʮ�����Ʊ�ʾ�� ת����ʮ���ƾ���1
//	printf("%p\n", p + 0x1);//��Ϊp�ǽṹ��ָ�� ���ṹ��Ĵ�С��32���ֽ� ���Լ���һ�� ����0x100020  ��0x20����ʮ���ƵĶ�ʮ
//	printf("%p\n", (unsigned long)p + 0x1);//p�ȱ�ת������unsigned int ���� �ټ�һ �൱��1*16**5+1 ��ʮ������Ϊ0x100001 �����Ե�ַ��ʽ��ӡ�������ʮ������ ��0x100001
//	printf("%p\n", (unsigned int *)p + 0x1);//p��ת������unsigned int * ��һ�������ĸ��ֽ� ���Խ����0x100004
//	return 0;
//}




//int main()
//{
//	int a[4] = { 1,2,3,4 };//��С�˴洢�� a�ڵ����ݴ洢Ϊ |01 00 00 00 |02 00 00 00 |03 00 00 00 |04 00 00 00|
//	int* ptr1 = (int*)(&a + 1);//&aȡ��������������ĵ�ַ ��һ��������������Ĵ�С���ֽ���  
//	int* ptr2 = (int*)((int)a + 1);//�Ƚ�aת��Ϊint ��һ����ת��Ϊint*���� �൱�ڰ�������Ԫ�صĵ�ַa����ƶ�һ���ֽ� ������ָ��01 ��Ϊָ��00
//	printf("%x,%x", ptr1[-1], *ptr2);//��ptr2������ ���00����ȡ�ĸ��ֽ� ����ȡ��00 00 00 02 ת��Ϊ16����Ϊ02000000 ʮ����Ϊ2*16**6
//	//����������Ԫ�صķ���arr[n] ȥ���ptr1[-1]  ptr1[-1]=*(ptr1-1)  ���Զ�ȡ��04 00 00 00  ʮ����Ϊ4
//	return 0;
//}




//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };//ע�⣺������ʹ�õ���С���� ����Ӧ�ý�����Ϊ���ű��ʽ ���������һ�����ʽ��ֵ
//	//����ʵ����a�д洢����{1,3,5},����λ��ϵͳ�Ჹ��0
//
//	int* p;
//	p = a[0];//����pȡ������1�ĵ�ַ
//	printf("%d\n", p[0]);//p[0]=*(p+0) ��1
//	return 0;
//}




//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;//����vs�Ѿ���֧��������ֵ 
//	printf("%p,%d\n", &p{ 4][2] - &a[4][2],& p[4][2] - &a[4][2] });
//	return 0;
//}



//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);//&aa+1����������aa���� ת��Ϊint*���ͺ� �Ӽ�1ֻ����һ������ ��4���ֽ� ����ptr1 - 1ָ��10 
//	int* ptr2 = (int*)(*(aa + 1));//aa��aa��Ԫ�صĵ�ַ ������aa[0]={1,2,3,4,5}�ĵ�ַ ��һ������aa�ĵڶ���Ԫ�� aa[1]={6,7,8,9,10} ����ptr2�õ��ĵ�ַָ��6 ��ǰ��һ���ֽں�ָ��5
//
//
//	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));//10��5
//	return 0;
//}




//int main()
//{//�����Ŀԭ��������const  �������ڰ汾��vs����const�Ͳ��ܸ�ֵ 
//	const char* a[] = { "work" ,"at","alibaba" };
//	//��"work"�����ģ�������Ϊconst char[5], ����a�д�ŵ�Ԫ����const char*���� ���Դ������ÿ���ַ�����Ԫ�صĵ�ַ
//
//	const char* pstr = "abc";//�������ĸ�ֵ���Ὣstr����Ԫ�صĵ�ַ����ָ�����  
//
//	const char** pa = a;//pa�õ���a����Ԫ�ء�����w���ĵ�ַ  �ĵ�ַ
//	pa++;//pa�����a�ĵڶ���Ԫ�ء�a���ĵ�ַ �ĵ�ַ 
//	printf("%s\n", *pa);//pa�����þ���a�ĵ�ַ ��a�ĵ�ַ��ӡ��at����
//	return 0;
//}



//д����̫�鷳��  ��ϰʱ���н������by 2024 6 5 myself
//int main()
//{
//	const char* c[] = { "enter","new","point","first" };
//	const char** cp[] = { c + 3,c + 2,c + 1,c };
//	const char*** cpp = cp;
//
//	printf("%s\n", **++cpp);//ע�� ++cpp�Ľ���ᱻ���� ��cpp=cpp+1
//	printf("%s\n", *--*++cpp+3);
//	printf("%s\n", *cpp[-2]+3);//*(*(cpp-2))+3
//	printf("%s\n", cpp[-1][-1]+1);  //*(*(cpp-1)-1)+1     
//
//	return 0;
//}





//����ָ��ʵ�������ַ���

#include<assert.h>
//void reverse(char* str)
//{
//	assert(str);//ȷ��str��Ϊ��
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;//ͬʱȡ���ַ����������ߵ��ַ��ĵ�ַ �����н��� 
//	while (left < right)//�������� 
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
//	//scanf("%s", arr);//�����������ݴ��ڿո� scanfֻ���ȡ�ո�֮ǰ������ 
//	gets_s(arr);//���Զ�ȡһ���е�����
//	reverse(arr);
//	return 0;
//}






//�ж�һ�����Ƿ�Ϊˮ�ɻ�������������
#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100000; i++)//����ֱ�Ӽ����100000���ڵ�����������
//	{
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp /= 10)//ʹ�����ַ�ʽ�ж�i�Ǹ���λ��  ��tmp��ɸ�λ����ʱ�� tmp/=10 ����0
//		{
//			n++;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);//pow ������ĳ������n�η� ����math.hͷ�ļ�
//			tmp /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//}





//��ӡָ���ַ����е�����ͼ��
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);//����Ҫ��ӡ������ͼ�����ϰ벿�ֵ�����
//	int i = 0;
//	for (i = 0; i < line; i++)//��ӡ�ϰ벿��
//	{
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)//����ʲôʱ���ӡ�ո� ʲôʱ���ӡ* ֻҪ�۲�ͼ���пո��*�������Ĺ�ϵ����֪��
//		{
//			printf(" ");//��ӡ�ո�
//		}
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0; i < line - 1; i++)//��ӡ�°벿��
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
//	const int* pp;//p��pp��ͬ const���� ʹ��ָ��ָ���Ԫ�ز��ܱ��ı�
//	int* const ppp=&a;//�����const���� ʹ��ppp���ܱ��ı�  ����ָ���Ԫ���ܱ��޸�
//	const int* const pppp = &a;//�����ܱ��޸�
//
//	*ppp = 20;
//	printf("%d\n", a);
//	return 0;
//}



//����������������ż����˳��  ������ȫ������ǰ�� ż�����ں���

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






#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>

//�������
//(*(void(*)())0)()  ��ʾ��0ǿ������ת��Ϊvoid(*)()  ��void(*)()���������Ǻ���ָ������  �����ܶ� void(*)())0���н����� ʹ����ָ��ĺ���

//void (*signal(int,void(*)(int)))(int)  
//���Կ���(int,void(*)(int))�Ǻ����Ĳ��� ��signal���Կ���������
//ע�� ���� int ADD(int,int)  ȥ���������ʹ��������ʣ�µľ��Ƿ�������int   
// �����ж�����void (*)(int) ���Ǻ����ķ�������
//Ҫע�� �� int ADD(int,int) ������д���Ǻ������� ��֮ǰ����������ɨ������������Ӧ��ͷ�ļ���Ҳ���й����������� 
//��������Ҳ���ڽ��к��������� 


//��Ҫע�� void(*)(int) signal(int,void(*)(int)) ���������������Ǵ���� 
//���Ҫ��signal(int,void(*)(int)) ����void(*)(int)���� ��ô*��ȻҪ���������� ����д��void (*signal(int,void(*)(int)))(int)

void(             *signal(int, void (*)(int))                )(int);
//�п��������򵥵�д��   ��Ҫ����typedef���м� 
typedef unsigned int uint;//��unsigned int������������Ϊuint 
typedef void(* pfun_t)(int);//��������������Ϊpfun_t    ע������ﲻ��д��typedef void(* )(int) pfun_t  ��ȻҪ��*��������

pfun_t signal(int, void (*)(int));//��������֮��Ϳ�������д��



//����ָ�� ����
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
//	printf("%d\n", (***p)(2, 3));//��������ͬ  ˵�������*û���ô� û��Ч��
//	printf("%d\n", p(2, 3));//��������дҲ��
//	printf("%d\n", ADD(2, 3));//��֮���ADD���������Ϊһ����ַ �Ϳ����������һ�е�д��
//
//	return 0;
//}




//����ָ������  ��һ������ �洢�Ķ��Ǻ���ָ��
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
//	int (*p)(int, int) = ADD;//p��ֻ�ܴ洢һ����ַ
//	//��ʱ��Ҫһ������ ȥ�洢�ĸ������ĵ�ַ
//	int (*p_func[4])(int, int) = { ADD,SUB,MUL,DIV };//�����һ������ָ������� Ҫע��int (*) (int,int) p_func[4] ����д���Ǵ����
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", p_func[i](4, 2));
//	}
//
//	return 0;
//}




//����
char* my_strcpy(char* dest, const char* src);
//дһ������ָ��Ϊ��char* (*p) (char* dest,char* src)=my_strcpy;
//дһ������ָ������Ϊ��char* (*p[1]) (char* dest,char* src)={my_strcpy};




//����ָ�������ʹ��


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
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("����������������");
//			scanf("%d%d", &x, & y);
//			printf("%d\n", ADD(x, y));
//			break;
//		case 2:
//			printf("����������������");
//			scanf("%d%d", &x, & y);
//			printf("%d\n", SUB(x, y));
//			break;		
//		case 3:
//			printf("����������������");
//			scanf("%d%d", &x, & y);
//			printf("%d\n", MUL(x, y));
//			break;	
//		case 4:
//			printf("����������������");
//			scanf("%d%d", &x, & y);
//			printf("%d\n", DIV(x, y));
//			break;
//		case 0:
//			break;
//		default:
//			printf("�����������������");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//���Ը��ܵ������ַ�����дһ�����׵ļ��������鷳��ͨ��ʹ�ú���ָ��������Լ򻯲���



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
//	printf("����������������");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}//ת�Ʊ�
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��");
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
//			printf("�������");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//���ϻ��漰���ص����������� �ص�������һ��ͨ������ָ����õĺ����� ������һ��������ָ����Ϊ����������һ��������
// �����ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص�����





//����ת�Ʊ��������� дһ���ܸ������͵����������ð������
//֮ǰд��ð������ֻ���������������� 
//���Գ����˽�⺯���е�qsort�������ó�������� ֻҪ�ܱȽϴ�С������qsort��������Ϊ������


//ԭð������
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
//int cmp_int(const void* e1, const void* e2)//Ϊqsort��������Ƚ��������͵ķ���
//{                                          //qsort��������ݸú����ķ���ֵ���ж����Ƚϵ�����Ԫ�صĴ�С 
//	                                       //����0������� ����<0����e2>e1  ����>0 ����e1>e2     
//	return *(int*)e1 - *(int*)e2;          //Ȼ��qsort��������ݵõ��Ĵ�С��ϵ�����Ƚϵ�����Ԫ���Ƿ񽻻�˳�� �Զ���������
//}
//
//
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz);//ֻ������������������
//
//	struct stu s[3] = { {"a",10},{"b",20},{"c",30} };
//	float f[] = { 9.0,8.0,7.0 };
//	//qsort-- quick sort  ��������
//	//void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*));//�鿴���ĺ�����Ϣ�ĵ�������
//	
//	//�����漰��void*���͵�ָ��
//	int a = 10;
//	void* p = &a;
//	//*p //����void*���͵�ָ����Խ����������͵ĵ�ַ
//	     //���ǲ��ܽ��н����ò��� 
//     //p+=1
//		 //Ҳ���ܽ��мӼ�����
//	*(int*)p = 20;
//	printf("%d\n",a);//���Գɹ��ı�a��ֵ��˵��ʹ��void*���͵�ָ��ʱҪ����ǿ������ת��
//
//
//
//
//	//�������qsort�����Ĳ��� �ǵ�����ͷ�ļ�stdlib.h
//	//�������ʹ�þ���
//	//qsort(arr,sz,sizeof(arr[0],) ǰ���������ֱ�ΪҪ��������飬����Ĵ�С����������һ��Ԫ�صĴ�С
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);//���ĸ�����Ϊint (*compar)(const void*, const void*)���� �����Ǵ��������Զ��������ķ��� 
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;//����ʹ��qsort����ɹ� �����ע�͵�bubble_sort������ܻ��д��󣬲�֪������Ϊʲô
//}




//����ģ��qsortдһ������ʵ�ֲ�ͬ�������������  �Լ������

//struct stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_int(const void* e1, const void* e2)//Ϊ���Ͷ��ƵıȽϷ���
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//
//
//int cmp_float(const void* e1, const void* e2)//�Ƚ�float���͵ķ���ֵǧ������Ƚ�intһ��
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
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);//�Ƚ��ַ���Ҫʹ��strcmp���� ֮����ٽ��ַ����������
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
//void swap(char* buf1,char*buf2,int width)//�Զ���Ľ�������  �������Ҫ����������Ԫ�صĵ�ַ width��ÿ��Ԫ�صĳ��� ���ｻ����ԭ���ǽ�����Ԫ��ÿ���ֽڶ��໥���� ֱ��������width���ֽڣ���ʱ������Ԫ�ر���ȫ����
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;//����Ԫ��1��ĳ���ֽ�
//		*buf1 = *buf2;//��Ԫ��2�Ķ�Ӧ�ֽڸ���Ԫ��1
//		*buf2 = tmp;//�������µ�Ԫ��1�Ķ�Ӧ�ֽڸ���Ԫ��2
//		buf1++;
//		buf2++;//��������ַ��������һ���ֽ� ׼����һ���ֽڵĽ���
//	}
//}
//
//void my_sort(void* base,int sz,int width,int (*cmp)(const void*e1,const void*e2))
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)//�Ƚϵ�����
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1; j++)//ÿһ�˱ȽϵĴ���
//		{       //�Զ���ȽϺ���                                                                //����֪��width�������ÿ��Ԫ����ռ���ֽ��� 
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)// base���������һ��Ԫ�صĵ�ַ ���õ�ַǿ��ת��Ϊchar*���� ����϶��پ�ǰ�����ٸ��ֽ� �������ɱ���width���ܵõ�����������Ԫ�صĵ�ַ �������ܽ���ͬԪ�صĵ�ַ����ȽϺ����н��бȽ�
//			{
//               //���������������Ҫ���н���λ��  �Զ��彻������  
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
//	//test_for_int();//ִ��my_sort������������������Ĳ���
//	test_for_float();
//	test_for_struct();//�������������ڼ����в鿴
//	//test_for_age �Ͳ�����ʾ��
//	return 0;
//}
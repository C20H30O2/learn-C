#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>//ʹstrlen��������
#include<Windows.h>
#include<stdlib.h>

//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe/n");
//		else  printf("haha/n");//����else�������δ��ƥ���ifƥ��
//	return 0;//���Ϊʲô������ӡ����Ϊ��һ��ifδ���㣬����Ķ���ִ��
//}


//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe/n");
//	}//����������ʹ��else���һ��if��ƥ��
//		else  printf("haha/n");
//	
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)//�����������Ⱥ����ж��Ƿ���ȣ�һ���Ⱥ��Ǹ�ֵ
//	{
//		if (b == 2)
//			printf("hehe/n");
//		else  printf("haha/n");
//	}
//	return 0;
//}



//����1
//int main()
//{
//	if (false)
//	{
//		return 3;
//	}
//	return 2;//���if������ֱ�ӷ���x��������y
//}
// 
// 
// 
//����2
// if(condition)
//{
//	return x
//}
// else
//{return y;}//1��2��ͬ



//�ж�100�������������
//int main()
//{
//	int a = 1;
//	while (a <= 100)
//	{
//		if (a % 2 == 1)//%ȡģ�������
//			printf("%d/n", a);
//		a++;
//	}
//	return 0;
//}





//switch���
//int main()
//{
//	int day = 0;
//		scanf("%d", &day);
//		switch (day)//�ж��������ֵ������Ӧ��case������ֻ��������
//		{
//		case 1:
//			printf("����һ/n");
//			break;//����break�ͻ�ӿ�ʼ���Ǹ�caseһֱ��������ֱ������breakΪֹ
//		case 2:
//			printf("����2/n");
//			break;
//		case 3:
//			printf("����3/n");
//			break;
//		case 4:
//			printf("����4/n");
//			break;
//		case 5:
//			printf("����5/n");
//			break;
//		case 6:
//			printf("����6/n");
//			break;
//		case 7:
//			printf("����7/n");
//			break;
//		}
//		return 0;
//
//}


//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)//�ж��������ֵ������Ӧ��case������ֻ��������
//	{
//	case 1:
//		if (day == 1)
//			printf("������/n");
//	case 2:
//		switch (day)//switch����Ƕ��
//		{
//		case 2:
//			printf("������/n");
//		}
//	case 3:
//	case 4:
//	case 5:
//		printf("������/n");
//		break;
//	case 6:
//	case 7:
//		printf("��Ϣ��/n");
//		break;
//	default://Ӧ������ֵ��Ϊ1-7�����ķ���
//		printf("�������/");
//	}
//	
//	
//			return 0;
//}





//ѭ�����while  for   do while
//int main()
//{
//	if (1)
//		printf("hehe/n");
//
//	while(1)
//		printf("hehe/n");//��ѭ��
//	return 0;
//}

//while(���ʽ)  ÿ��ִ����ѭ����䶼Ҫ�жϱ��ʽ�Ƿ�Ϊ�棬�������ִ��ѭ�����
//ѭ�����
//int main()
//{
//	int i = 1;
//	while (i < 10)
//	{
//		if (i == 5)
//		break;//��������ʹ������ѭ����ǰ����������whlieѭ��
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
//			continue;//continueʹ�������ѭ����i=5ʱ��Ϊcontinue������ص���while       �ﵽcontinueʱֱ����Ϊ����ѭ������Ȼ��ص�while���ж�Ҫ��Ҫִ����һ��ѭ��
//		printf("%d/n", i);
//		i++;//�����i++��ǰ��if֮ǰ����ֻ��5����ӡ����
//	}
//	return 0;
//}


//int main()
//{
//	int ch = getchar();//�Ӽ�������һ���ַ�����ch
//	putchar(ch);//���ch��ͬ����Ĵ�ӡһ��
//	printf("%c/n", ch);
//	return 0;
//}
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)// �߼�ȡ��    �������Ĳ���EOF��end of file�����ļ�������־���򲻻�ֹͣ    ����ctrl+zʱgetchar��ֱ�ӻ�ȡ��һ��EOF(�����ַ�ʽʹ���whileֹͣ��������ֱ������EOF,����û�ã��ᱻ��ȡΪ�����������ַ��ٴ���������ַ��� 
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
//	printf("����������:>");
//	scanf("%s", password);//ֻ��ȡ�ո�֮ǰ�����ݣ�
//	//getchar()           ���û����һ��������������õĻس��ᱻ�������뻺������Ȼ����һ��getchar��ȡ����ֱ�ӷ���ȷ��-------getchar֮������뺯�����ȶ�ȡ���뻺���������ݣ���������getchar�Ƚ��س�������ַ�/n���ߣ���������뻺����
//	while (ch = getchar() != '/n');//�����ѭ��������뻺����������ݱ���һ�и��ã���ȫ��
//	printf("��ȷ��(Y/N):>");
//	ret = getchar();
//	if(ret=='Y')
//	{
//		printf("ȷ�ϳɹ�/n");
//	}
//	else {
//		printf("����ȷ��/n");
//	}
//	return 0;
//}





//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')
//			continue;//ֻ��ӡ���ַ�1���ַ�9֮����ַ�
//		putchar(ch);
//	}
//	return 0;
//}


//for ѭ��
//int main()
//{
////for(���ʽ1�����ʽ2�����ʽ3)123�ֱ�Ϊ��ʼ�����жϣ�����
////ѭ�����
//	int i = 0;//(��ʼ�����жϣ�����)
//		   for (i = 1; i <=10;i++)
//		{
//			   if (i == 5)
//				   break;// continue;������continue������whlieһ��������ѭ��������������Ż�ִ��i++��Ҳ����ִ�����������ݺ��ٽ��е�������
//			printf("%d", i);
//		}
//	return 0;
//}




//for��ʹ�ý���
//1������forѭ���ڸ���ѭ����������ֹѭ��ʧȥ���ƣ����ܽ�����ѭ��
//2����forѭ���ı�������ǰ�պ������д����(i=0,i<10,i++),���Լ򵥵ؿ���ѭ������



//int main()
//{
//	for (;;)//forѭ���ĳ�ʼ�����������ж϶�����ʡ�ԣ��ж����������ʡ�����жϽ��Ĭ��Ϊ ��Ϊ�棬�������������ѭ�������Բ�Ҫ���ʡ��
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
//		for (; j < 10; j++)//����ʡ��j=0��ʹ���ֻ���10��hehe����ʡ������100����ʡ�Ի�ʹһ��ѭ����jһֱΪ10���Ͳ��ٴ�ӡ
//		{
//			printf("hehe\n");
//		}
//	}
//	printf("%d", j);//j��ֵ�Ѿ������10
//	printf("%d", i);//��������ѭ����ֵ�ĸı�
//	return 0;
//}


//int main()
//{
//	int x, y;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)//��������������ѭ��
//	{
//		printf("hehe");
//	}
//	printf("%d", y);
//	printf("%d", x);
//	return 0;
//}




	//�ж������ѭ��ѭ������
	//int i = 0;
	//int k = 0;
	//for (i = 0, k = 0; k = 0; i++, k++)
	//	k++;
	//return 0;//��Ϊ0�Σ���Ϊ���ж��������˸�k��ֵΪ0���ж�Ϊ�٣�ѭ�������У�����ֵΪһ����0����������ѭ��







	//do whileѭ����ʹ�ý��٣���ѭ�����ٻᱻִ��һ��
	//int i = 0;
	//do
	//{
	//	//if (i == 5)
	//		//break;

	//	//if (i == 5)
	//		//continue;//do while ѭ��Ҳ����break��continue��ʹ��
	//	printf("%d/n", i);
	//	i++;
	//} while (i <= 10);//whlie��������ʱ����ѭ��
	//return 0;



//}


	//дһ���������n�Ľ׳�
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
	////д�������ָ��������k

	//int i = 0;
	//for (i = 0; i < sz; i++)
	//{
	//	if (arr[i] == k)
	//	{		printf("�ҵ��ˣ��±���%d", i);
	//	break;
	//    }
	//}
	//if (i == sz)
	//	printf("û�ҵ�");


	//�������ϵĴ���Ч��̫�� ����������������飨��С���� �Ӵ�С��  һ������۰�����㷨 Ҳ�ж��ֲ����㷨  ���ǽ�ԭ�������ݶ԰�� ������һ�뿪ʼ��
	// �������������arr ȡ���м�Ԫ�ص��±�4 �������Ӧ��ֵ��5 ͨ�������ж�Ҫ���ҵ�7������ڵĻ��϶���5���ұ�  ��ȡ�±�4���±�8���м��±� ȡ�����Ӧ��Ԫ�� ����
	//����������������� ʹ�ö��ַ����� ���������2^n��Ԫ�� �����ֻҪ����n�� 


	//int left = 0;
	//int right = sz - 1;
	//
	//while (true)//���Լ���left<=right����ʹ�õ������в�����Ҫ�ҵ���ʱ ѭ����ֹͣ   ��������ʹ���������if�е�������ж� Ч����ͬ
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
	//		printf("�ҵ��ˣ��±���%d", mid);
	//		break;
	//	}
	//	printf("%d", right);
	//	printf("%d", left);

	//}
	//if (right < left || arr[right] < k)
	//printf("�Ҳ���");
	//return 0;
//} //4 8 5 6 5 5 5 5 6



//int main()
//{
//	char arr1[] = "BangDream It's MyGO !!!!!";
//	char arr2[] = "#########################";
//	int left = 0;
//	//int right = sizeof(arr1) / sizeof(arr) - 2;     //char arr[]="abc"   ʵ����arr����a b c \0 �ĸ�Ԫ�� �±�ֱ���0 1 2 3 ���������ȥ2 �������һ�������±� 
//	int right = strlen(arr1) - 1;//�������right���������� ���������ַ���ֱ����������ټ�ȥһ�������һ������Ӧ�±�
//	while (left<=right)
//	{
//
//
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//		Sleep(1000);//����1000���� ����һ�� ʹ��Ч���������� ʹ��sleep�⺯����Ҫ����ͷ�ļ�#include<Windows.h>
//		system("cls");//ִ��ϵͳ����ĺ���system���� ����ͷ�ļ�#include<stdlib.h> "cls"�������Ļ��ָ�� 
//	}
//	return 0;
//}


//��д����ģ���û���¼ 
//int main()
//{
//	int i = 0;
//	char password[20] = "";//���������[]�ڵ���ֵ �����ڳ������н���ʱ���� 
//	//printf("%s\n", password);  //ʹ��password[20]={0}���Ҳһ�� ͬ���Ƕ���һ�����ַ�
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������-����");
//		scanf("%s", password);
//		if (strcmp(password,"123456789") == 0)//ע����ںŲ��������Ƚ��ַ����Ƿ���� Ӧ��ʹ��һ���⺯�� strcmp ͷ�ļ���#include<string.h>
//		{                                    //��Ȼ᷵��0 ��str1С��str2�᷵�ظ��� ��֮�򷵻�����
//			printf("��½�ɹ�\n");
//				break;
//		}
//		else
//		{
//			printf("error\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("��½ʧ��\n");
//	}
//	return 0;
//}
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//
//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//void Left_Rem(char arr[], int n )
//{
//	char*p = arr;
//	char temp;
//	while (n--)
//	{
//		temp = *arr;
//		p = arr; 
//		while (*(p + 1) != '\0')
//		{
//			//ÿ���ַ�����Ų��һ��λ��
//			*p = *(p + 1);
//			p++;
//		}
//		*p = temp;
//	}
//}
//int main()
//{
//	int n = 0;
//	printf("���������������ַ�����\n");
//	scanf("%d", &n);
//	char arr[1024] = "ABCD";
//	Left_Rem(arr, n);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

//�ַ�����ת
void reverse(char* start, char* end) 
{
	while (start < end)
	{

		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
//������ת��
void Left_Rem2(char arr[], int n)
{
	int len = strlen(arr);
	char*str = arr;
	reverse(str, str + n - 1);    //��תǰn���ַ�
	reverse(str + n, str + len - 1); //��תʣ�µ��ַ�
	reverse(str, str + len - 1);   ////������תһ��
}
int Is_rorate(char* dest, char* src)              //�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
{
	int k = strlen(src);
	if (strlen(dest) != strlen(src))
	{
		return 0;
	}
	if (!strcmp(dest, src))
	{
		return 1;
	}
	k--;
	while (k--)
	{
		Left_Rem2(dest, 1);
		if (!strcmp(dest,src))
		{
			return 1;
		}
	}
	return 0;
}
//������������len-k��
int main()
{
	int n = 0;
	//printf("���������������ַ�����\n");
	//scanf("%d", &n);
	char dest[1024] = "ABCD";
	char src[1024] = "CDAB";
	int i = 0;
	i = Is_rorate(dest, src);
	printf("%d\n",i);
	system("pause");
	return 0;
}
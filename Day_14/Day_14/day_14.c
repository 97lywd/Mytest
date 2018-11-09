//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
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
//			//每个字符向左挪动一个位置
//			*p = *(p + 1);
//			p++;
//		}
//		*p = temp;
//	}
//}
//int main()
//{
//	int n = 0;
//	printf("请输入想左旋的字符数：\n");
//	scanf("%d", &n);
//	char arr[1024] = "ABCD";
//	Left_Rem(arr, n);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}

//字符串逆转
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
//三次旋转法
void Left_Rem2(char arr[], int n)
{
	int len = strlen(arr);
	char*str = arr;
	reverse(str, str + n - 1);    //旋转前n个字符
	reverse(str + n, str + len - 1); //旋转剩下的字符
	reverse(str, str + len - 1);   ////整体旋转一次
}
int Is_rorate(char* dest, char* src)              //判断一个字符串是否为另外一个字符串旋转之后的字符串。
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
//右旋等于左旋len-k次
int main()
{
	int n = 0;
	//printf("请输入想左旋的字符数：\n");
	//scanf("%d", &n);
	char dest[1024] = "ABCD";
	char src[1024] = "CDAB";
	int i = 0;
	i = Is_rorate(dest, src);
	printf("%d\n",i);
	system("pause");
	return 0;
}
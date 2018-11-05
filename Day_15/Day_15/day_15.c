
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//
// 一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个数字，编程实现。
//
//int main()
//{
//	int arr[] = { 1,2,3,3,4,7,5,5,4,7};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int a[10000] = { 0 };
//	for (int i = 0; i < len; i++) {
//		a[arr[i]]++;
//	}
//	for (int i = 0; i < len; i++) {
//		if (a[arr[i]] == 1)
//			printf("%d\n",arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水.
//给20元，可以多少汽水。
//编程实现。
//
//int main()
//{
//	int n = 20;
//	int k = 0;
//	while (n)
//	{
//		k++;
//		n--;
//		if (k % 2 == 0)
//		{
//			n++;
//		}
//	}
//	printf("%d\n", k);
//	system("pause");
//	return 0;
//}

//3.模拟实现strcpy

//void My_strcpy(char*dest, const char* str)
//{
//	assert(dest);
//	assert(str);
//	while ((*dest++ = *str++) && (*str != '\0'))
//	{
//		;
//	}
//}
//int main()
//{
//	char arr[] = "abcde";
//	char a[1024] = { 0 };
//	My_strcpy(a, arr);
//	printf("%s\n", a);
//	system("pause");
//	return 0;
//}
//
//4.模拟实现strcat
//
void My_strcat(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	while (*dest)
	{
		    dest++;
			if (*dest == '\0')
			{
				while (*src)
				{
					*dest++ = *src++;
				}
			}
	}
}
int main()
{
	char a[1024] = "abc";
	char b[] = "edf";
	My_strcat(a, b);
	printf("%s\n", a);
	system("pause");
	return 0;
}
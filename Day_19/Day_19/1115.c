#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//1.模拟实现strncpy
//
//char * Mystrncpy(char * dest, const char * src, size_t num)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	while( (*src) && num)
//	{
//		*dest = *src;
//		dest++;
//		src++;
//		num--;
//	}
//	*dest = '\0';
//	return ret;
//}
//int main()
//{
//	char dest[1024] = "abc";
//	char src[1024] = "ed";
//	Mystrncpy(dest, src, 2);
//	printf("%s\n", dest);
//	system("pause");
//	return 0;
//}
//
//2.模拟实现strncat
//
//char* Mystrncat(char * dest, const char * src, size_t num)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest)
//	{
//		dest++;
//	}
//	while ((*src) && (num))
//	{
//		*dest = *src;
//		dest++;
//		src++;
//		num--;
//	}
//	return ret;
//}
//int main()
//{
//	char dest[1024] = "hello ";
//	char src[1024] = "world";
//	Mystrncat(dest, src, 7);
//	printf("%s\n", dest);
//	system("pause");
//	return 0;
//}
//
//3.模拟实现strncmp
//
int Mystrncmp(const char* str1, const char* str2,size_t num )
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	while ((*str1) && (*str2))
	{
		while (*str1 == *str2)
		{
			str1++;
			str2++;
			num--;
			if (num == 0)
			{
				return 0;
			}
		}
		if (*str1 > *str2)
		{
			return 1;
		}
		if (*str1 < *str2)
		{
			return -1;
		}
	}
}
int main()
{
	char str1[] = "abc";
	char str2[] = "abd";
	printf("%d\n", Mystrncmp(str1, str2, 4));
	system("pause");
	return 0;
}
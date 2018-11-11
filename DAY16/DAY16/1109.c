//3.实现strstr
//4.实现strchr
//5.实现strcmp
//6.实现memcpy
//7.实现memmove
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
char * Mystrstr(const char* str, const char* arr)
{
	for (int i = 0; i < strlen(str) - strlen(arr); i++) {
		for (int j = 0; j < strlen(arr); j++) {
			if (str[i + j] == arr[j]) {
				if (j == strlen(arr) - 1)
				{
					return &str[i];
				}
				continue;
			}
			else break;
		}
	}
	return NULL;
}
int main()
{
	char str[] = "abcdef";
	char arr[] = "abcd";
	char* ret = Mystrstr(str, arr);
	printf("%p\n", ret);
	printf("%p\n", str);
	system("pause");
	return 0;
}
//char * Mystrchr(const char* src, char c)
//{
//	while (*src)
//	{
//		src++;
//		if (*src == c)
//		{
//			return src;
//	    }
//	}
//	return NULL;
//}
//int main()
//{
//	char src[] = "this is a simple string";
//	char* ret = Mystrchr(src, 's');
//	printf("%s\n",ret);
//	system("pause");
//	return 0;
//}
//int Mystrcmp(const char * str1, const char * str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while ((*str1) && (*str2) && (*str1 == *str2))
//	{
//	   str1++;
//       str2++;
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		if(*str1 < *str2)
//		{
//			return -1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char str1[] = "abcd";
//	char str2[] = "sbcd";
//	int i = Mystrcmp(str1, str2);
//	printf("%d\n", i);
//	system("pause");
//	return 0;
//}

//void * Mymemcpy(void * dest, const void * src, size_t num)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	void* ret = dest;
//	for (size_t i = 0; i < num; i++)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//void * Mymemmove(void * dest, const void * src, size_t num)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	assert(num != 0);
//	void* ret = dest;
//	if (dest <= src || dest >= (char*)src + num)
//	{
//		for (size_t i = 0; i < num; i++)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		dest = (char*)dest + num - 1;
//		src = (char*)src + num - 1;
//		for (size_t i = 0; i < num; i++)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest - 1;
//			src = (char*)src - 1;
//		}
//	}
//	return ret;
//}
//int main()
//{
//	char src[100] = {1,2,3,4};
//	int i = 0;
//	Mymemmove(src+1, src, sizeof(src[0]) * 4);
//	for (i = 0; i < 10; ++i)
//	{
//		printf("%d\n",src[i]);
//	}
//	system("pause");
//	return 0;
//}
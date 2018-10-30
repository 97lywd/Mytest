#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*unsigned int reverse_bit(unsigned int n)
{
	unsigned int sum= 0;
	int i = 0;
	for(i=0; i<32; i++)
	{
		sum += ((n>>i) & 1)*pow(2,31-i);
	}
		return i;
 }

int main()
{
	unsigned int n;
	scanf("%d",&n);
printf("%u\n", reverse_bit(n));
}
int Average(int a,int b)
{
	return (a+b)>>1;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d",&a,&b);
	printf("%d",Average(a,b));
	return 0;
}
int Find(int arr[],int len)
{
	int i = 0;
	int ret = 0;
	for(i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}
	return ret;
}
int main()
{
	int arr[]={1,2,2,3,4,3,4,6,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("%d\n",Find(arr,len));
	return 0;
}*/
int Str_len(char *arr)
{
	int count = 0;
	while (*arr++)
	{
		count++;
	}
	return count;
}
void reverse(char* p1, char* p2)
{
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}
}
void reverse_str(char* str)
{
	char *p1 = str;
	char *p2 = str + Str_len(str) - 1;
	reverse(p1, p2);
	char *p3 = str;
	while (*p3)
	{
		char *p1 = p3;
		while ((*p3 != '\0') && (*p3 != ' '))
		{
			p3++;
		}
		reverse(p1, p3 - 1);
		if (*p3 == ' ')
		{
			p3++;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	reverse_str(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}
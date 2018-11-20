#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100
typedef struct PersonInfo
{
	char name[1024];
	char phone[1024]; 
}PersonInfo;
typedef struct Add_book 
{
	PersonInfo* person_info;
	int size;     //标注有意义的值
	int MaxSize;   //动态数组的最大值
}Add_book;
Add_book add_book;
void Init()
{
	add_book.size = 0;
	add_book.MaxSize = 2;
	add_book.person_info = (PersonInfo*)malloc(sizeof(PersonInfo) * add_book.MaxSize);
}
void CheckRealloc()
{
	if (add_book.size < add_book.MaxSize)
	{
		return;    //空间足够，不需扩容
	}
	add_book.MaxSize *= 2;
	PersonInfo* temp = (PersonInfo*)malloc(sizeof(PersonInfo) * add_book.MaxSize);
	for (int i = 0; i < add_book.size; i++)
	{
		temp[i] = add_book.person_info[i];
	}
	free(add_book.person_info);
	add_book.person_info = temp;
}
void Add()
{
	CheckRealloc();
	printf("请输入要添加人的姓名：\n");
	scanf("%s", add_book.person_info[add_book.size].name);
	printf("请输入要添加人的号码: \n");
	scanf("%s", add_book.person_info[add_book.size].phone);
	printf("添加完成\n");
	add_book.size++;
	return;
}
void Del()
{
	if (add_book.size == 0)
	{
		return 0;
	}
	printf("请输入你要删除联系人的编号：\n");
	int i = 0;
	scanf("%d", &i);
	while(i < 0 || i > add_book.size)
	{
     printf("输入编号有误，请重新输入\n");
	 scanf("%d", &i);
	}
    add_book.person_info[add_book.size] = add_book.person_info[i];
	add_book.size--;
	printf("删除完成\n");
}
void Find()   //以名字的方式查找
{
	printf("请输入想要查找联系人的名字\n");
	char i[1024] = { 0 };
	scanf("%s", &i);
	printf("查找结果如下：\n");
	for (int j = 0; j < add_book.size; j++)
	{
		if (strcmp(add_book.person_info[j].name, i) == 0) {
			printf("[%d]  %s: %s\n", j, add_book.person_info[j].name, add_book.person_info[j].phone);
		}
		else
		printf("查无此人，请重新输入\n");
	}
}
void Modify()
{
	printf("请输入要修改联系人的编号：\n");
	int i = 0;
	char arr1[1024] = { 0 };
	char arr2[1024] = { 0 };
	scanf("%d", &i);
	while (i < 0 || i > add_book.size)
	{
		scanf("%d", &i);
		printf("输入编号有误，请重新输入\n");
	}
		printf("请输入要修改的姓名\n");
		scanf("%s", arr1);
		printf("请输入要修改的号码\n");
		scanf("%s", arr2);
		strcpy(add_book.person_info[i].phone, arr2);
		strcpy(add_book.person_info[i].name, arr1);
		printf("修改成功\n");
	}
void Clear()
{
	printf("请确认清空通讯录: (yes/no)\n");
	char arr[100] = { 0 };
	scanf("%s", arr);
	if (strcmp(arr, "yes") == 0)
	{
		add_book.size = 0;
		printf("清除成功\n");
	}
	return 0;
}
void Print()
{
	for (int i = 0; i < add_book.size; i++)
	{
		printf("[%d]  %s: %s\n", i, add_book.person_info[i].name, add_book.person_info[i].phone);
	}
	printf("打印完成：\n");
	printf("共有%d条信息：\n", add_book.size);
}
//以字典序方式对列表进行排序；
void Sort()
{
	for (int i = 0; i < add_book.size; i++)
	{
		for (int j = 0; j < add_book.size; j++)
		{
			if (strcmp(add_book.person_info[j].name, add_book.person_info[j + 1].name) > 0)
			{
				PersonInfo tmp = add_book.person_info[j];
				add_book.person_info[j] = add_book.person_info[j + 1];
				add_book.person_info[j + 1] = tmp;
			}
		}
	}
}
void Save()
{
	printf("Saving\n");
	FILE* fp = fopen("../DAY_17.txt", "w");
	if (fp == NULL)
	{
		printf("File is failed to save \n");
		return;
	}
	for (int i = 0; i < add_book.size; i++)
	{
		fwrite(&add_book.person_info[i], sizeof(PersonInfo), 1, fp);
	}
	fclose(fp);
	printf("successfully save,%d messages\n",add_book.size);
}
void Load()
{
	printf("Loading\n");
	FILE* fp = fopen("../DAY_17.txt", "r");
	if (fp == NULL)
	{
		printf("File is failed to load\n");
		return;
	}
	PersonInfo ret = { 0 };
	while (fread(&ret, sizeof(ret), 1, fp))
	{
		CheckRealloc();
		add_book.person_info[add_book.size] = ret;
		add_book.size++;
	}
	fclose(fp);
	printf("successfully load,%d messages\n", add_book.size);
}
int Menu()
{
	printf("====================================\n");
	printf("   1.增加联系人   \n");
	printf("   2.删除联系人   \n");
	printf("   3.查找联系人   \n");
	printf("   4.修改信息     \n");
	printf("   5.显示信息     \n");
	printf("   6.清空通讯录   \n");
	printf("   0.退出         \n");
	printf("====================================\n");
	printf("请输入你的选择 :\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
enum choice
{
	EXIT = 0,
	add,
	del,
	find,
	midfoy,
	print,
	clear,
};
int main()
{
	Init();
	Load();
	while (1)
	{
		int choice = Menu();
		switch (choice)
		{
		case add:
			Add();
			Sort();
			Save();
			break;
		case del:
			Del();
			Save();
			break;
		case find:
			Find();
			break;
		case midfoy:
			Modify();
			Save();
			break;
		case print:
			Print();
			break;
		case clear:
			Clear();
			Save();
			break;
		case EXIT:
			Save();
			printf("已退出\n");
			system("pause");
			return 0;
			break;
		default:
			printf("输入有误，请重新输入：\n");
			break;
		}
	}
	return 0;
	system("pause");
}

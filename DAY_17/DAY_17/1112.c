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
	int size;     //��ע�������ֵ
	int MaxSize;   //��̬��������ֵ
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
		return;    //�ռ��㹻����������
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
	printf("������Ҫ����˵�������\n");
	scanf("%s", add_book.person_info[add_book.size].name);
	printf("������Ҫ����˵ĺ���: \n");
	scanf("%s", add_book.person_info[add_book.size].phone);
	printf("������\n");
	add_book.size++;
	return;
}
void Del()
{
	if (add_book.size == 0)
	{
		return 0;
	}
	printf("��������Ҫɾ����ϵ�˵ı�ţ�\n");
	int i = 0;
	scanf("%d", &i);
	while(i < 0 || i > add_book.size)
	{
     printf("��������������������\n");
	 scanf("%d", &i);
	}
    add_book.person_info[add_book.size] = add_book.person_info[i];
	add_book.size--;
	printf("ɾ�����\n");
}
void Find()   //�����ֵķ�ʽ����
{
	printf("��������Ҫ������ϵ�˵�����\n");
	char i[1024] = { 0 };
	scanf("%s", &i);
	printf("���ҽ�����£�\n");
	for (int j = 0; j < add_book.size; j++)
	{
		if (strcmp(add_book.person_info[j].name, i) == 0) {
			printf("[%d]  %s: %s\n", j, add_book.person_info[j].name, add_book.person_info[j].phone);
		}
		else
		printf("���޴��ˣ�����������\n");
	}
}
void Modify()
{
	printf("������Ҫ�޸���ϵ�˵ı�ţ�\n");
	int i = 0;
	char arr1[1024] = { 0 };
	char arr2[1024] = { 0 };
	scanf("%d", &i);
	while (i < 0 || i > add_book.size)
	{
		scanf("%d", &i);
		printf("��������������������\n");
	}
		printf("������Ҫ�޸ĵ�����\n");
		scanf("%s", arr1);
		printf("������Ҫ�޸ĵĺ���\n");
		scanf("%s", arr2);
		strcpy(add_book.person_info[i].phone, arr2);
		strcpy(add_book.person_info[i].name, arr1);
		printf("�޸ĳɹ�\n");
	}
void Clear()
{
	printf("��ȷ�����ͨѶ¼: (yes/no)\n");
	char arr[100] = { 0 };
	scanf("%s", arr);
	if (strcmp(arr, "yes") == 0)
	{
		add_book.size = 0;
		printf("����ɹ�\n");
	}
	return 0;
}
void Print()
{
	for (int i = 0; i < add_book.size; i++)
	{
		printf("[%d]  %s: %s\n", i, add_book.person_info[i].name, add_book.person_info[i].phone);
	}
	printf("��ӡ��ɣ�\n");
	printf("����%d����Ϣ��\n", add_book.size);
}
//���ֵ���ʽ���б��������
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
	printf("   1.������ϵ��   \n");
	printf("   2.ɾ����ϵ��   \n");
	printf("   3.������ϵ��   \n");
	printf("   4.�޸���Ϣ     \n");
	printf("   5.��ʾ��Ϣ     \n");
	printf("   6.���ͨѶ¼   \n");
	printf("   0.�˳�         \n");
	printf("====================================\n");
	printf("���������ѡ�� :\n");
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
			printf("���˳�\n");
			system("pause");
			return 0;
			break;
		default:
			printf("�����������������룺\n");
			break;
		}
	}
	return 0;
	system("pause");
}

#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("           - - - - - - - - - - - - - - - - - -\n");
	printf("           - - - - -    1. play      - - - - -\n"); 
	printf("           - - - - -    0. exit      - - - - -\n");
	printf("           - - - - - - - - - - - - - - - - - -\n");
}
void game()
{
	char bomb[ROWS][COLS] = { 0 }; //�������
	char show[ROWS][COLS] = { 0 }; //չʾ����
	Init(bomb, ROWS, COLS, '0');
	Init(show, ROWS, COLS, '*');
	Setbomb(bomb, ROW, COL);
	//Displaybomb(bomb, ROW, COL);
	Displaybomb(show, ROW, COL);
	printf("��������Ҫ�Ų�����꣺\n");
	Findbomb(show,bomb, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("���������ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			    game();
				break;
		case 0:
			printf("�˳���Ϸ:\n");
			break;
		default:
			printf("������������������");
			printf("\n");
		}
	} while (input);
	return 0;
}
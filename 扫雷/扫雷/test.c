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
	char bomb[ROWS][COLS] = { 0 }; //存放雷阵
	char show[ROWS][COLS] = { 0 }; //展示雷阵
	Init(bomb, ROWS, COLS, '0');
	Init(show, ROWS, COLS, '*');
	Setbomb(bomb, ROW, COL);
	//Displaybomb(bomb, ROW, COL);
	Displaybomb(show, ROW, COL);
	printf("请输入想要排查的坐标：\n");
	Findbomb(show,bomb, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			    game();
				break;
		case 0:
			printf("退出游戏:\n");
			break;
		default:
			printf("输入有误，请重新输入");
			printf("\n");
		}
	} while (input);
	return 0;
}
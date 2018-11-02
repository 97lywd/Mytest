#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Init( char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}
void Setbomb(char arr[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int k = count;
	while (k)
	{
		x = rand()% row + 1;
	    y = rand()% col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			k--;
		}
	}
}void Displaybomb(char arr[ROWS][COLS], int row, int col) {

	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);

		}
		printf("\n");
	}
}

void Findbomb(char show[ROWS][COLS],char bomb[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int safecount = 0;
	while (IS_win( show, ROW,COL) - count)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			int i = 0;
			int j = 0;
			safecount++;
			if (bomb[x][y] == '1')
			{
				if (safecount == 1)
				{
					while (1)
					{
						i = rand() % 9 + 1;
						j = rand() % 9 + 1;
						if (bomb[i][j] == '0')
						{
							bomb[x][y] = '0';
							bomb[i][j] = '1';
							show[x][y] = Bombcount(x, y, bomb);
							Expandbomb(x, y, show, bomb, col, row);
							Displaybomb(show, ROW, COL);
							break;
						}
					}
					
				}
				else
				{
					printf("很遗憾，你被炸死\n");
					Displaybomb(bomb, ROW, COL);
					return;
				}
			}
			else
			{
			
				Expandbomb(x , y , show, bomb, col, row);
				Displaybomb(show, ROW, COL);
				printf("请继续输入你要排查的坐标:\n");

			}
		}
		else
		{
			printf("输入坐标有误，请重新输入：\n");
		}
	
	} 
	printf("恭喜你赢了\n");
	
}
char Bombcount(int x, int y,char bomb[ROWS][COLS])
{
	return (bomb[x - 1][y - 1] + bomb[x - 1][y] + bomb[x - 1][y + 1] + bomb[x][y - 1] +
		bomb[x][y + 1] + bomb[x + 1][y - 1] + bomb[x + 1][y] + bomb[x + 1][y + 1]) - 7*'0';
}
void Expandbomb(int x, int y, char show[ROWS][COLS], char bomb[ROWS][COLS],int col,int row)
{
	char a = Bombcount(x, y, bomb);
	/*int i = 0;
	int j = 0;
	if (Bombcount(x, y, bomb) == '0')
	{
		show[x][y] = '0';
			for (i = -1; i <= row; i++)
			{
				for (j = -1; j <= col; j++)
				{
					if (x + i >= 1 && x + i <= row && y + i >= 1 && y + i <= col && (i != 0 || j != 0))
					{
						if (show[x+i][y+i] != '0')
						{
							Expandbomb( x + i, y + i,show,bomb,col,row);
						}
					}
				}
			}
	}
	else
	{
		show[x][y] = Bombcount(x, y, bomb) ;
	}*/
	if (bomb[x][y] == '1' )
	{
		return;
	}
	if (a == '0') {
		show[x][y] = a;
		if (x - 1 > 0 && show[x-1][y]=='*')Expandbomb(x-1, y, show, bomb, col, row);
		if (y - 1 > 0 && show[x][y - 1] == '*')Expandbomb(x , y - 1, show, bomb, col, row);
		if (x + 1 < ROWS-1 && show[x + 1][y] == '*')Expandbomb(x + 1, y, show, bomb, col, row);
		if (y + 1 < COLS-1 && show[x][y + 1] == '*')Expandbomb(x , y + 1, show, bomb, col, row);
	}
	else {
		show[x][y] = a;
	}
}
int  IS_win(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int minecount = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				minecount++;
			}
		}
	}
	return minecount;
}
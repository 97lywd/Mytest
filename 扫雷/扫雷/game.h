#ifndef __GAME__H__
#define __GAME__H__
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROWS 11
#define COLS 11	
#define ROW  9
#define COL 9
#define count 10
//初始化雷阵
void Init(char arr[ROWS][COLS], int rows, int cols, char set);
//随机出雷
void Setbomb(char arr[ROW][COL], int row, int col);
//打印雷阵
void Displaybomb(char arr[ROWS][COLS], int row, int col);
//排查雷阵
void Findbomb(char show[ROWS][COLS],char bomb[ROWS][COLS],int row, int col);
//周围雷数
char  Bombcount(int x, int y,char bomb [ROWS][COLS]);
//排查周围雷数
void Expandbomb(int x, int y, char show[ROWS][COLS], char bomb[ROWS][COLS], int col, int row);
//判断输赢
int IS_win(char show[ROWS][COLS], int row, int col);





#endif // !__GAME__H__


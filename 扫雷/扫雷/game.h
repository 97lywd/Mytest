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
//��ʼ������
void Init(char arr[ROWS][COLS], int rows, int cols, char set);
//�������
void Setbomb(char arr[ROW][COL], int row, int col);
//��ӡ����
void Displaybomb(char arr[ROWS][COLS], int row, int col);
//�Ų�����
void Findbomb(char show[ROWS][COLS],char bomb[ROWS][COLS],int row, int col);
//��Χ����
char  Bombcount(int x, int y,char bomb [ROWS][COLS]);
//�Ų���Χ����
void Expandbomb(int x, int y, char show[ROWS][COLS], char bomb[ROWS][COLS], int col, int row);
//�ж���Ӯ
int IS_win(char show[ROWS][COLS], int row, int col);





#endif // !__GAME__H__


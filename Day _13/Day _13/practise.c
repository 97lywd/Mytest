#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
    //给定一个数组，编程调整使其奇数位于偶数之前

//void Swap(int arr[], int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while ( left < right)
//	{
//		while (((arr[left]) % 2 != 0) && (left < right))
//		{
//			left++;
//		}
//		while (((arr[right]) % 2 == 0) && (left < right))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//} 
//int main()
//{
//	int i = 0;
//	int arr[] = {1,2,3,4,5,6,7,8,9};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Swap(arr,len);
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}


// 杨氏矩阵找一个数 ----->最大时间复杂度O(row+col) < O(N)
// 杨氏矩阵特点：有一个二位数组，数组每行从左到右是递增，每列从上到下是递增的

void Find(int a[3][3], int row, int col, int k, int *px, int *py)
{
	//从右上角开始找
	int i = 0;
	int j = col - 1;
	while ((i < row) && (j >= 0))
	{
		if (a[i][j] == k) //如果找到这个数，保存当前坐标
		{
			*px = i + 1;
			*py = j + 1;
			return;
		}
		else if (a[i][j] < k)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	  *px = -1;
	  *py = -1; //如果没有找到，赋无效值
}

//从左下角开始寻找，用递归实现

void Search(int a[3][3], int row, int col, int k,int x,int y, int*px1, int *py1) {

	if ((x < 0) || (y >= col))
	{
		return 0;
	}
	if (a[x][y] == k)
	{
      *px1 = x + 1;
	  *py1 = y + 1;
		return;
	}
	else if (a[x][y] < k)
	{
		Search(a, row, col,k, x, y + 1,px1,py1);
	}
	else
	{
		Search(a, row, col, k, x - 1, y, px1,py1);
	}
}
int main()
{
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	int px = 0;
	int py = 0;
	int px1 = 0;
	int py1 = 0;
	Find(a, 3, 3, 5, &px, &py);
	Search(a, 3, 3, 5, 2, 0, &px1, &py1);
	printf("%d %d \n", px, py);
	printf("%d %d \n", px1, py1);
	system("pause");
	return 0;
}
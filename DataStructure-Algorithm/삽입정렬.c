/* ���� ���� : �ι�° �ڷ���� �� �ڷḦ ���Ͽ� �����Ѵ�. */
#include <stdio.h>

void insertionSort(int*, int); 

void printAry(int*, int);

int main(void)
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 }; 
	int size = sizeof(ary) / sizeof(ary[0]); 
	insertionSort(ary, size); 

	printAry(ary, size); 

	return 0; 
}

void insertionSort(int* pary, int size)
{
	int i, j, k; 
	int temp; 
	for ( i = 1; i < size; i++) {				// ���� for������ ���� ! 
		for ( j = i; j > 0; j--)				// i�� ���� �ε��� ��� j�� ���� ���� ���ϸ鼭 �ڸ� ������ !!
		{
			if (pary[j] < pary[j - 1]) {
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
		printf("\n%d �ܰ� : ", i); 
		for ( k = 0; k < size; k++)
		{
			printf("%d   ", pary[k]);
		}
	}
}

void printAry(int* pary, int size)
{
	printf("\n"); 
	int i; 
	for ( i = 0; i < size; i++)
	{
		printf("ary[%d] = %d\n", i, pary[i]); 
	}
}
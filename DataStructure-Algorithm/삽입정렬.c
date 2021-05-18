/* 삽입 정렬 : 두번째 자료부터 앞 자료를 비교하여 정렬한다. */
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
	for ( i = 1; i < size; i++) {				// 이중 for문으로 구현 ! 
		for ( j = i; j > 0; j--)				// i로 값의 인덱스 잡고 j로 이전 값과 비교하면서 자리 내리기 !!
		{
			if (pary[j] < pary[j - 1]) {
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
		printf("\n%d 단계 : ", i); 
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
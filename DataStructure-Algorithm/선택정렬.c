/* 
선택 정렬 : 0번방을 최소값이라 가정한다. 
0번 값으로 뒤로 쭉 훑으면서 찾은 최소값을 0번방에 저장 ! 
*/
#include <stdio.h>

void selectSort(int*, int); 

int main(void)
{
	int ary[] = { 4,2,7,5,9,1,8,3,6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	selectSort(ary, size);

	return 0; 
}

void selectSort(int* pary, int size)
{
	int i, j, k; 
	int min, temp; 
	for (i = 0; i < (size - 1); i++) {			// 이중 for문으로 선택정렬 알고리즘 구현 !
		min = i;								
		for ( j = i + 1; j < size; j++)
		{
			if (pary[min] > pary[j]) min = j; 
		}
		temp = pary[min]; 
		pary[min] = pary[i]; 
		pary[i] = temp; 
		printf("\n%d 단계 : ", i + 1); 
		for ( k = 0; k < size; k++) {
			printf("%d   ", pary[k]); 
		}
	}

}
/* 
퀵 정렬 : 대표적인 분할 정복 알고리즘 
정렬이 안되어있는 데이터에 사용해야 성능이 발휘됨 (가장 빠르다)
1. 원소들 중에서 pivot(기준)을 고른다. 
2. 이 pivot을 기준으로 앞에는 작은값, 뒤에는 큰 값 (분할)
3. 분할된 작은 리스트를 재귀적으로 동작시킨다.(정복)
4. 정렬된 작은 리스트들을 결합한다.(결합) 
*/
#include <stdio.h>

void quickSort(int*, int, int); 

int main(void)
{
	int ary[] = { 3, 5, 2, 4, 7, 6, 1, 8 };
	int size = sizeof(ary) / sizeof(ary[0]); 
	printf("ary[] : 3, 5, 2, 4, 7, 6, 1, 8\n\n"); 
	quickSort(ary, 0, size - 1);

	return 0; 
}

void quickSort(int* pary, int left, int right)
{
	int lidx = left, ridx = right;					// li = left = 0, ri = right = size -1, li와 lr은 index를 나타냄
	int temp;										// n/2로 피봇을 설정한다 !		
	int pivot = (left + right) / 2; 
	printf("pivot - index : %d, value : %d\n", pivot, pary[pivot]); 
	while (lidx <= ridx) {							// li와 ri가 교차되기 전까지 실행한다. 
		while (pary[lidx] < pary[pivot]) lidx++;	// 피봇의 왼쪽 리스트 중 작은 값은 통과 
		while (pary[ridx] > pary[pivot]) ridx--;	// 피봇의 오른쪽 리스트 중 큰 값은 통과 
		if (lidx <= ridx)							// 정렬할 조건이 되면(lidx == ridx 이면 pivot 값이다.)
		{											// 찾은 리스트의 두 값을 교환하여 정렬한다. 
			temp = pary[ridx]; 
			pary[ridx] = pary[lidx]; 
			pary[lidx] = temp; 
			printf("%d : %d\n", temp, pary[ridx]); 
			lidx++;  
			ridx--; 
		}
	}
	for (int i = 0; i <= right; i++) printf("%3d", pary[i]); 
	printf("\n"); 
	if (left < ridx) quickSort(pary, left, ridx);   // a
	if (lidx < right) quickSort(pary, lidx, right); // b
	
}
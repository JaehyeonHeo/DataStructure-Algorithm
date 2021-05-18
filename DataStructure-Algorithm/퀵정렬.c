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
	int ary[] = { 3, 5, 2, 4, 7, 6, 1 };
	int size = sizeof(ary) / sizeof(ary[0]); 
	quickSort(ary, 0, size - 1);

	return 0; 
}

void quickSort(int* pary, int left, int right)
{
	if (left >= right) return; 
	int pivot = left;
	int lleft = pivot + 1; 
	int lright = right;
	int temp; 
	int k; 
	while (lleft <= lright) {  // lleft, lright가 교차 안될때 까지 
		while (pary[lleft] <= pary[pivot]) lleft++; 
		while (pary[lright] >= pary[pivot] && lright > left) lright--; 

		if (lleft > lright) {
			temp = pary[lright]; 
			pary[lright] = pary[pivot];
			pary[pivot] = temp; 
		}
		else {
			temp = pary[lright]; 
			pary[lright] = pary[lleft]; 
			pary[lleft] = temp; 
		}
	}
	for (k = 0; k < right + 1; k++) {
		printf("%d   ", pary[k]);
	}
	printf("\n"); 

	quickSort(pary, left, lright - 1); 
	quickSort(pary, lright + 1, right);
}
#include <stdio.h>

int BSearch(int* pary, int size, int target) 
{
	int first = 0; 
	int last = size - 1; // 0부터 시작하므로 -1
	int mid; 
	
	while (first <= last) {
		mid = (first + last) / 2; // 가운데 기준점 설정
		if (target == pary[mid]) return mid; 
		else {
			if (target > pary[mid]) first = mid + 1;
			else last = mid - 1; 
		}
	}
	return -1; 
}

int main(void)
{
	int ary[] = { 1, 2, 3, 5, 6, 7, 8 }; 
	int size = sizeof(ary) / sizeof(ary[0]);
	int index; 

	index = BSearch(ary, size, 5);

	if (index == -1) printf("탐색 실패");
	else printf("index : %d\n", index); 

	return 0; 
}
#include <stdio.h>

// 순차적으로 데이터를 탐색하는 함수 
int LSearch(int* pary, int sz, int tg)
{
	int i; 
	for ( i = 0; i < sz; i++)
	{
		if (pary[i] == tg) {
			return i;
		}
	}
	return -1; 
}

int main(void)
{
	int index; // 배열의 인덱스를 저장하는 변수 선언 
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };     // 배열 정의 
	int size = sizeof(ary) / sizeof(ary[0]); // 배열의 요소 개수를 저장하는 size 

	index = LSearch(ary, size, 2); // 변수index에다가 배열에서 2라는 데이터를 가진 요소의 인덱스 저장 !

	if (index == -1) printf("찾기 실패 !");
	else printf("index : %d\n", index); 


	return 0; 
}

/* 
예제 2-2
학년별 취득 학점을 1차원 배열에 저장하고 출력하는 프로그램 만들기
*/

#include <stdio.h>

int main(void)
{
	int score[3] = { 91, 86, 97 }; 
	char grade[3] = { 'A', 'B', 'A' };

	int i;
	printf("\n========학년별 시험 결과========\n"); 
	for ( i = 0; i < 3; i++)
	{
		printf("%d학년의 점수 : %d, 등급 : %c\n", i + 1, score[i], grade[i]); 
	}

	return 0; 
}

/* 
���� 2-2
�г⺰ ��� ������ 1���� �迭�� �����ϰ� ����ϴ� ���α׷� �����
*/

#include <stdio.h>

int main(void)
{
	int score[3] = { 91, 86, 97 }; 
	char grade[3] = { 'A', 'B', 'A' };

	int i;
	printf("\n========�г⺰ ���� ���========\n"); 
	for ( i = 0; i < 3; i++)
	{
		printf("%d�г��� ���� : %d, ��� : %c\n", i + 1, score[i], grade[i]); 
	}

	return 0; 
}
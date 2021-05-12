#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a; 
	int i; 
	printf("몇단을 실행할까요!"); 
	scanf("%d", &a); 
	if (a > 9 || a < 2)
	{
		printf("2~9사이 숫자를 입력하세요"); 
	}
	else
	{
		for (i = 1; i < 10; i++)
		{
			printf("%d * %d = %d\n", a, i, (a * i)); 
		}
	}

}
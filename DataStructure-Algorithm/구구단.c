#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a; 
	int i; 
	printf("����� �����ұ��!"); 
	scanf("%d", &a); 
	if (a > 9 || a < 2)
	{
		printf("2~9���� ���ڸ� �Է��ϼ���"); 
	}
	else
	{
		for (i = 1; i < 10; i++)
		{
			printf("%d * %d = %d\n", a, i, (a * i)); 
		}
	}

}
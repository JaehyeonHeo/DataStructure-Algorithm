#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[50]; 
	int i; 
	int cnt = 0; 

	printf("���ڿ��� �Է� �ϼ��� : "); 
	gets(str); 

	for ( i = 0; str[i]; i++)
	{
		printf("%c", str[i]); 
		cnt++; 
	}

	printf("�� �Էµ� ���ڴ� %d�� �Դϴ�.\n", cnt); 

	return 0; 
}
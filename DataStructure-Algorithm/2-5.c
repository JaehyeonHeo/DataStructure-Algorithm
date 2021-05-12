#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[50]; 
	int i; 
	int cnt = 0; 

	printf("문자열을 입력 하세요 : "); 
	gets(str); 

	for ( i = 0; str[i]; i++)
	{
		printf("%c", str[i]); 
		cnt++; 
	}

	printf("의 입력된 문자는 %d개 입니다.\n", cnt); 

	return 0; 
}
#include <stdio.h>

void main()
{
	char str[20] = "Data Structure!"; 
	int cnt = 0; 
	int i; 
	printf("\n문자 배열 str[] : "); 
	for ( i = 0; str[i]; i++)  // str[i]에 널 문자가 들어가면 종료된다 
	{
		printf("%c", str[i]); 
		cnt++; 
	}
	printf("%d", cnt);  // cnt == 15

	getchar(); 
}
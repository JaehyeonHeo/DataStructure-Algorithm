#include <stdio.h>

void main()
{
	char str[20] = "Data Structure!"; 
	int cnt = 0; 
	int i; 
	printf("\n���� �迭 str[] : "); 
	for ( i = 0; str[i]; i++)  // str[i]�� �� ���ڰ� ���� ����ȴ� 
	{
		printf("%c", str[i]); 
		cnt++; 
	}
	printf("%d", cnt);  // cnt == 15

	getchar(); 
}
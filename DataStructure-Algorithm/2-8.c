#include <stdio.h>

int main(void)
{
	int i = 10, j = 20; 
	int* ptr; 
	
	printf("i�� �� : %d, j�� �� : %d", i, j); 
	printf("i�� �ּ� �� : %d", &i); 
	printf("j�� �ּ� �� : %d", &j);

	ptr = &i; 
	printf("\n\n << ptr=&i ���� >>"); 
	printf("\n ptr�� �޸� �ּ� : %u", &ptr); 
	printf("\n ptr�� �� : %u", ptr); 
	printf("\n ptr�� ������ : %d", *ptr); 
	
	ptr = &j;
	printf("\n\n << ptr=&j ���� >>");
	printf("\n ptr�� �޸� �ּ� : %u", &ptr);
	printf("\n ptr�� �� : %u", ptr);
	printf("\n ptr�� ������ : %d", *ptr);

	i = *ptr;
	printf("\n\n << i = *ptr ���� >>"); 
	printf("\n i�� �� = %d", i); 

	return 0; 
}
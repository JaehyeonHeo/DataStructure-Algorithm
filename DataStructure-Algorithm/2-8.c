#include <stdio.h>

int main(void)
{
	int i = 10, j = 20; 
	int* ptr; 
	
	printf("i의 값 : %d, j의 값 : %d", i, j); 
	printf("i의 주소 값 : %d", &i); 
	printf("j의 주소 값 : %d", &j);

	ptr = &i; 
	printf("\n\n << ptr=&i 실행 >>"); 
	printf("\n ptr의 메모리 주소 : %u", &ptr); 
	printf("\n ptr의 값 : %u", ptr); 
	printf("\n ptr의 참조값 : %d", *ptr); 
	
	ptr = &j;
	printf("\n\n << ptr=&j 실행 >>");
	printf("\n ptr의 메모리 주소 : %u", &ptr);
	printf("\n ptr의 값 : %u", ptr);
	printf("\n ptr의 참조값 : %d", *ptr);

	i = *ptr;
	printf("\n\n << i = *ptr 실행 >>"); 
	printf("\n i의 값 = %d", i); 

	return 0; 
}
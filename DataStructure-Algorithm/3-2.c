#include <stdio.h>

void main() {
	int i, n = 0, * ptr; 
	int sale[2][4] = { {63,84,140,130},
					  {157,209,251,312} }; 

	// 포인터 
	ptr = &sale[0][0]; 
	for ( i = 0; i < 8; i++)
	{
		printf("\n address : %u, sale[%d] = %d", ptr, i, *ptr); 
		ptr++; 
	}

	// 배열 포인터 
	int (*pa)[4] = sale; 

	printf("\n sale[1][1] = %d", pa[1][1]); // == *(pa[1] + 1)
	printf("\n %u %u", pa, pa + 1); 
	printf("\n %u %u", pa[0], pa[0] + 1); 

	getchar(); 
}
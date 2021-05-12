#include <stdio.h>	

int main(void)
{
	int i; 
	char* ptrArry[4] = { {"Korea"}, {"Seoul"}, {"Mapo"}, {"152¹øÁö 2 / 3"} }; 
	for ( i = 0; i < 4; i++)
	{
		printf("\n %s", ptrArry[i]); 
	}
	ptrArry[2] = "Jongno"; 
	printf("\n\n"); 
	for ( i = 0; i < 4; i++)
	{
		printf("\n %s", ptrArry[i]); 
	}

	return 0; 
}
#include <stdio.h>

int main(void)
{
	int i, j, k; 
	char student[2][3][20];

	for ( i = 0; i < 2; i++)
	{
		printf("\n�л� %d�� �̸� : ", i+1); 
		gets(student[i][0]); // gets�� scanf�� �ٸ��� ������⵵ �Է� ���� �ϴ�.
		printf(" �а� : "); 
		gets(student[i][1]); 
		printf(" �й� : "); 
		gets(student[i][2]); 
	}

	for ( i = 0; i < 2; i++)
	{
		printf("\n\n �л� %d", i + 1); 
		for ( j = 0; j < 3; j++)
		{
			printf("\n\t"); 
			for ( k = 0; student[i][j][k] != '\0'; k++)
			{
				printf("%c", student[i][j][k]); 
			}
		}
	}

	return 0;
}
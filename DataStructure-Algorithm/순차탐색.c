#include <stdio.h>

// ���������� �����͸� Ž���ϴ� �Լ� 
int LSearch(int* pary, int sz, int tg)
{
	int i; 
	for ( i = 0; i < sz; i++)
	{
		if (pary[i] == tg) {
			return i;
		}
	}
	return -1; 
}

int main(void)
{
	int index; // �迭�� �ε����� �����ϴ� ���� ���� 
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };     // �迭 ���� 
	int size = sizeof(ary) / sizeof(ary[0]); // �迭�� ��� ������ �����ϴ� size 

	index = LSearch(ary, size, 2); // ����index���ٰ� �迭���� 2��� �����͸� ���� ����� �ε��� ���� !

	if (index == -1) printf("ã�� ���� !");
	else printf("index : %d\n", index); 


	return 0; 
}
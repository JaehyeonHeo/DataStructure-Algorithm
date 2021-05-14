#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct node {
	int data; 
	struct node* link; 
}Node;

void addNode(Node* target, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;           // ���ο����� �����Ϳ� �� ���� 
	newNode->link = target->link;  // ���ο����� ��ũ�� target�� ��ũ ����
	target->link = newNode;       // target�� link���� ���ο� ����� �ּҰ� ���� 
}

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node)); 
	head->link = NULL;

	int i = 1;
	int size; 
	printf("����� ��� �� : "); 
	scanf("%d", &size); 
	for (i = 1; i <= size; i++)
	{
		addNode(head, i * 10);
	}

	int j = 1; 
	Node* curr = head->link;
	while (curr != NULL)
	{
		printf("%d��° ����� �����Ͱ� : %d\n", j, curr->data);
		curr = curr->link;
		j++;
	}

	int k = 0; 
	Node* temp = head; 
	while (1)
	{
		if (temp == NULL) break; 
		printf("%d ��° �޸� ���� free(node%d)\n", k, k); 
		free(temp); 
		temp = temp->link; 
		k++; 
	}

	return 0; 
}


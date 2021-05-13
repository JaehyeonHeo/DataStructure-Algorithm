#include <stdio.h>

typedef struct node{
	int data;			// data�� �����ϴ� ���
	struct node* link;  // ���� ����� �ּҸ� �����ϴ� ��� 
}Node;

int main(void)
{
	// ��� ���� !
	Node* head = (Node*)malloc(sizeof(Node));  // �޸� �����Ҵ� malloc
	Node* node1 = (Node*)malloc(sizeof(Node)); // �Ҵ�� �޸��� �ּҰ��� �����ϴ� malloc !
	Node* node2 = (Node*)malloc(sizeof(Node)); // ��ȣ���� �����ŭ�� �޸� �Ҵ�
	Node* node3 = (Node*)malloc(sizeof(Node)); 
	Node* node4 = (Node*)malloc(sizeof(Node)); 
	Node* node5 = (Node*)malloc(sizeof(Node)); 

	if (node1 == NULL) return; 
	// ��忡 �����Ϳ� ��ũ ���� 
	head->link = node1;   // ��� ����� ��ũ�� ù��° ����� �ּҰ��� ���� 
	node1->data = 10; 
	node1->link = node2; 
	node2->data = 20; 
	node2->link = node3; 
	node3->data = 30; 
	node3->link = node4; 
	node4->data = 40; 
	node4->link = node5; 
	node5->data = 50; 
	node5->link = NULL; 

	int i = 1;
	Node* curr = head->link; 
	while (curr != NULL)
	{
		printf("%d��° ����� �����Ͱ� : %d\n", i, curr->data); 
		curr = curr->link; 
		i++; 
	}

	free(head); 
	free(node1); 
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	return 0; 
}
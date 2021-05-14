#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct node {
	int data; 
	struct node* link; 
}Node;

void addNode(Node* target, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;           // 새로운노드의 데이터에 값 저장 
	newNode->link = target->link;  // 새로운노드의 링크에 target의 링크 저장
	target->link = newNode;       // target의 link에는 새로운 노드의 주소값 저장 
}

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node)); 
	head->link = NULL;

	int i = 1;
	int size; 
	printf("출력할 노드 수 : "); 
	scanf("%d", &size); 
	for (i = 1; i <= size; i++)
	{
		addNode(head, i * 10);
	}

	int j = 1; 
	Node* curr = head->link;
	while (curr != NULL)
	{
		printf("%d번째 노드의 데이터값 : %d\n", j, curr->data);
		curr = curr->link;
		j++;
	}

	int k = 0; 
	Node* temp = head; 
	while (1)
	{
		if (temp == NULL) break; 
		printf("%d 번째 메모리 해제 free(node%d)\n", k, k); 
		free(temp); 
		temp = temp->link; 
		k++; 
	}

	return 0; 
}


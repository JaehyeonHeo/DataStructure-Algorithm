#include <stdio.h>

typedef struct node{
	int data;			// data를 저장하는 멤버
	struct node* link;  // 다음 노드의 주소를 저장하는 멤버 
}Node;

int main(void)
{
	// 노드 생성 !
	Node* head = (Node*)malloc(sizeof(Node));  // 메모리 동적할당 malloc
	Node* node1 = (Node*)malloc(sizeof(Node)); // 할당된 메모리의 주소값을 리턴하는 malloc !
	Node* node2 = (Node*)malloc(sizeof(Node)); // 괄호안의 사이즈만큼의 메모리 할당
	Node* node3 = (Node*)malloc(sizeof(Node)); 
	Node* node4 = (Node*)malloc(sizeof(Node)); 
	Node* node5 = (Node*)malloc(sizeof(Node)); 

	if (node1 == NULL) return; 
	// 노드에 데이터와 링크 저장 
	head->link = node1;   // 헤더 노드의 링크에 첫번째 노드의 주소값을 저장 
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
		printf("%d번째 노드의 데이터값 : %d\n", i, curr->data); 
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
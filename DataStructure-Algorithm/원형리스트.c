#include <stdio.h>

// 구조체 리스트 선언 
typedef struct listnode {
	int data; 
	struct listnode* link; 
}ListNode;

typedef struct {
	ListNode* head; 
}HeadNode;

// 함수선언+정의(전치)
HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode)); 
	if (h != NULL) h->head = NULL; 

	return h; 
}

ListNode* createNode(HeadNode* phead, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode)); 
	if (newNode != NULL) 
	{
		newNode->data = data; 
		newNode->link = NULL;

		return newNode; 
	}
}
void insertFirstNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL) 
	{
		phead->head = newNode; 
		newNode->link = newNode; 
	}
	else
	{
		newNode->link = phead->head->link; 
		phead->head->link = newNode; 
	}
}

void insertLastNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode; 
		newNode->link = newNode; 
	}
	else
	{
		newNode->link = phead->head->link; 
		phead->head->link = newNode; 
		phead->head = newNode; 
	}
}

void printNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("출력할 노드가 없습니다");
	}
	else
	{
		printf("\n========출력함수로 모든 데이터 출력========\n"); 
		ListNode* curr = phead->head->link; 
		int i = 1; 
		while (curr != phead->head)
		{
			printf("%d번째 노드의 데이터 : %d\n", i, curr->data); 
			curr = curr->link; 
			i++; 
		}
		printf("%d번째 노드의 데이터 : %d\n", i, phead->head->data); 

	}
}

void deleteNode(HeadNode* phead)
{
	ListNode* curr = NULL; 
	while (phead->head != NULL)
	{
		curr = phead->head->link;
		phead->head->link = phead->head->link->link; 
		free(curr);
		curr = NULL; 
	}
	free(phead);
}

// 메인함수 
int main()
{
	HeadNode* h = createHead(); 
	ListNode* n1 = createNode(h, 1); 
	ListNode* n2 = createNode(h, 2); 
	ListNode* n3 = createNode(h, 3); 
	ListNode* n4 = createNode(h, 4); 

	insertFirstNode(h, n1);
	insertFirstNode(h, n2); 

	insertLastNode(h, n3);
	insertLastNode(h, n4); 

	printNode(h);

	//deleteNode(h); 

	//printNode(h); 

	return 0; 
}
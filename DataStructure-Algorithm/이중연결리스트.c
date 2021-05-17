#include <stdio.h>

typedef struct dlistnode {
	int data;
	struct dlistnode* next;
	struct dlistnode* prev;
}DListNode;

typedef struct {
	DListNode* head;
}HeadNode;

HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}

DListNode* createNode(int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		printf("메모리 할당 실패!!");
		exit(1);
	}
	else
	{
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;

		return newNode;
	}
}

void insertNode(HeadNode* phead, DListNode* preNode, DListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;
		newNode->prev = phead;
	}
	else
	{
		newNode->prev = preNode;
		newNode->next = preNode->next;
		if (preNode->next != NULL) preNode->next->prev = newNode;
		preNode->next = newNode;
	}
}

DListNode* searchNode(HeadNode* phead, int data)
{
	DListNode* targetN = phead->head;
	while (targetN->data != data)
	{
		targetN = targetN->next;
	}

	return targetN;
}
// 선택 노드 삭제 
void deleteNode(HeadNode* phead, DListNode* targetNode) 
{
	DListNode* curr = phead->head;
	while (curr->data != targetNode->data)
	{
		curr = curr->next;
	}
	curr->prev->next = targetNode->next; 
	if(targetNode->next != NULL) targetNode->next->prev = curr->prev; 
	free(targetNode);
}

void deleteAllNodes(HeadNode* phead)
{
	DListNode* curr = NULL; 
	while (phead->head != NULL)
	{
		curr = phead->head; 
		phead->head = phead->head->next; 
		free(curr); 
		curr = NULL; 
	}
	free(phead); 
}

int main()
{
	HeadNode* phead = createHead(); // 헤드노드 생성
	DListNode* lp = NULL;           // 새로운 노드 생성 
	DListNode* n1 = createNode(8);  // 중간 삽입 노드 생성 
	DListNode* n2 = createNode(9);
	DListNode* n3 = createNode(10);

	insertNode(phead, lp, n1); // 노드가 없을 때 처음 노드로 중간삽입 노드 생성 
	insertNode(phead, n1, n2);
	insertNode(phead, n2, n3);

	DListNode* targetNode = searchNode(phead, 9); // => n2

	printf("%d\n", n1->next->data);  // 삭제 전 n1 다음 리스트의 데이터 값
	deleteNode(phead, targetNode);

	printf("%d\n", n1->next->data); // 삭제 후 n1 다음 리스트의 데이터 값 

	deleteAllNodes(phead); 
	printf("%d\n", n1->data); 

	return 0;
}
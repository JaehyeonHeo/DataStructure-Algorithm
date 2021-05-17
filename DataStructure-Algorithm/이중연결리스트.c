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
		printf("�޸� �Ҵ� ����!!");
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
// ���� ��� ���� 
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
	HeadNode* phead = createHead(); // ����� ����
	DListNode* lp = NULL;           // ���ο� ��� ���� 
	DListNode* n1 = createNode(8);  // �߰� ���� ��� ���� 
	DListNode* n2 = createNode(9);
	DListNode* n3 = createNode(10);

	insertNode(phead, lp, n1); // ��尡 ���� �� ó�� ���� �߰����� ��� ���� 
	insertNode(phead, n1, n2);
	insertNode(phead, n2, n3);

	DListNode* targetNode = searchNode(phead, 9); // => n2

	printf("%d\n", n1->next->data);  // ���� �� n1 ���� ����Ʈ�� ������ ��
	deleteNode(phead, targetNode);

	printf("%d\n", n1->next->data); // ���� �� n1 ���� ����Ʈ�� ������ �� 

	deleteAllNodes(phead); 
	printf("%d\n", n1->data); 

	return 0;
}
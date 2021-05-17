#include <stdio.h>

typedef struct listnode {
	int data; 
	struct listnode* link; 
}ListNode;
typedef struct {
	ListNode* head; 
}HeadNode;

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

	printf("%d %d\n", n1->data, n2->data); // ������ �� Ȯ�� 

	printf("%p = %p\n", n4->link, n2); // ��ũ Ȯ�� 

	printf("������ ��� ������ : %d\n", h->head->data); 
	printf("ù��° ��� ������ : %d\n", h->head->link->data); 
	printf("�ι�° ��� ������ : %d\n", h->head->link->link->data); 
	printf("����° ��� ������ : %d\n", h->head->link->link->link->data); 

	return 0; 
}
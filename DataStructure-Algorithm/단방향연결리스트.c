#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct node {
	int data; 
	struct node* next;   // �ڱ� ���� ����ü 
}Node;

typedef struct headnode {
	Node* head;          // ��带 ����Ű�� �����Ͱ� �;��Ѵ� 
}HeadNode;

/* ����� �����ϴ� �Լ� */
HeadNode* createHead(void) 
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode)); 
	if (h != NULL) h->head = NULL; 

	return h; 
}
/* ��� �ٷ� �ڿ� �ٴ� ��� �����ϴ� �Լ� */
void preInsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // malloc : �����޸� �Ҵ� �� �ּ� ��ȯ !
	if (newNode != NULL) // newNode�� �ּҰ� ���� �Ǿ��ٸ�,,,,
	{
		newNode->data = data;
		newNode->next = h->head;
		h->head = newNode;
		printf("���ο� ��ġ��� ���� (%d)\n", data); 
	}
}
/* �� �� ��� �ڷ� �ٴ� ���� ���� �Լ�*/
void rearInsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;

		if (h->head != NULL)
		{
			Node* curr;
			curr = h->head;
			int i = 0;
			while (curr->next != NULL)
			{
				curr = curr->next;
				i++;
			}
			curr->next = newNode;
		}
		else
		{
			h->head = newNode; 
		}
	}
	printf("���ο� ��ġ��� ���� (%d)\n", data);
}
/* ����ϴ� �Լ�*/
void printNode(HeadNode* h)
{
	printf("\n===========���================\n"); 
	Node* curr;
	curr = h->head;
	int i = 1;
	while (1)
	{
		printf("%d��° ����� data : %d\n", i, curr->data);
		if (curr->next == NULL) break;
		curr = curr->next;
		i++;
	}
}
/* ��ü ��� ���� �Լ� */
void deleteNode(HeadNode* h)
{
	printf("��ü ��� ���� ����\n"); 
	
	if (h->head == NULL)
	{
		free(h);
	}
	else if (h->head != NULL)
	{
		while(1)
		{
			Node* node;
			Node* temp;
			node = h->head;
			int i = 0;

			if (node == NULL) break;
			
			while (node->next != NULL)
			{
				node = node->next;
				i++;
			}
			printf("��ü ����� ���� = %d\n", i);
			temp = node;
			free(temp);
			printf("�� �� ��� ���� �Ϸ�");
		}
	}
	

}

/* ��� �˻� �Լ� */
Node* searchNode(HeadNode* h, int data)
{
	printf("\n======='%d' ���� ���� ��� �˻�=========\n", data);
	Node* s = h->head;
	int i = 1;
	while (s->data != data)
	{
		s = s->next;
		i++; 
	}
	printf("%d���� ���� �ִ� %d��° node\n", s->data, i);

	return s;
}
/* �˻��� ��� ���� �Լ� */
void searchNodeDelete(HeadNode* h, Node* s)
{
	
}

/* �߰��� ��� ���� �Լ� */
void midInsertNode(HeadNode* h, int num)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		if (h->head == NULL)
		{
			printf("��尡 �����ϴ�");
			h->head = newNode;
		}
		else
		{
			int i = 1;
			int newData = 0;
			Node* pn = h->head;
			while (i != num)
			{
				pn = pn->next;
				i++;
			}
			printf("\n%d ��° �ٷ� �ڿ� ������ �����Ͱ� �Է� : ", i);
			scanf("%d", &newData);

			newNode->next = pn->next;
			pn->next = newNode;
			newNode->data = newData;
		}
		
	}
}

int main(void)
{
	HeadNode* h = createHead(); 
	
	rearInsertNode(h, 0);
	rearInsertNode(h, 1);
	preInsertNode(h, 10);
	rearInsertNode(h, 2); 
	rearInsertNode(h, 3); 
	preInsertNode(h, 11); 
	preInsertNode(h, 12); 

	printNode(h);

	midInsertNode(h, 2);  // ������ ��� ���� �Է� !
	
	printNode(h); 
	
	searchNode(h, 10);


	return 0; 
}
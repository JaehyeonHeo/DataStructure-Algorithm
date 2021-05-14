#include <stdio.h>

typedef struct node {
	int data; 
	struct node* next;   // 자기 참조 구조체 
}Node;

typedef struct headnode {
	Node* head;          // 노드를 가리키는 포인터가 와야한다 
}HeadNode;

/* 헤더를 생성하는 함수 */
HeadNode* createHead(void) 
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode)); 
	if (h != NULL) h->head = NULL; 

	return h; 
}
/* 헤더 바로 뒤에 붙는 노드 생성하는 함수 */
void preInsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // malloc : 동적메모리 할당 후 주소 반환 !
	if (newNode != NULL) // newNode의 주소가 생성 되었다면,,,,
	{
		newNode->data = data;
		newNode->next = h->head;
		h->head = newNode;
		printf("새로운 전치노드 생성 (%d)\n", data); 
	}
}
/* 맨 뒤 노드 뒤로 붙는 후위 삽입 함수*/
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
	printf("새로운 후치노드 생성 (%d)\n", data);
}
/* 출력하는 함수*/
void printNode(HeadNode* h)
{
	printf("\n===========결과================\n"); 
	Node* curr;
	curr = h->head;
	int i = 1;
	while (1)
	{
		printf("%d번째 노드의 data : %d\n", i, curr->data);
		if (curr->next == NULL) break;
		curr = curr->next;
		i++;
	}
}
/* 전체 노드 삭제 함수 */
void deleteNode(HeadNode* h)
{
	printf("전체 노드 삭제 시작"); 
	Node* temp = h->head;
	while (temp->next != NULL)
	{
		h->head = temp->next;
		

	}
	if (temp->next == NULL)
	{
		free(temp);
		free(h);
	}

}

/* 노드 검색 함수 */
Node* searchNode(HeadNode* h, int data)
{
	printf("\n======='%d' 값을 가진 노드 검색=========\n", data);
	Node* s = h->head;
	int i = 1;
	while (s->data != data)
	{
		s = s->next;
		i++; 
	}
	printf("%d값을 갖고 있는 %d번째 node\n", s->data, i);

	return s;
}
/* 검색된 노드 삭제 함수 */
void searchNodeDelete(HeadNode* h, Node* s)
{

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
	
	searchNode(h, 10);


	deleteNode(h); 
	printNode(h);

	

	return 0; 
}
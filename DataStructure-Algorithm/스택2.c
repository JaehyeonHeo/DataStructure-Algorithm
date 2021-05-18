#include <stdio.h>
#include <stdbool.h>

typedef struct snode {
	int data; 
	struct snode* link; 
}SNode;
typedef struct {
	SNode* topstack; 
}TStack;

TStack* createHead()
{
	TStack* t = (TStack*)malloc(sizeof(TStack)); 
	if (t != NULL) t->topstack = NULL; 
	return t; 
}

int isEmpty(TStack* ptstack)
{
	if (ptstack->topstack == NULL) return true;
	else return false; 
}

void push(TStack* ptstack, int data)
{
	SNode* newNode = (SNode*)malloc(sizeof(SNode)); 
	if (newNode == NULL) return; 
	newNode->data = data; 
	newNode->link = ptstack->topstack; 
	ptstack->topstack = newNode; 
}

int pop(TStack* ptstack)
{
	int data; 
	SNode* temp; 
	if (ptstack->topstack == NULL) { 
		printf("STACK is Empty ! !\n"); 
		return; 
	}
	else {
		data = ptstack->topstack->data; 
		temp = ptstack->topstack; 
		ptstack->topstack = ptstack->topstack->link; 
		free(temp); 
		return data; 
	}
}
int peek(TStack* ptstack)
{
	if (isEmpty(ptstack)) {
		printf("STACK is Empty !!\n");
		return; 
	}
	else {
		return ptstack->topstack->data; 
	}
}
void printStack(TStack* ptstack)
{
	SNode* curr = ptstack->topstack; 
	while (curr != NULL)
	{
		printf("%d      ", curr->data); 
		curr = curr->link;
	}
	printf("\n===============================\n"); 
}

int main(void)
{
	TStack* h = createHead(); 
	push(h, 10); 
	push(h, 20); 
	push(h, 30); 
	push(h, 40); 

	printStack(h); 

	pop(h); 
	printStack(h); 

	return 0; 
}
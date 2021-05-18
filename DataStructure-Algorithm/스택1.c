#include <stdio.h>
#include <stdbool.h>
#define STACK_SZ	3   // �� ���ڸ� �߰��ϸ� 3���� �ٲ��ν� �ض� 

//#define TRUE	1    -----> <stdbool.h>�� ���� !!
//#define FALSE	2

// ���� üũ  
int isEmpty();    
// ��ȭ üũ  
int isFull();

// ���ÿ� �Է� 
void push(int); 
// ���ÿ��� ��� 
int pop(); 
// ������ ���� Ȯ�� 
int peek(); 

// ��� 
void printStack(); 

int stack[STACK_SZ]; 
int top = -1; // ���� ������ ��ġ �ʱ�ȭ, �Ѱ��� ���ö� ���� +1 


int main(void)
{
	push(10); 
	push(11); 
	push(12); 
	push(13); 

	pop(); 
	
	printStack(); 


	return 0; 
}

int isEmpty()
{
	if (top <= -1) return true;
	else return false; 
}
int isFull()
{
	if (top >= STACK_SZ - 1) return true;
	else return false; 
}
void push(int data)
{
	if (isFull()) {
		printf("STACK overflow!!\n"); 
		return; 
	}
	else {
		stack[++top] = data; 
	}
}
int pop()
{
	if (isEmpty()) {
		printf("STACK underflow!!\n");
		return; 
	}
	else {
		return stack[top];
		top--; 
		// == stack[top--];
	}
}
int peek()
{
	if (isEmpty()) {
		printf("STACK underflow!!\n"); 
		return; // == exit(1); 
	}
	else {
		return stack[top]; 
	}
}
void printStack()
{
	int i; 
	if (!isEmpty()) {
		for ( i = 0; i <= top; i++){
			printf("%d    ", stack[i]); 
		}
		printf("\n"); 
	}
}

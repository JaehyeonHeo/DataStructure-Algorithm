#include <stdio.h>
#include <stdbool.h>
#define SIZE 6

int isEmpty(); 
int isFull(); 
void enQueue(int); // 큐에 삽입 
int deQueue();     // 큐에서 삭제  

int rear = 0;   // 입구
int front = 0;  // 출구 
int queue[SIZE]; 


int main(void)
{
	enQueue(10);
	enQueue(20); 
	enQueue(30); 
	printf("%d\n", deQueue()); 
	printf("%d\n", deQueue()); 

	return 0; 
}

int isEmpty() 
{
	if (rear == front) return true;
	else return false; 
}

int isFull()
{
	if (front == (rear + 1) % SIZE) return true;  // 6으로 나눈 나머지 계산으로 큐인덱스 계산 
	else return false; 
}

void enQueue(int data)
{
	if (isFull()) {
		printf("QUEUE overflow!!\n");
		return;
	}
	else {
		rear = rear % SIZE; 
		queue[rear] = data; 
		rear++; 
	}

}
int deQueue()
{
	if (isEmpty()) {
		printf("Queue underflow!\n");
		return; 
	}
	else {
		return queue[front++ % SIZE]; 
	}
}
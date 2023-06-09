#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10

typedef struct Queue{
	int values[CAPACITY];
	int tail;
	int head;
	int count;
} Queue;

Queue *initialize_queue(){
	// Allocate memory for the queue structure
	Queue *queue = malloc(sizeof(Queue)); 
	// Initialize head, tail, and count to 0
	queue->head = 0;
	queue->tail = 0;
	queue->count = 0;
	return queue;
}

int isFull(Queue *queue){
	// Check if the count of elements is equal to the capacity
	if(queue->count == CAPACITY){
		return 1; // Queue is full
	}
	else{
		return 0; // Queue is not full
	}
}

int isEmpty(Queue *queue){
	// Check if the count of elements is 0
	if(queue->count == 0){
		return 1; // Queue is empty
	}
	return 0; // Queue is not empty
}

void enqueue(Queue *queue, int value){
	// Check if the queue is not full
	if(!isFull(queue)){
		// Add the value to the tail of the queue
		queue->values[queue->tail % CAPACITY] = value;
		// Update the tail index by wrapping around the capacity
		queue->tail = (queue->tail + 1) % CAPACITY;
		// Increment the count of elements in the queue
		queue->count++;
	}
}

int dequeue(Queue *queue){
	int result = -1; // Default result if the queue is empty
	// Check if the queue is not empty
	if(!isEmpty(queue)){
		// Get the value at the head of the queue
		result = queue->values[queue->head % CAPACITY];
		// Set the value at the head to 0 (optional, for clarity)
		queue->values[queue->head % CAPACITY] = 0;
		// Update the head index by wrapping around the capacity
		queue->head = (queue->head + 1) % CAPACITY;
		// Decrement the count of elements in the queue
		queue->count--;
	}
	return result;
}

void show_queue(Queue *queue){
	// Iterate over the queue and print its values
	int count2 = 0;
	for(int i = queue->head; count2 < queue->count; i++){
		printf("%d ", queue->values[i % CAPACITY]);
		count2++;
	}
	printf("\n");
}

int main(void) {
	Queue *queue = initialize_queue();
	for(int i = 0; i < 100; i++){
		if(i % 3 == 0){
			dequeue(queue); // Dequeue if i is divisible by 3
		}else{
			enqueue(queue, i); // Enqueue otherwise
		}
		show_queue(queue);
	}
	return 0;
}

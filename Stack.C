#include <stdio.h>
#include <stdlib.h>

#define VALUES_SIZE 6
#define TRUE 1
#define FALSE 0


typedef struct Cell {
	int value;
	struct Cell* next;
} Cell;


typedef struct Stack {
	int size;
	Cell* top;
} Stack;


Stack* start_stack() {
	// Allocate memory for the stack structure
	Stack* stack = malloc(sizeof(Stack));
	stack->top = NULL; // Initialize the top pointer to NULL (empty stack)
	stack->size = 0; // Initialize the size to 0
	return stack;
}

int isEmpty(Stack* stack) {
	// Check if the stack is empty based on the size
	if (stack->size == 0)
		return TRUE; // Stack is empty
	else
		return FALSE; // Stack is not empty
}

int push(Stack* stack, int value) {
	// Create a new cell and set its value and next pointer
	Cell* new_cell = malloc(sizeof(Cell));
	new_cell->value = value;
	new_cell->next = stack->top;
	// Update the top pointer to point to the new cell
	stack->top = new_cell;
	// Increment the size of the stack
	stack->size++;
	return 0;
}

int pop(Stack* stack) {
	// Check if the stack is not empty
	if (!isEmpty(stack)) {
		int value = stack->top->value;
		Cell* temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
		stack->size--;
		return value;
	}
	else {
		return -1;
	}
}

void show_stack(Stack* stack) {
	printf("Top of the stack -> ");
	Cell* cell = stack->top;
	while (cell != NULL) {
		printf("%d ", cell->value);
		cell = cell->next;
	}
	printf(" <- End of the stack\n");
}

int main(void) {
	Stack* stack = start_stack();
	for (int i = 0; i < 10; i++) {
		printf("Pushing: %d\n", i);
		push(stack, i);
	}
	show_stack(stack);
	for (int i = 0; i <= 10; i++) {
		printf("Popping: %d\n", pop(stack));
		show_stack(stack);
	}
	return 0;
}

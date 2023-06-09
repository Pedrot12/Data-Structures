#include <stdio.h>
#include <stdlib.h>

#define hash_size 7

typedef struct Cell {
	int value;
	struct Cell* next;
} Cell;

typedef struct {
	Cell* start;
} List;

typedef struct {
	List* table[hash_size];
} Hash;

Hash* start_hash() {
	// Allocate memory for the hash structure
	Hash* hash = malloc(sizeof(Hash));
	// Initialize each list in the hash table
	for (int i = 0; i < hash_size; i++) {
		// Allocate memory for the list
		List* list = malloc(sizeof(List));
		// Set the start of the list to NULL (empty)
		list->start = NULL;
		// Assign the list to the hash table
		hash->table[i] = list;
	}
	// Return the initialized hash
	return hash;
}

void insert_hash(Hash* hash, int value) {
	// Allocate memory for a new cell
	Cell* new_cell = malloc(sizeof(Cell));
	// Set the value of the cell
	new_cell->value = value;
	// Set the next pointer of the cell to NULL
	new_cell->next = NULL;
	// Calculate the index for the value in the hash table
	int index = value % hash_size;
	// Check if the list at the index is empty
	if (hash->table[index]->start == NULL) {
		// If the list is empty, set the start to the new cell
		hash->table[index]->start = new_cell;
	} else {
		// If the list is not empty, set the next pointer of the new cell
		// to the current start of the list and update the start to the new cell
		new_cell->next = hash->table[index]->start;
		hash->table[index]->start = new_cell;
	}
}

void remove_hash(Hash* hash, int value) {
	// Calculate the index for the value in the hash table
	int index = value % hash_size;
	// Get the start of the list at the index
	Cell* current = hash->table[index]->start;
	// Keep track of the previous cell
	Cell* previous = NULL;
	// Traverse the list to find the cell with the specified value
	while (current != NULL && current->value != value) {
		previous = current;
		current = current->next;
	}
	// If the current cell is NULL, the value was not found in the list
	if (current == NULL) {
		return;
	} else {
		// If the previous cell is NULL, the current cell is the start of the list
		if (previous == NULL) {
			// Update the start of the list to the next cell
			hash->table[index]->start = current->next;
			// Free the memory of the current cell
			free(current);
		} else {
			// If the next cell is NULL, the current cell is the last cell in the list
			if (current->next == NULL) {
				// Set the next pointer of the previous cell to NULL
				previous->next = NULL;
				// Free the memory of the current cell
				free(current);
			} else {
				// If the current cell is in the middle of the list,
				// set the next pointer of the previous cell to the next cell
				previous->next = current->next;
				// Free the memory of the current cell
				free(current);
			}
		}
	}
}

void print_hash(Hash* hash) {
	printf("---------------------\n");
	// Iterate over each list in the hash table
	for (int i = 0; i < hash_size; i++) {
		printf("%d -> ", i);
		// Get the start of the current list
		Cell* current = hash->table[i]->start;
		// Traverse the list and print the values
		while (current != NULL) {
			printf("%d ", current->value);
			current = current->next;
		}
		printf("\n");
	}
	printf("---------------------\n");
	printf("\n");
}

int main(void) {
	int values[] = {190, 322, 172, 89, 13, 4, 769, 61, 15, 76, 97, 28, 80, 76, 88};
	int size = sizeof(values) / sizeof(int);
	Hash* hash = start_hash();
	// Insert values into the hash table
	for (int i = 0; i < size; i++) {
		insert_hash(hash, values[i]);
	}
	// Print the initial hash table
	print_hash(hash);
	// Remove values from the hash table
	for (int i = 5; i < 10; i++) {
		remove_hash(hash, values[i]);
	}
	// Print the hash table after removal
	print_hash(hash);
	// Insert more values into the hash table
	for (int i = 3; i < 7; i++) {
		insert_hash(hash, values[i]);
	}
	// Print the hash table after insertion
	print_hash(hash);
	// Remove more values from the hash table
	for (int i = 10; i < 15; i++) {
		remove_hash(hash, values[i]);
	}
	// Print the final hash table
	print_hash(hash);
	return 0;
}

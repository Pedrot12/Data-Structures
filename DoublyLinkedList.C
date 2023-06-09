#include <stdio.h>
#include <stdlib.h>

typedef struct Cell{
  struct Cell *previous;
  struct Cell *next;
  int value;
} Cell;

typedef struct DoublyLinkedList{
  Cell *first;
  int quantity;
} DoublyLinkedList;

// Function to initialize an empty doubly linked list and return it
DoublyLinkedList *initialize_list(){
  DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
  list->first = NULL;
  list->quantity = 0;
  return list;
}

// Function to initialize a new cell with a given value and return it
Cell *initialize_cell(int value){
  Cell *cell = malloc(sizeof(Cell));
  cell->previous = NULL;
  cell->next = NULL;
  cell->value = value;
  return cell;
}

// Function to insert a new cell with a given value into the list
void insert(DoublyLinkedList *list, int value){
  Cell *newCell = initialize_cell(value);
  if(list->quantity == 0){
    list->first = newCell;
  }else{
    Cell *current = list->first;
    Cell *previous = NULL;
    while(current != NULL && current->value <= value){
    previous = current;
    current = current->next;
  }
  if(previous == NULL && current != NULL){
    newCell->next = current;
    current->previous = newCell;
    list->first = newCell;
  }else{
  if(current == NULL && previous != NULL){
    previous->next = newCell;
    newCell->previous = previous;
  }else{
    previous->next = newCell;
    newCell->previous = previous;
    newCell->next = current;
    current->previous = newCell;
  }
  }
  }
  list->quantity++;
}

// Function to print the values in the doubly linked list
void print(DoublyLinkedList *list){
  Cell *current = list->first;
  while(current != NULL){
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

// Function to search for a cell with a given value in the doubly linked list and return it
Cell *search(DoublyLinkedList *list, int value){
  Cell *current = list->first;
  Cell *previous = NULL;
  while(current != NULL && current->value != value){
    previous = current;
    current = current->next;
  }
  if(current == NULL){
    return NULL;
  }
  current->previous = previous;
  return current;
}

// Function to remove a cell with a given value from the doubly linked list
void remove_cell(DoublyLinkedList *list, int value){
  Cell *current = search(list, value);
  if(current == NULL){
  return;
  }
  Cell *previous = current->previous;
  if(previous == NULL){
	list->first = current->next;
	list->quantity--;
	return;
  }

  if(current->previous != NULL && current->next != NULL){
  	current = current->next;
  	previous->next = current;
  	current->previous = previous;
  	list->quantity--;
  	return;
  }
  
  if(current->next == NULL){
  	current = NULL;
  	previous->next = NULL;
  	list->quantity--;
  	return;
  }
  }

int main(void) {
  DoublyLinkedList *list = initialize_list();
  int in[] = {2, 3, 9, 6, 7, 4, 1, 8, 0, 5};
  int out[] = {0, 9, 1, 8, 5, 5, 6, 2, 3, 4, 7};
  int len_in = sizeof(in) / sizeof(int);
  int len_out = sizeof(out) / sizeof(int);
  for(int i = 0; i < len_in; i ++){
  insert(list, in[i]);
  print(list);
  }
  for(int j = 0; j < len_out; j++){
  remove_cell(list, out[j]);
  print(list);
  }
  return 0;
}

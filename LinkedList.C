#include <stdio.h>
#include <stdlib.h>

typedef struct Cell{
  int value;
  struct Cell *next;
} Cell;

typedef struct List{
  int quantity;
  Cell *first;
} List;

// Function to insert a new cell with a given value into the list
void insert(List *l, int value){
  Cell *newCell = malloc(sizeof(Cell));
  newCell->value = value;
  newCell->next = NULL;
  if(l->first == NULL){
	 l->first = newCell;
  }else{
  	Cell *current = l->first;
  	Cell *previous = NULL;
  	while(current != NULL && current->value <= value){
  		previous = current;
  		current = current->next;
  	}
  	if(previous == NULL){
  		newCell->next = l->first;
  		l->first = newCell;
  	}else{
  		if(current == NULL){
  			previous->next = newCell;
  		}else{
  			newCell->next = current;
  			previous->next = newCell;
  		}
  	}
  }
  l->quantity++;
  }

// Function to remove a cell with a given value from the list
void remove_cell(List *l, int value) {
  Cell *current = l->first;
  Cell *previous = NULL;
  while (current != NULL && current->value != value){
  previous = current;
  current = current->next;
  }
  if(current == NULL){
  return;
  }
  if(previous == NULL){
  l->first = current->next;
  free(current);
  return;
  }
  if(current->next == NULL){
  previous->next = NULL;
  free(current);
  return;
  }
  if(previous != NULL && current->next != NULL){
  previous->next = current->next;
  free(current);
  return;
  }
}

// Function to initialize a new list and return it
List *initialize_list(){
  List *l = malloc(sizeof(List));
  l->first = NULL;
  l->quantity = 0;
  return l;
}

// Function to print the values in the list
void print(List *l){
  Cell *current = l->first;
  while(current != NULL){
  printf("%d ", current->value);
  current = current->next;
  }
  printf("\n");
}

int main(void) {
  List *l = initialize_list();
  insert(l, 56);
  print(l);
  insert(l, 50);
  print(l);
  insert(l, 40);
  print(l);
  insert(l, 45);
  print(l);
  insert(l, 80);
  print(l);
  remove_cell(l, 40);
  print(l);
  remove_cell(l, 80);
  print(l);
  remove_cell(l, 50);
  print(l);
return 0;
}
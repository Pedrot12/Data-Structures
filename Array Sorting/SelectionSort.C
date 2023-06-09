#include <stdio.h>

int SelectionSort(int list[],int n){
  int min;
  int aux;
  for(int i=0;i<n-1;i++){
    min =i;
    for(int j=i+1;j<n;j++){
      if(list[j]<list[min]){
        min=j;
      }
      }
    if (list[i]!=list[min]){
      aux =list[i];
      list[i]=list[min];
      list[min]=aux;
    }
    }
  }
void PrintList(int list[], int n) {
  for(int i = 0; i < n; i++){
   printf("%d ", list[i]);
};
   printf("\n");
}

int main(void) {
  int list[] = {8,4,2,7,1,3,9,6,0,5};
  int list_size = sizeof(list)/(sizeof(int));
  SelectionSort(list, list_size);
  PrintList(list,list_size);
  return 0;
}
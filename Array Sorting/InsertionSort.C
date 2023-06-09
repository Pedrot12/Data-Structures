#include <stdio.h>

void InsertionSort(int list[], int n){
  int key;
  int i;
  for(int j=1;j<n;j++){
    key = list[j];
    i = j-1;
    while(i>=0 && list[i]>key){
      list[i+1]=list[i];
      i = i-1;
    }
    list[i+1]=key;
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
  InsertionSort(list, list_size);
  PrintList(list,list_size);
  return 0;
}
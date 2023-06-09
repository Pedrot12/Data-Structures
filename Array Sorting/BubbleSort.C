#include <stdio.h>

void BubbleSort(int list[],int n){
  int aux;
  for(int i =0;i<n;i++){
    for(int j = n-1;j>i;j--){
      if(list[j]<list[j-1]){
        aux = list[j];
        list[j]= list[j-1];   
        list[j-1]=aux;
      }
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
  BubbleSort(list, list_size);
  PrintList(list,list_size);
  return 0;
}

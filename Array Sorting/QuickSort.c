#include <stdio.h>


void QuickSort(int list[], int start, int end,int list_size){
    int pivot, left, right, center, aux;
    left = start;
    right = end;

    center = (int)((left + right) / 2);
    pivot = list[center];
    while(right > left){
        while(list[left] < pivot){
            left = left + 1;
        }
        while(list[right] > pivot){
            right = right - 1;
        }
        if(left <= right){
            aux = list[left];
            list[left] = list[right];
            list[right] = aux;
            left = left + 1;
            right = right - 1;
        }
    }
    if(start < right){
        QuickSort(list, start, right,list_size);
    }
    if(left < end){
        QuickSort(list, left, end,list_size);
    }
}

void PrintList(int list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main(){

    int list[] = { 8, 4, 2, 7, 1, 3, 9, 6, 0, 5 };
    int list_size = sizeof(list) / sizeof(int);
    QuickSort(list, 0, list_size-1,list_size);
    PrintList(list,list_size);

    return 0;
}

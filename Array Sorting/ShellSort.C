#include <stdio.h>

void ShellSort(int list[],int list_size){
    int h = 1;

    while(h < list_size){
        h = 3 * h + 1;
    }
    while(h > 1){
        h = h / 3;

        for(int i = h; i < list_size; i++){
            int n = list[i];
            int j = i - h;

            while((j >= 0) && (n < list[j])){
                list[j + h] = list[j];
                j = j - h;
            }
            list[j + h] = n;
        }
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
    ShellSort(list,list_size);
    PrintList(list,list_size);

    return 0;
}

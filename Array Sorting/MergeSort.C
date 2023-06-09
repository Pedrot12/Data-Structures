#include <stdio.h>

void merge(int list[], int left, int right, int center) {
    int n1 = center - left + 1;
    int n2 = right - center;
    int list_left[n1], list_right[n2];
    int i, j, k;

    for (i = 0; i < n1; i++) {
        list_left[i] = list[left + i];
    }

    for (j = 0; j < n2; j++) {
        list_right[j] = list[center + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (list_left[i] <= list_right[j]) {
            list[k] = list_left[i];
            i++;
        } else {
            list[k] = list_right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        list[k] = list_left[i];
        i++;
        k++;
    }
    while (j < n2) {
        list[k] = list_right[j];
        j++;
        k++;
    }
}

void MergeSort(int list[], int left, int right) {
    if (left < right) {
        int center = left + (right - left) / 2;

        MergeSort(list, left, center);
        MergeSort(list, center + 1, right);
        merge(list, left, right, center);
    }
}

void PrintList(int list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[] = { 8, 4, 2, 7, 1, 3, 9, 6, 0, 5 };
    int list_size = sizeof(list) / sizeof(int);
    MergeSort(list, 0, list_size - 1);
    PrintList(list, list_size);

    return 0;
}

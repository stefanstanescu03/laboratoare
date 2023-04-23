#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int *arr, int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++) 
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

// O(n^2) - worst case (deja sortat, sortat invers, totate el egale)
// O(nlogn) - best case
// Nu e stabil

void quickSort(int *arr, int low, int high) {
    
    if(low < high) {
        int q = partition(arr, low, high);

        quickSort(arr, low, q - 1);
        quickSort(arr, q + 1, high);
    }

}

int main() {

    int arr[8] = {54, 23, 99, 43, 545, 8, 12, 32};

    quickSort(arr, 0, 7);

    for(int i = 0; i < 8; i++)
        printf("%d ", arr[i]);

    puts("\n");

    return 0;
}
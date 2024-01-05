#include <stdio.h>

int quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = low; 
        int pivot = arr[high];
        for (int i = low; i < high; i++) {
            if (arr[i] <= pivot) {
                
                int temp = arr[i];
                arr[i] = arr[pivotIndex];
                arr[pivotIndex] = temp;
                pivotIndex++;
            }
        }

        
        int temp = arr[high];
        arr[high] = arr[pivotIndex];
        arr[pivotIndex] = temp;

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int matrix[7][8] = {
        {77, 18, 11, 28, 77, 46, 25, 70},
        {94, 29, 48, 83, 62, 48, 84, 32},
        {54, 18, 99, 83, 60, 25, 57, 72},
        {56, 94, 67, 97, 39, 39, 37, 36},
        {29, 74, 72, 80, 97, 85, 70, 11},
        {65, 19, 19, 53, 82, 51, 70, 48},
        {52, 35, 32, 24, 59, 35, 35, 42}
    };

    printf("Original matrix:\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    
    for (int i = 0; i < 7; i++) {
        quicksort(matrix[i], 0, 7);
    }

    printf("\nSorted matrix:\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}



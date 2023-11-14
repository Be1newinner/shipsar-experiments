#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, j, key;
    int swaps = 0, comparisons = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Compare the key with elements to its left
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }

        // Insert the key in its correct position
        arr[j + 1] = key;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of swaps: %d\n", swaps);
    printf("Number of comparisons: %d\n", comparisons);
}

int main() {
    int arr[] = {10, 25, 86, 1, 16, 95, 37, 56, 5, 15, 20, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    return 0;
}


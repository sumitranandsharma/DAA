#include <stdio.h>
int splitArray(int arr[], int start, int end) {
    int key = arr[end];
    int pos = start - 1;
    int swap, idx;

    for (idx = start; idx < end; idx++) {
        if (arr[idx] <= key) {
            pos++;
            swap = arr[pos];
            arr[pos] = arr[idx];
            arr[idx] = swap;
        }
    }
    swap = arr[pos + 1];
    arr[pos + 1] = arr[end];
    arr[end] = swap;

    return pos + 1;
}
void sortQuick(int arr[], int start, int end) {
    if (start < end) {
        int pivotIndex = splitArray(arr, start, end);
        sortQuick(arr, start, pivotIndex - 1);
        sortQuick(arr, pivotIndex + 1, end);
    }
}
int main() {
    int size, data[50], i;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter elements:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &data[i]);

    sortQuick(data, 0, size - 1);

    printf("Sorted array:\n");
    for (i = 0; i < size; i++)
        printf("%d ", data[i]);

    return 0;
}

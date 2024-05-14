#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void append(int arr[], int* size, int value) {
    if (*size < MAX_SIZE) {
        arr[*size] = value;
        (*size)++;
    }
}

int pop(int arr[], int* size) {
    if (*size > 0) {
        int popped = arr[*size - 1];
        (*size)--;
        return popped;
    }
    return -1; 
}

void insert(int arr[], int* size, int value, int position) {
    if (*size >= MAX_SIZE) {
        return; 
    }
    if (position < 0 || position > *size) {
        return; 
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
}

void removeValue(int arr[], int* size, int value) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == value && !found) {
            found = 1;
        }
        if (found && i + 1 < *size) {
            arr[i] = arr[i + 1];
        }
    }
    if (found) {
        (*size)--;
    }
}

void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int count(int arr[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

int indexOf(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    append(arr, &size, 5);
    append(arr, &size, 3);
    append(arr, &size, 7);

    printf("Count of 3: %d\n", count(arr, size, 3));
    printf("Index of 7: %d\n", indexOf(arr, size, 7));

    insert(arr, &size, 2, 1);
    printf("Lista com inserção: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Popped element: %d\n", pop(arr, &size)); 

    printf("Lista com pop: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    removeValue(arr, &size, 2); 
    printf("Lista com remoção: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    reverse(arr, size);
    printf("Lista com reversão: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    sort(arr, size);
    printf("Lista com ordenação: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

}
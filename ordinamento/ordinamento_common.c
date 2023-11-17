#include <stdio.h>
#include "ordinamento_common.h"

int arr[] = {3, 1, 6, 2, 8, 10, 8, 15, 0, 7};

int max() {
    int max = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

void printArray() {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printGivenArray(int *data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void scambia(int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;

    printf("%d <-> %d\n", arr[i], tmp);
}

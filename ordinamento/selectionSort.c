#include "ordinamento_common.c"

void selectionSort();

void selectionSort() {
    for (int k = 0; k < N - 1; k++) {
        printArray(arr, 10);

        int min = k;
        for (int j = k + 1; j < N; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        scambia(min, k);
    }
}

int main(void) {
    selectionSort();
    printArray();

    return 0;
}

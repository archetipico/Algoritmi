#include "ordinamento_common.c"

void insertionSort();

void insertionSort() {
    for (int k = 1; k < N; k++) {
        printArray();

        int x = arr[k];
        int j = k - 1;
        while (j >= 0 && arr[j] > x) {
            scambia(j + 1, j);
            j--;
        }

        arr[j+1] = x;
    }
}

int main(void) {
    insertionSort();
    printArray();

    return 0;
}

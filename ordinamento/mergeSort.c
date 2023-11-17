#include "ordinamento_common.c"

void merge(int *arr, int i, int m, int f, int *aux);
void mergeSort(int *arr, int i, int f, int *aux);

void merge(int *arr, int i, int m, int f, int *aux) {
    int i_1 = i;
    int i_2 = m;
    int k = 0;

    while (i_1 < m && i_2 < f) {
        if (arr[i_1] <= arr[i_2]) {
            aux[k] = arr[i_1];
            i_1++;
        } else {
            aux[k] = arr[i_2];
            i_2++;
        }

        k++;
    }

    if (i_1 < m) {
        for (int j = i_1; j < m; j++) {
            aux[k] = arr[j];
            k++;
        }
    } else {
        for (int j = i_2; j < f; j++) {
            aux[k] = arr[j];
            k++;
        }
    }

    for (k = 0; k < f - i; k++) {
        arr[i+k] = aux[k];
    }

    printArray();
}

void mergeSort(int *arr, int i, int f, int *aux) {
    if (f - i > 1) {
        int m = (i + f) / 2;

        mergeSort(arr, i, m, aux);
        mergeSort(arr, m, f, aux);
        merge(arr, i, m, f, aux);
    }
}

int main(void) {
    printArray();

    int aux[N];
    mergeSort(arr, 0, N, aux);

    return 0;
}

#include "ordinamento_common.c"
#include "ordinamento_common.h"

void integerSort(int b);

void integerSort(int b) {
    int aux[b];

    for (int i = 0; i < b; i++) {
        aux[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        int x = arr[i];
        aux[x]++;
    }

    int j = 0;

    for (int i = 0; i < b; i++) {
        while (aux[i] > 0) {
            printArray();
            printGivenArray(aux, b);
            printf("\n");

            arr[j] = i;
            aux[i]--;
            j++;
        }
    }

    printArray();
    printGivenArray(aux, b);
}

int main(void) {
    integerSort(max() + 1);

    return 0;
}

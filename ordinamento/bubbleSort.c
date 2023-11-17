#include "ordinamento_common.c"

void bubbleSort();

// Knuth
void bubbleSort() {
    int primoInOrdine = N;
    int t = 0;

    do {
        printArray();
        t = 0;

        for (int j = 1; j < primoInOrdine; j++) {
            if (arr[j] < arr[j-1]) {
                scambia(j-1, j);
                t = j;
            }
        }

        primoInOrdine = t;
    } while (t > 0);
}

int main(void) {
    bubbleSort();

    return 0;
}

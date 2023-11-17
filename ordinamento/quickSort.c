#include "ordinamento_common.c"

int partiziona(int i, int f);
void quickSort(int i, int f);

int partiziona(int i, int f) {
    printArray();

    int perno = arr[i];
    int sx = i;
    int dx = f;

    while (sx < dx) {
        do {
            dx--;
        } while (arr[dx] > perno);

        do {
            sx++;
        } while ( sx < dx && arr[sx] <= perno);

        if (sx < dx) {
            scambia(sx, dx);
        }
    }

    scambia(i, dx);

    return dx;
}

void quickSort(int i, int f) {
    while (f - i > 1) {
        int m = partiziona(i, f);

        if (m - 1 < f - m) {
            quickSort(i, m);
            i = m + 1;
        } else {
            quickSort(m + 1, f);
            f = m;
        }
    }
}

int main(void) {
    quickSort(0, N);
    printArray();

    return 0;
}

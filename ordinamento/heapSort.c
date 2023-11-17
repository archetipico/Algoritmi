#include "ordinamento_common.c"

void makeHeap();
void risistema(int r, int l);

void makeHeap() {
    for (int i = (int) (N / 2); i >= 0; i-- ) {
        risistema(i, N);
    }
}

void risistema(int r, int l) {
    int v = r;
    int x = arr[v];
    int daCollocare = 1;

    do {
        if ((2 * v) + 1 >= l) {
            daCollocare = 0;
        } else {
            int u = (2 * v) + 1;

            if (u + 1 < l && arr[u+1] > arr[u]) {
                u++;
            }

            if (arr[u] > x) {
                arr[v] = arr[u];
                v = u;
            } else {
                daCollocare = 0;
            }
        }
    } while (daCollocare);
    arr[v] = x;
}

void heapSort() {
    makeHeap();
    for (int l = N - 1; l >= 1; l--) {
        printArray();
        scambia(0, l);
        risistema(0, l);
    }
}

int main(void) {
    heapSort();
    printArray();

    return 0;
}

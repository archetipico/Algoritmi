#include <stdio.h>

int ricercaRic(int *arr, int sx, int dx, int x);

int ricercaRic(int *arr, int sx, int dx, int x) {
    if (dx <= sx) {
        return -1;
    } else {
        int m = (sx + dx) / 2;
        if (x == arr[m]) {
            return m;
        } else if (x < arr[m]) {
            return ricercaRic(arr, sx, m, x);
        } else {
            return ricercaRic(arr, m + 1, dx, x);
        }
    }
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x;

    printf("Inserisci un numero: ");
    scanf("%d", &x);

    int pos = ricercaRic(arr, 0, 10, x);
    printf("%d\n", pos);

    return 0;
}

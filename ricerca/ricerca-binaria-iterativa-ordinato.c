#include <stdio.h>

int ricercaBin(int *arr, int n, int x);

int ricercaBin(int *arr, int n, int x) {
    int sx = 0;
    int dx = n;
    int pos = -1;
    while (sx < dx && pos == -1) {
        int m = (sx + dx) / 2;
        if (x == arr[m]) {
            pos = m;
        } else if (x < arr[m]) {
            dx = m;
        } else {
            sx = m + 1;
        }
    }

    return pos;
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x;

    printf("Inserisci un numero: ");
    scanf("%d", &x);

    int pos = ricercaBin(arr, 10, x);
    printf("%d\n", pos);

    return 0;
}

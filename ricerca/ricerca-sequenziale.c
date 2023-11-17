#include <stdio.h>

int ricercaSequenziale(int *arr, int n, int x);

int ricercaSequenziale(int *arr, int n, int x) {
    int i = n - 1;
    while (i >= 0 && arr[i] != x) {
        i--;
    }

    return i;
}

int main(void) {
    int arr[] = {3, 5, 1, 6, 7, 1, 9, 2, 2, 5};
    int x;

    printf("Inserisci un numero: ");
    scanf("%d", &x);

    int pos = ricercaSequenziale(arr, 10, x);
    printf("%d\n", pos);

    return 0;
}

#include <stdlib.h>
#include <stdio.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) {
    int x_min = 0;
    int x_max = (int) rows;
    int y_min = 0;
    int y_max = (int) cols;

    *outsz = x_max * y_max;
    int n = x_max * y_max;

    int i = 0;
    int *array = malloc(sizeof(int) * n);

    int x = 0;
    int y = 0;

    while (n > 0) {
        while (x < x_max) {
            array[i++] = mx[y][x];
            x++;
            n--;
        }
        if (n <= 0) { break; }
        x--;
        y++;
        y_min++;
        while (y < y_max) {
            array[i++] = mx[y][x];
            y++;
            n--;
        }
        if (n <= 0) { break; }
        y--;
        x--;
        x_max--;
        while (x > x_min) {
            array[i++] = mx[y][x];
            x--;
            n--;
        }
        if (n <= 0) { break; }
        y_max--;
        while (y > y_min) {
            array[i++] = mx[y][x];
            y--;
            n--;
        }
        if (n <= 0) { break; }
        x_min++;
    }
    return (int *) (array);
}

int main() {
    int *a[] = {
            (int[]) {1, 2, 3, 4, 5},
            (int[]) {16, 17, 18, 19, 6},
            (int[]) {15, 24, 25, 20, 7},
            (int[]) {14, 23, 22, 21, 8},
            (int[]) {13, 12, 11, 10, 9}};
    size_t result;
    snail(&result, (const int **) a, 5, 5);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createRandomArray(int n, int min, int max) {
    int* v = malloc(sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < n; i++) v[i] = rand() % (max + 1 - min) + min;
    return v;
}

// int main() {
//     int *array;
//     array = createRandomArray(5, 0, 10);

//     for(int i = 0; i < 5; i++) printf("%d\n", array[i]);
// }
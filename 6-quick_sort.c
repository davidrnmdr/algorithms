#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void quickSort(int v[], int from, int to) {
  if (from < to) {
    int pivot = to;
    int j = from, i = from - 1;

    for(j = from; j < to; j++) {
        if(v[j] <= pivot) {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&pivot, v + i);
    i++;
    quickSort(v, from, i - 1);
    quickSort(v, i + 1, to);
  }
  
}

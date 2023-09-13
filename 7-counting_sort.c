#include <stdio.h>
#include <stdlib.h>

void countingSort(int v[], int n, int maxElement) {
    int temp[n];


    int c[maxElement];
    for(int i = 0; i < maxElement; i++) c[i] = 0;

    for(int i = 0; i < n; i++) c[v[i]]++;

    for(int i = 0; i <= maxElement; i++) c[i] = c[i] + c[i - 1];

    for(int i = n - 1; i >= 0; i--) {
        temp[c[v[i]]] = v[i];
        c[v[i]]--;
    }

    for(int i = 0; i < n; i++) v[i] = temp[i];


}

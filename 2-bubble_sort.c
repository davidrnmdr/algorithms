#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}


void bubbleSort(int v[], int n) {
    //i for defines the lower bound of the sorted sub-array
    //therefor, the refered sub-array is the rightmost
    for(int i = n - 1; i > 0; i--) {

        //j for is used to compare sequencial elements
        for(int j = 0; j < i; j++) {

            //swaps if the first is greater than the second
            if(v[j] > v[j + 1]) swap(&v[j], &v[j + 1]);
        }
    }
}

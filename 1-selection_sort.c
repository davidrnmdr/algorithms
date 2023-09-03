#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}


void selectionSort(int v[], int n){
    //i for is used to move the boundary of the unsorted sub-array
    for(int i = 0; i < n - 1; i++){

        //j for is used to travel all the elements of that unsorted sub-array, from the second
        for(int j = i + 1; j < n; j++){

            //if the element is less than the current min, swap them
            if(v[j] < v[i]) swap(&v[j], &v[i]);
        }
    }
}

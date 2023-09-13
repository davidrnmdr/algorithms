#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void quickSort(int v[], int from, int to) {
  //if the array is non-empty  
  if (from < to) {
    //set the pivot as the last element
    int pivot = to;
    //set j as the first element and i one less than j
    int j = from, i = from - 1;


    for(j = from; j < to; j++) {
        //if the current element is less than or equal pivot
        if(v[j] <= pivot) {
            //increment i and swap the elements at i and j
            i++;
            swap(&v[i], &v[j]);
        }
    }

    //now i contains the right position for the pivot
    //swap the pivot with the element at i
    swap(&pivot, v + i);
    //now the pivot is in the right spot
    //wich means that all elements to the left of it are <= it
    //and all elements to the right of it are >= it

    i++;

    //call quick sort in each sub-array, with the bounding being the element at i
    quickSort(v, from, i - 1);
    quickSort(v, i + 1, to);
  }
  
}

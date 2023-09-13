#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void maxHeapify(int *v, int i, int n) {
    int l = 2 * i + 1, r = 2 * i + 2, max = i;

    //check if we are still inside the array and if the left child is greather then parent
    //if so, max receives the index of the greather between parent and left
    if(l < n && v[l] > v[max]) {
        max = l;
    }

    //check if we are still inside the array and if the right child is greather than the winner of the previous step
    //if so, max receives the index of the greather between parent, left and right child
    if(r < n && v[r] > v[max]) {
        max = r;
    }

    //if there was a change in max, swap the parent with the current max
    //and apply maxHeapify again in the position of the swaped child
    //because now it may be less than its own childs
    if(max != i) {
        swap(&v[i], &v[max]);
        maxHeapify(v, max, n);
    }
}

void buildMaxHeap(int v[], int n) {
    for(int j = n/2 - 1; j >= 0; j--) {
        maxHeapify(v, j, n);
    }
}

void heapSort(int v[], int n) {
    //first, build a heap from the passed array
    buildMaxHeap(v, n);

    //starts from the last element to the first, swapping in order to
    //bring the root of the heap to the last position in the array
    for(int i = n - 1; i >= 0; i--) {
        swap(&v[i], &v[0]);

        //then, insures that the array v, from the index 0 with size i
        //still a max heap
        maxHeapify(v, 0, i);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int v[], int n) {
    int i, j, aux;

    //i for is used to go through every element
    for(i = 1; i < n; i++) {

        //initializes aux as the current element and j to the previous
        aux = v[i];
        j = i - 1;

        /*if j is not bellow 0 and the j-th element is greater than
        the i-th (now stored in aux), pass the former to the right*/
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }

        //place the aux in the space left by the right shifts
        //(if no shifts were made, it just go back the it's place)
        v[j + 1] = aux;
    }
}

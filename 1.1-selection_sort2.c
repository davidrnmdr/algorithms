#include <stdio.h>
#include <stdlib.h>

void selectionSort(int v[], int n){
    //goes through all the array, except the last item
    for(int i = 0; i < n - 1; i++){

        //initializes the first item as the min
        int minPos = i;

        //goes from the following element to the end of the array
        for(int j = i + 1; j < n; j++){

            //check if the j-th element is less than the minPos-th
            //if so, the new minPos becomes j
            if(v[j] < v[minPos]) minPos = j;
        }

        //if minPos was updated, perform a swap
        if(minPos != i){
            int aux = v[i]; 
            v[i] = v[minPos];
            v[minPos] = aux;
        }
    }
}

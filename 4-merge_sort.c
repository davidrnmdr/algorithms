#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int l, int r, int separator) {
    //create two temp arrays
    int nl = separator - l + 1;
    int nr = r - separator;
    int L[nl], R[nr];

    //copy elements to the left part
    for(int i = 0; i < nl; i++) L[i] = v[l + i];

    //copy elements to the right part
    for(int j = 0; j < nr; j++) R[j] = v[separator + 1 + j];

    //fill the big array in order with elements of the two sub arrays
    int il = 0, ir = 0, iv = l;
    while(il < nl && ir < nr) {
        if(L[il] <= R[ir]) {
            v[iv] = L[il];
            il++;
        } else {
            v[iv] = R[ir];
            ir++;
        }
        iv++;
    }

    //if there are remaining elements in the left, copy it
    while(il < nl) {
        v[iv] = L[il];
        iv++; il++;
    }

    while( ir < nr) {
        v[iv] = R[ir];
        iv++; ir++;
    }
}

void mergeSort(int v[], int l, int r) {
    if(l < r) {
        //create a separator between the two parts
        int separator = (r + l) / 2;

        //recursive call on the left part
        mergeSort(v, l, separator);

        //recursive call on the right part
        mergeSort(v, separator + 1, r - 1);

        //merge the two, already sorted, parts into one sorted big array
        merge(v, l, r, separator);
    }
    
}

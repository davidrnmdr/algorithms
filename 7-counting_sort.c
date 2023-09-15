#include <stdio.h>
#include <stdlib.h>

void countingSort(int v[], int n, int maxElement) {
    //create a temp array to contain the output
    int temp[n];

    //create a counting array
    //each position corresponds to a number in the interval [0,maxElement]
    int c[maxElement];
    for(int i = 0; i < maxElement; i++) c[i] = 0;

    //now c[k] contains the frequency of k in the input array
    for(int i = 0; i < n; i++) c[v[i]]++;

    //cumullative sum, now c[k] contains the number of elements >= k
    for(int i = 0; i <= maxElement; i++) c[i] = c[i] + c[i - 1];

    //backwards access the output array
    for(int i = n - 1; i >= 0; i--) {

        //puts the v[i] element on the c[v[i]] position
        //that is, in a position in which no other element
        //on the left side is > than v[i]
        temp[c[v[i]]] = v[i];

        //decrements c[v[i]], because one of those elements just got
        //correctly inserted on the output array
        c[v[i]]--;
    }

    //copy the output array to the passed one
    for(int i = 0; i < n; i++) v[i] = temp[i];


}

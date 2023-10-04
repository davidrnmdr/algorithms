#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *v, int key, int n) {
    int left = 0;
    int right = n;
    int mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(v[mid] == key) return mid;
        if(v[mid] <= key) {
            left = mid + 1;
        } else right = mid - 1;
    }
    return 0;
}
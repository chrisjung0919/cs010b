#include "minFunc.h"
const int * min(const int arr[], int n) {

    if (n == 0) {
        return nullptr;
    }

    if(n == 1){
        return &arr[0];
    }

    const int* minRest = min(arr + 1, n - 1);
    
    if (*arr < *minRest) {
        return &arr[0];
    } else {
        return minRest;
    }

}
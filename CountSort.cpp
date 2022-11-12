#include "Sort.h"
#include <cstring>

void CountSort::sort(int *arr, int size) {
    int max = 1000;
    int* countArr = new int [max+1]{0};

    for(int i=0;i<size;i++){
        countArr[arr[i]] ++;
    }
    int cumulate = 0;
    for(int i=1;i<=max;i++){
        for(int j=0;j<countArr[i];j++){
            arr[cumulate] = i;
            cumulate++;
        }
    }
    delete [] countArr;
}


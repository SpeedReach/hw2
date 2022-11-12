#include "Sort.h"

void hPartition(int *arr,int low,int high){
    int i= low-1;
    int j = high+1;
    int pivot = arr[rand()%(high-low+1)+low];


    while (true){
        do {
            i++;
        }
        while (arr[i] < pivot);
        do{
            j--;
        }
        while (arr[j] > pivot);

        if(i>=j) break;
        swap(arr[i],arr[j]);
    }

    if(j-low > 0)
        hPartition(arr,low,j);
    if(high-j-1 > 0)
        hPartition(arr,j+1,high);
}

void HQuickSort::sort(int *arr, int size) {
    hPartition(arr,0,size-1);
}
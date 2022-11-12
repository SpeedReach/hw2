#include "Sort.h"
#include "cstdlib"



void partition(int *arr,int low,int high){
    int len = high-low+1;
    swap(arr[low+rand()%len],arr[high]);
    int pivot = arr[high];

    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);

    /**
    cout <<"i+1=" << i+1<<endl;
    for(int i=low;i<=high;i++){
        cout << arr[i] <<" ";
    }
    cout <<endl;
     */

    if(i-low>0)
        partition(arr,low,i);
    if(high-i-1>0)
        partition(arr,i+1,high);
}

void LQuickSort::sort(int *arr, int size) {
    partition(arr,0,size-1);
}
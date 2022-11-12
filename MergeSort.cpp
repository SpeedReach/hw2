#include "Sort.h"


//   [l,e,e][m,e,e] r
//ex  3 4 5  6 7 8  9
//0 1 2 3  4 5 6 7
//1,5,7,9  2,3,5,8};
void merge(int * arr,int l,int m,int r){
    int size = r-l;
    int *newArr = new int[size];
    int index = 0;
    int lp = l,rp = m;
    while (index < size){
        if(rp >= r){
            newArr[index] = arr[lp];
            lp++;
        } else if(lp >=m){
            newArr[index] = arr[rp];
            rp++;
        } else if(arr[lp] < arr[rp]){
            newArr[index] = arr[lp];
            lp++;
        } else{
            newArr[index] = arr[rp];
            rp++;
        }
        index ++;
    }
    for(int i=0;i<size;i++){
        arr[l+i] = newArr[i];
    }
    delete[] newArr;
}

void divideThenMerge(int *arr,int left,int right){
    int p = (right-left+1)/2;
    if(p == 0) return;
    int mid = left+p;
    divideThenMerge(arr,left,mid-1);
    divideThenMerge(arr,mid,right);
    merge(arr,left,mid,right+1);
}

void MergeSort::sort(int *arr, int size) {
    divideThenMerge(arr,0,size-1);
}
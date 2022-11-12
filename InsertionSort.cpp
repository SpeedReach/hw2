#include<iostream>
#include "Sort.h"

using namespace std;


void InsertSort::sort( int *array, int size) {
    int j;
    int key;
    for(int i = 1; i<size; i++) {
        key = array[i];
        j = i;
        while(j > 0 && array[j-1]>key) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = key;
    }
}

#include<iostream>
#include "Sort.h"
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <climits>
#include "cmath"
#include <fstream>

using namespace std;

ofstream o;

void display(short int *array, int size) {
    for(int i = 0; i<size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void process(Sort& sortMethod,int arrSize){
    try {
        long averageTime = 0;
        for(int i=0;i<10;i++){
            int* arr = new int [arrSize];
            for(int j=0;j<arrSize;j++){
                arr[j] = (rand()%1000+1);
            }
            clock_t startTime = clock();
            sortMethod.sort(arr,arrSize);
            clock_t endTime = clock();
            averageTime += (long ) ((endTime-startTime)/10);
            delete[] arr;
        }
        o << sortMethod.name() << " took " << averageTime <<" ms to sort array size of "<< arrSize <<" in average" <<endl;
    }
    catch (const bad_alloc& e){
        o << "not enough memory on sort: "<<sortMethod.name()<< " with n="<< arrSize <<endl;
    }
}

void process(Sort& sort){
    for(int i=15;i<=30;i++){
        process(sort, pow(2,i));
    }
}

int main() {
    o.open("./output.txt");

    Sort* sorts[] = {
            new CountSort(),
            new MergeSort(),
            new LQuickSort(),
            new HQuickSort(),
            new ThreeWaySort(),
            new InsertSort()
    };

    for (const auto &item : sorts){
        process(*item);
    }
}
//
// Created by gomil on 2022/11/12.
//
#include "iostream"

using namespace std;


#ifndef SCHOOLHW_SORT_H
#define SCHOOLHW_SORT_H

class Sort{
public:
    virtual void sort(int* arr,int size) = 0;
    virtual string name() = 0;
    void test(){
        int arr1[20] = {};
        sort(arr1,20);
        int arr[20];
        for(int j=0;j<20;j++){
            arr[j] = (rand()%1000+1);
        }
        sort(arr,20);
        for(int i=0;i<20;i++){
            cout << arr[i]<< " ";
        }
        cout<<endl;
    }
};


class InsertSort: public Sort{
public:
    virtual void sort(int* arr,int size);
    string name(){ return "Insertion Sort"; }
};

class MergeSort: public Sort{
    virtual void sort(int* arr,int size);
    string name() { return "Merge Sort"; }
};

class CountSort: public Sort{
    void sort(int* arr,int size);
    string name() { return "Count Sort"; }
};

class LQuickSort: public Sort{
public:
    void sort(int* arr,int size);

    string name() { return "Lomuto Quick Sort"; }
};

class HQuickSort: public  Sort{
public:
    void sort(int* arr,int size);
    string name() { return "Hoare Quick Sort";}
};

class ThreeWaySort: public Sort{
public:

    void sort(int* arr,int size);
    string name() { return "Three Way Quick Sort";}
};

#endif //SCHOOLHW_SORT_H


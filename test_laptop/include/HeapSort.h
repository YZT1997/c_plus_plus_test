//
// Created by yang zhengtao on 2021/5/6.
//

#ifndef TEST_LAPTOP_HEAPSORT_H
#define TEST_LAPTOP_HEAPSORT_H

#include <iostream>
#include <algorithm>
using namespace std;

void maxHeapify(int arr[], int start, int end){
    int father = start;
    int son = father * 2 + 1;

    while (son <= end){
        if(son + 1 <= end && arr[son] < arr[son + 1]){
            son++;      // 取出更大的孩子
        }
        if(arr[father] > arr[son]) return;
        else{
            swap(arr[father], arr[son]);
            father = son;
            son = father * 2 + 1;
        }
    }
}

void HeapSort(int arr[], int len){
    for(int i = len / 2 - 1; i >= 0; i--){
        maxHeapify(arr, i, len - 1);
    }
    for (int i = len - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i - 1);
    }
}

#endif //TEST_LAPTOP_HEAPSORT_H

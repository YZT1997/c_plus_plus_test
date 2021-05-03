//
// Created by yang zhengtao on 2021/4/16.
//

#ifndef TEST_LAPTOP_MERGESORT_H
#define TEST_LAPTOP_MERGESORT_H
#include <algorithm>
#include <vector>
template <typename T>
void merge_sort_recur(std::vector<T>& arr, std::vector<T>& res, int start, int end){
    if(start >= end) return;

    int len = end - start, mid = (len >> 1) + start;

    int start_front = start, end_front = mid;
    int start_back = mid + 1, end_back = end;
    merge_sort_recur(arr, res, start_front, end_front);
    merge_sort_recur(arr, res, start_back, end_back);

    int i = start;

    while (start_front <= end_front && start_back <= end_back){
        res[i++] = arr[start_front] < arr[start_front] ? arr[start_front++] : arr[start_back++];
    }
    while (start_front <= end_front){
        res[i++] = arr[start_front++];
    }
    while (start_back <= end_back){
        res[i++] = arr[start_back++];
    }

    for (i = start; i <= end ; ++i) {
        arr[i] = res[i];
    }
}

template <typename T>
void merge_sort(std::vector<T>& arr, const int len){
    std::vector<T> res(len);
    merge_sort_recur(arr, res, 0, len - 1);
}


#endif //TEST_LAPTOP_MERGESORT_H

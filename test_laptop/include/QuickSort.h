//
// Created by yang zhengtao on 2021/4/16.
//

#ifndef TEST_LAPTOP_QUICKSORT_H
#define TEST_LAPTOP_QUICKSORT_H
#include <algorithm>
#include <vector>

template <typename T>
void quick_sort_recursive(std::vector<T> &arr, int start, int end){
    if(start >= end) return;
    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right){
        while (arr[left] < mid && left < right) left++;
        while (arr[right] >= mid && left < right) right--;
        std::swap(arr[left], arr[right]);
    }

    if(arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;

    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);

}

template <typename T>
void quick_sort(std::vector<T>& arr, int len){
    quick_sort_recursive(arr, 0, len - 1);
}

#endif //TEST_LAPTOP_QUICKSORT_H

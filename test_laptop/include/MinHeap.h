//
// Created by yang zhengtao on 2021/1/12.
//

#ifndef TEST_LAPTOP_MINHEAP_H
#define TEST_LAPTOP_MINHEAP_H
template <class T>
class MinHeap{
private:
    T *_minHeap = nullptr;
    int _index, _maxSize;
public:
    MinHeap(int maxSize){
        _maxSize = maxSize;

    }
};
#endif //TEST_LAPTOP_MINHEAP_H

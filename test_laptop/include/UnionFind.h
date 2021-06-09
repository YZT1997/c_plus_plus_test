//
// Created by yang zhengtao on 2021/5/13.
//

#ifndef TEST_LAPTOP_UNIONFIND_H
#define TEST_LAPTOP_UNIONFIND_H
#include <iostream>
#include <string>
#include <unordered_map>

template<class T1, class T2>
class UF{
private: int count;
    std::unordered_map<T1, T2> parent;
    int[] size;

public:
    UF(int n){
        count = n;
        size = new int[n];
        for(int )
    }
};

#endif //TEST_LAPTOP_UNIONFIND_H

//
// Created by yang zhengtao on 2021/4/16.
//
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include "QuickSort.h"
#include "MergeSort.h"
#include <unordered_set>

using namespace std;

bool isBigNum(int a, int b){
    string str_a = to_string(a);
    string str_b = to_string(b);

    return str_a + str_b > str_b + str_a;
}

bool isContain(vector<int>& track, int val){
    auto iter = find(track.begin(), track.end(), val);
    if(iter == track.end()) return false;
    else return true;
}

int main(){
    vector<int> vec;
    for (int i = 0; i < 5; ++i) {
        vec.push_back(2 * i);
    }
    if(isContain(vec, 4)) cout<<"True";
    else cout<<"No";
    return 0;

}
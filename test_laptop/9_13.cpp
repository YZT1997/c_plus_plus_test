//
// Created by yang zhengtao on 2021/9/13.
//
#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main(){
    vector<int> vec;
    for(int i = 0; i < 10; ++i){
        vec.push_back(i);
    }
    vector<int> vec2{-10, -15, -20};
    copy(vec.begin(), vec.end(), back_inserter(vec2));
    for(int num : vec2){
        cout<<num<<" ";
    }
    return 0;
}

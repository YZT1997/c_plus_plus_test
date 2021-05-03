//
// Created by yang zhengtao on 2021/5/3.
//
#include <vector>
#include <iostream>
#include <algorithm>
template<typename T>
bool isEven(const T& num){
    return (num % 2) == 0;
}
template<typename T>
bool compare(const T& a, const T& b){
    return a  > b;
}

template<typename T>
void display(const T& container){
    for(auto iter = container.cbegin(); iter != container.cend(); ++iter){
        std::cout<<*iter<<" ";
    }
    std::cout<<"\n";
}
using namespace std;
int main(){
    vector<int> numVec;
    for (int i = 0; i < 10; ++i) {
        numVec.push_back(3 * i);
    }
    display(numVec);

    size_t num = count_if(numVec.cbegin(), numVec.cend(), isEven<int>);

    partition(numVec.begin(), numVec.end(), isEven<int>);
    display(numVec);

    return 0;
}
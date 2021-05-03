//
// Created by yang zhengtao on 2021/4/12.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string>

bool isBigName(const std::pair<char, int> a, const std::pair<char, int> b){
    return a.first > b.first;
}
bool isBigVal(const std::pair<char, int> a, const std::pair<char, int> b){
    if(a.second == b.second){
        return a.first > b.first;
    }

    return a.second > b.second;
}
using namespace std;
int main(){
    std::vector<int> vec;
    for (int i = 0; i < 4; ++i) {
        vec.push_back(2 * i);
    }

    vec.insert(vec.begin() + 1, 3);

    vector<int>::iterator iter = find(vec.begin(), vec.end(), 3);
    if(iter == vec.end()) cout<<"Not found"<<endl;
    else cout<<distance(vec.begin(), iter)<<endl;


    return 0;

}
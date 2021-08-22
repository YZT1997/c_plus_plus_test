//
// Created by yang zhengtao on 2021/7/16.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool my_compare(const pair<int, int>& lhs, const pair<int, int>& rhs){
    return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second);
}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> vec;

    int sla = 0, score = 0;
    for (int i = 0; i < n; ++i) {
        cin>>sla>>score;
        vec.push_back(make_pair(sla, score));
    }
    sort(vec.begin(), vec.end(), my_compare);

    int start_time = 0;
    multiset<int, less<int>> mul_set;
    for(auto num : vec){
        if(num.first > start_time){
            mul_set.insert(num.second);
            start_time++;
        }
        else{
            if(num.second > *mul_set.begin()){
                mul_set.erase(mul_set.begin());
                mul_set.insert(num.second);
            }
        }
    }

    int sum_score = 0;
    for(auto score : mul_set){
        sum_score += score;
    }
    cout<<sum_score<<endl;
    return 0;
}


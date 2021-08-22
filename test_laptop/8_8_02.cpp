//
// Created by yang zhengtao on 2021/8/8.
//
#include <iostream>
#include <vector>
#include <set>

#define SQUARE(a) (a) * (a)
#define SUB(a) ((a) - (a))

using namespace std;
int find_prev(const set<int, greater<int>>& prev_set, int num){
    for(auto n : prev_set){
        if(n < num){
            return n;
        }
    }
    return 0;
}
int main(){
//    int n = 0;
//    cin>>n;
//    vector<int> vec(n + 1, 0), prev(n + 1, 0);
//    for(int i = 0; i < n; ++i){
//        cin>>vec[i + 1];
//    }
//
//    set<int, greater<int>> prev_set;
//    prev_set.insert(0);
//    for(int i = 1; i <= n; ++i){
//        prev[i] = find_prev(prev_set, vec[i]);
//        prev_set.insert(vec[i]);
//    }
//    int res = 0;
//    for(int i = 1; i <= n; ++i){
//        res += (i * prev[i]);
//    }
//    cout<<res;
    float a = 12.438f;
    int c = 123;
    int b = (int)(a);
    float d = (float)(1.1);



    cout<<d;
    return 0;
}
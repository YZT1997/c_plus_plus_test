//
// Created by yang zhengtao on 2021/7/18.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool my_compare(const vector<long long>& lhs, const vector<long long>& rhs){
    return lhs[1] < rhs[1] || (lhs[1] == rhs[1] && lhs[2] > rhs[2]);
}

int main(){
    string str;
    int n = 0;
    cin>>n;
    vector<vector<long long>> vec;
    long long t1 = 0, t2 = 0, value = 0;
    long long start_time = 0, end_time = 0;
    for (int i = 0; i < n; ++i) {
        cin>>t1>>t2>>value;
        start_time = min(start_time, t1);
        end_time = max(end_time, t2);
        vec.push_back({t1, t2, value});
    }

//    sort(vec.begin(), vec.end(), my_compare);

//    long long time_len = end_time - start_time + 1;
    vector<long long> dp(end_time + 1, 0);
    for(long long i = 1; i <= end_time; ++i){
        for(auto num : vec){
            if(num[1] <= i){
                dp[i] = max(dp[i], dp[num[0]] + num[2]);
            }
        }
    }
    cout<<dp[end_time]<<endl;

    return 0;
}


//
//    multiset<long long, less<long long>> mul_set;
//    int prev_end = 0;
//    for(int i = 0; i < n; ++i){
//        if(vec[i][0] >= prev_end){
//            mul_set.insert(vec[i][2]);
//            prev_end = vec[i][1];
//        }
//        else{
//            if(vec[i][2] > *mul_set.begin()){
//                mul_set.erase(mul_set.begin());
//                mul_set.insert(vec[i][2]);
//                prev_end = vec[i][1];
//            }
//        }
//    }
//    int res = 0;
//    for(auto num : mul_set){
//        res += num;
//    }
//    cout<<res;
//}

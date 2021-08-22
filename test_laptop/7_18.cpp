//
// Created by yang zhengtao on 2021/7/18.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n = 0, m = 0;
    cin>>n>>m;
    vector<int> count_list(n);
    int num = 0;
    set<int, less<int>> count_set;
    for(int i = 0; i < n; ++i){
        cin>>num;
        count_set.insert(num);

    }
//    sort(count_list.begin(), count_list.end());
    n = count_set.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = i * (count_list[i] - count_list[i - 1]) + dp[i - 1];
    }

    int max_group = count_list[0];
    for(int i = 0;i < n - 1; ++i){
        if(dp[i] <= m && m < dp[i + 1]){
            max_group = count_list[i];
            break;
        }
    }
    if(m >= dp[n-1]) max_group = count_list[n-1] + (m - dp[i - 1]) / n;
    cout<<max_group;

    return 0;
}

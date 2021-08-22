//
// Created by yang zhengtao on 2021/8/17.
//
#include <iostream>
#include <vector>

using namespace std;
int integerBreak(int n) {
    if(n < 2) return 0;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for(int i = 2; i <=n; ++i){
        for(int j = 1; j < i; ++j){
            dp[i] = max(dp[i], (i - j) * dp[j]);
        }
    }
    return dp[n];
}

int main(){
    int res = integerBreak(5);
    return 0;
}

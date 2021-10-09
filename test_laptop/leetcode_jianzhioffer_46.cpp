//
// Created by yang zhengtao on 2021/10/5.
//
#include <iostream>
#include <vector>

using namespace std;

int translateNum(int num) {
    string str = to_string(num);
    int n = str.length();

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        dp[i + 1] = dp[i];
        if(i > 0){
            int prev_num = stoi(str.substr(i - 1, 2));
            if(10 <= prev_num && prev_num < 26) dp[i + 1] += dp[i - 1];
        }
    }
    return dp.back();
}

int main(){
    int res = translateNum(18580);
    return 0;
}

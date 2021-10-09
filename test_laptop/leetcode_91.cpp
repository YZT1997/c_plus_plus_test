//
// Created by yang zhengtao on 2021/10/4.
//
#include <iostream>
#include <vector>

using namespace std;

int numDecodings(string s) {
    if(s.empty() || s[0] == '0') return 0;

    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; ++i){
        if(s[i] == '0'){
            dp[i + 1] = 0;
        }
        else{
            dp[i + 1] = dp[i];
        }
        if(i > 0){
            int prev_curr_num = stoi(s.substr(i - 1, 2));
            if(10 <= prev_curr_num && prev_curr_num <= 26){
                dp[i + 1] += dp[i - 1];
            }
        }

    }
    return dp.back();

}

int main(){
    int res = numDecodings("2101");
    cout<<res;
    return 0;

}

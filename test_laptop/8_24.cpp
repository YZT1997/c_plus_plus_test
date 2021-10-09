//
// Created by yang zhengtao on 2021/8/24.
//
#include <iostream>
#include <vector>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<int>> dp(n, vector<int>(k + 2, INT_MAX));
    for(int i = 0; i <= k + 1; ++i) dp[src][i] = 0;

    for(int i = 1; i <= k + 1; ++i){
        for(auto flight : flights){
            if(dp[flight[0]][i - 1] != INT_MAX){
                dp[flight[1]][i] = min(dp[flight[1]][i], dp[flight[0]][i - 1] + flight[2]);
            }
        }
    }
    return dp[dst][k + 1] == INT_MAX?-1:dp[dst][k + 1];
}

int main(){
    vector<vector<int>> flights{{0,1,100},{1,2,100},{0,2,500}};
    int res = findCheapestPrice(3, flights,0, 2, 1);
    cout<<res;
    return 0;
}

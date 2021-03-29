//
// Created by yang zhengtao on 2021/3/2.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool isDigit(char c){
    if(48 <= c && c <= 57) {
        std::cout<<"true"<<endl;
        return true;
    }
    std::cout<<"false";
    return false;
}

int findCountOne(string& strs){
    int count = 0;
    for(int i=0; i < strs.size(); ++i){
        if(strs[i] == '1') count++;
    }
    return count;
}
int findMaxForm(vector<string>& strs, int m, int n) {
    if(strs.size() == 0) return 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // dp[i][j] 代表i个0与j个1时，元素个数的最大值
    for(int k=0; k < strs.size(); ++k){
        int countOnes = findCountOne(strs[k]);
        int countZeros = strs[k].size() - countOnes;
        cout<<"k="<<k<<" "<<countOnes<<" "<<countZeros<<endl;

        // dp[i][j] = max(dp[i][j], 1+dp[i-countZeros][j-countZeros])
        for(int i=m; i>=countZeros; i--){
            for(int j=n; j >= countOnes; j--){
                dp[i][j] = max(dp[i][j], 1 + dp[i-countZeros][j-countOnes]); // 1 + dp[i-zeros][j-zeros] 为选中当前元素
            }
        }
    }

    return dp[m][n];
}

int main(){
    vector<int> a;
    int i = 0;
    while (i < 10){
        i++;
        a.push_back(i);
    }
//    vector<int> dp(10, 0);
//
//    unordered_set<int> dict(a.begin(), a.end());
//    if(dict.count(11)) cout<<"true"<<endl;
//    else cout<<"false"<<endl;
    char c = 'n';
    isDigit(c);

    return 0;

}

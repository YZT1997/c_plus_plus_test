//
// Created by yang zhengtao on 2021/8/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <istream>

using namespace std;

string reverse_invert(string& str){
    string res;
    for(auto c : str){
        res += 'z' - (c - 'a');
    }
    reverse(res.begin(), res.end());
    return res;
}

string solve(string& str, int i){
    if(i == 1){
        str = "a";
        return str;
    }
    else{
        str = str + (char)((i - 1) + 'a') + reverse_invert(str);
    }
    return str;
}

int minSailCost(vector<vector<int> >& input) {
    // write code here
    if(input.empty() || input[0].empty()) return 0;
    int m = input.size();
    int n = input[0].size();
    vector<vector<int>> dp(m, vector<int>(n , 0));

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(i == 0 && j == 0) continue;
            if(input[i][j] == 2) dp[i][j] = -1;
            if(i == 0){
                if(dp[i][j - 1] == 0) dp[i][j] = dp[i][j - 1];
                else
            }
            else{
                if(dp[i - 1][j] == -1 && dp[i][j - 1] == -1){
                    dp[i][j] = -1;
                }
                else if(dp[i - 1][j] != 0 && dp[i][j - 1] != 0){
                    dp[i][j] = input[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
                }
                else{
                    dp[i][j] = input[i][j] + dp[i - 1][j] == 0?dp[i][j - 1] : dp[i][j - 1];
                }
            }
        }
    }
    return dp[m - 1][n - 1] == 0?-1:dp[m - 1][n - 1];


}
int main(){
    string str;
    getline(cin, str, '\n');
    vector<int> vec;
    stringstream str_in(str);
    while(getline(str_in, str, ' ')){
        int num = stoi(str);
        vec.push_back(num);
    }
    int m;
    cin>>m;

    int n = vec.size();
    int count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(vec[i] + vec[j] < m) count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
//
// Created by yang zhengtao on 2021/7/24.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    vector<vector<int>> matrix{{1, 0, 1},{0,0,1},{0,0,1}};
    int n = matrix.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == 0){
                dp[i][j][0] = 1 + (i == 0 ? 0 :dp[i - 1][j][0]);// 行
                dp[i][j][1] = 1 + (j == 0 ? 0 : dp[i][j - 1][1]);   // 列
            }
        }
    }

    int max_side_length = 0;
    int r = -1, c = -1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int temp_side = min(dp[i][j][0], dp[i][j][1]); temp_side >= 1; --temp_side){
                if(dp[i - temp_side + 1][j][1] >= temp_side && dp[i][j - temp_side + 1][0] >= temp_side){
                    if(temp_side > max_side_length){
                        r = i - temp_side + 1;
                        c = j - temp_side + 1;
                        max_side_length = temp_side;
                        break;
                    }
                }
            }
        }
    }
    if(r == -1 && c == -1) return {};
    vector<int> res{r, c, max_side_length};
//    return res;


    return 0;
}

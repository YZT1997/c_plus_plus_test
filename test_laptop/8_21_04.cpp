//
// Created by yang zhengtao on 2021/8/22.
//
#include <iostream>
#include <vector>

using namespace std;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dfs(vector<vector<int>>& input, int row, int col, vector<vector<int>>& is_vis){
    int m = input.size(), n = input[0].size();
    if(row == m - 1 && col == n - 1) return input[row][col];
    if(row < 0 || row >= m || col < 0 || col >= n || is_vis[row][col] || input[row][col] == 0) return INT_MAX;

    is_vis[row][col] = 1;
    int min_path = INT_MAX;
    for (int i = 0; i < 4; ++i) {
        min_path = min(min_path, dfs(input, row + dir[i][0], col + dir[i][1], is_vis));
    }
    return input[row][col] + min_path;
}

int main(){
    vector<vector<int>> vec = {{1, 1, 0}, {0, 2, 1}, {0, 2, 1}};
    vector<vector<int>> is_vis(3, vector<int>(3));
    int res = dfs(vec, 0, 1, is_vis);
    if(is_vis[2][2]) cout<<res;
    else cout<<-1;
    return 0;
}

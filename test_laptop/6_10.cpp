//
// Created by yang zhengtao on 2021/6/10.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
bool my_compare(const int a, const int b){
    return a > b;
}
using namespace std;

void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int row, int col, int prev_val){
    if(row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size() || visited[row][col] || heights[row][col] < prev_val) return;
    visited[row][col] = 1;

    dfs(heights, visited, row - 1, col, heights[row][col]);
    dfs(heights, visited, row + 1, col, heights[row][col]);
    dfs(heights, visited, row, col - 1, heights[row][col]);
    dfs(heights, visited, row, col + 1, heights[row][col]);

}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> res;
    if(heights.empty()) return {};
    int m = heights.size(), n = heights[0].size();

    vector<vector<int>> pacific(m, vector<int>(n, 0));
    vector<vector<int>> atlantic(m, vector<int>(n, 0));

    for(int i = 0; i < m; ++i){
        dfs(heights, pacific, i, 0, heights[i][0]);
        dfs(heights, atlantic, i, n - 1, heights[i][n - 1]);
    }
    for(int j = 0; j < n; ++j){
        dfs(heights, pacific,  0, j, heights[0][j]);
        dfs(heights, atlantic, n - 1, j, heights[n - 1][j]);
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
        }
    }
    return res;
}

int main(){
    vector<vector<int>> vec{{3, 3, 3, 3, 3},{3, 0, 3, 0, 3}, {3, 3, 3, 3, 3}};
    vector<vector<int>> res = pacificAtlantic(vec);
    for(auto row : res){
        for(auto num : row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}

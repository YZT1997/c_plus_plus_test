//
// Created by yang zhengtao on 2021/8/22.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int dir_x[4] = {1, 0, -1, 0};
const int dir_y[4] = { 0,  1, 0, -1};
int dfs(vector<vector<int>>& input, int row, int col, vector<vector<int>>& is_vis){
    int m = input.size(), n = input[0].size();
    if(row == m - 1 && col == n - 1) return input[row][col];
    if(row < 0 || row >= m || col < 0 || col >= n || is_vis[row][col] || input[row][col] == 0) return INT_MAX;

    is_vis[row][col] = 1;
    int min_path = INT_MAX;
    for (int i = 0; i < 4; ++i) {
        min_path = min(min_path, dfs(input, row + dir[i][0], col + dir[i][1], is_vis));
    }
    is_vis[row][col] = 0;
    return input[row][col] + min_path;
}

int bfs(vector<vector<int>>& input){
    int m = input.size(), n = input[0].size();
    vector<vector<bool>> is_vis(m, vector<bool>(n, false));
    vector<vector<int>> path_cost(m, vector<int>(n, INT_MAX));


    queue<pair<int, int>> que;
    que.emplace(0, 0);
    is_vis[0][0] = true;
    int res = 0;
    path_cost[0][0] = 0;
    bool find = false;
    while(!que.empty()){
        int size = que.size();
        while (size--){
            auto [x, y] = que.front();
            res = path_cost[x][y];
            is_vis[x][y] = true;
            que.pop();
            if(x == m - 1 && y == n - 1 && que.empty()) {
                find = true;
                break;
            }
            for(int i = 0; i < 4; ++i){
                int n_x = x + dir_x[i], n_y = y + dir_y[i];
                if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n && input[n_x][n_y] != 0 && !is_vis[n_x][n_y]){
                    que.emplace(n_x, n_y);
                    path_cost[n_x][n_y] = min(path_cost[n_x][n_y], res + input[n_x][n_y]);
//                    is_vis[n_x][n_y] = true;
                }
            }
        }
        if(find){
            break;
        }

    }
    if(is_vis[m - 1][n - 1]) return path_cost[m - 1][n - 1];
    else return -1;
}

int main(){
    vector<vector<int>> vec = {{1, 1, 0},{0,1,0},{1,1,0},{1,5,0},{1,1,1}};
//    int res = dfs(vec, 0, 1, is_vis);
    int res = bfs(vec);
    cout<<res;

    return 0;
}

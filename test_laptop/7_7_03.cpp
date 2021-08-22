#include <bits/stdc++.h>
using namespace std;


const int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int dy[8] = {2, 2, 1,-1, -2, -2, -1, 1};
const int mask_x[8] = {0, 0, 1, 1, 0, 0, -1 , -1};
const int mask_y[8] = {1, 1, 0, 0, -1, -1, 0, 0};

int main(){
    int m , n;
    int start_x, start_y, end_x, end_y;
    cin>>m>>n;
    vector<vector<char>> grid(m, vector<char>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin>>grid[i][j];
            if(grid[i][j] == 'H'){
                start_x = i;
                start_y = j;
            }
            else if(grid[i][j] == 'T'){
                end_x = i;
                end_y = j;
            }
        }
    }
    queue<pair<int, int>> que;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    que.emplace(start_x, start_y);
    vis[start_x][start_y] = true;
    int res = 0;
    bool find = false;
    while(!que.empty()){
        int size = que.size();
        while(size--){
            auto [x, y] = que.front();
            que.pop();
            if(x == end_x && y == end_y){
                find = true;
                break;
            }
            for(int k = 0; k < 8; ++k){
                int n_x = x + dx[k], n_y = y + dy[k];
                if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n && !vis[n_x][n_y] && grid[n_x][n_y] != '#' && grid[x + mask_x[k]][y+mask_y[k]] != '#'){
                    que.emplace(n_x, n_y);
                    vis[n_x][n_y] = true;
                }
            }
        }
        if(find) break;
        ++res;
    }
    if(!vis[end_x][end_y]){
        cout<<-1<<endl;
    }
    else{
        cout<<res<<endl;
    }
    return 0;

}

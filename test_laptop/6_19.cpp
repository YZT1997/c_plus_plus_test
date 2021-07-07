//
// Created by yang zhengtao on 2021/6/19.
//
/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(queue<pair<int, int>>& q){
    cout<<"("<<q.front().first<<", "<<q.front().second<<")\n";
    q.pop();
    print(q);
}

int main(){
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    cout<<"Enter mat"<<endl;
    cin>>m>>n;
    vector<vector<int>> vec(m, vector<int>(n));
    vector<vector<bool>> is_visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j) {
            cin>>vec[i][j];
        }
    }

    queue<pair<int, int>> que;
    que.push({0, 0});
    while (!que.empty()){
        pair<int, int> curr_pos = que.front();
        que.pop();

        if(curr_pos.first == m - 1 && curr_pos.second == n - 1){
            print(que);
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int row = curr_pos.first + dir[i][0];
            int col = curr_pos.second + dir[i][1];

            if(row < 0 || row >= vec.size() || col < 0 || col >= vec[0].size() || is_visited[row][col] || vec[row][col] != 0) continue;
            is_visited[row][col] = true;
            que.push({row, col});
        }

    }
    return 0;

}
*/
/*
#include<iostream>
#include<vector>
using namespace std;
bool flag;
void dfs(vector<vector<int>>& nums, vector<pair<int, int>>& points, int i, int j) {
    if (flag) return;//已找到路径，return
    if (i < 0 || i >= nums.size() || j < 0 || j >= nums[0].size()) return;//遇到边界return
    points.push_back({ i,j });
    if (nums[i][j] == 1) {//碰到障碍物，此路不通，pop后return
        points.pop_back();
        return;
    }
    if (i == nums.size() - 1 && j == nums[0].size() - 1)//到达终点
    {
        for (auto i : points) {
            cout << '(' << i.first << ',' << i.second << ')' << endl;
        }
        flag = true;
        return;
    }
    dfs(nums, points, i + 1, j);//向右走
    dfs(nums, points, i, j + 1);//向下走
    dfs(nums, points, i - 1, j + 1);//向上走
    dfs(nums, points, i, j - 1);//向左走
    points.pop_back();//不通，pop
}

int main() {
    int m, n;
    cin>>m>>n;
    vector<vector<int>> nums(m, vector<int>(n, 0));
    vector<pair<int, int>> points;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    flag = false;
    dfs(nums, points, 0, 0);
    return 0;
}
 */
#include <iostream>
#include <vector>

using namespace std;

// 寻找start, end之间的最长单调子序列长度

int main(){
    int n;
    while(cin>>n){
        vector<int> vec(n);
        for(int i = 0; i < n; ++i){
            cin>>vec[i];
        }

        vector<int> max_len_up(n, 1);
        vector<int> max_len_down(n, 1);

        int min_count = n;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(vec[j] < vec[i]){
                    max_len_up[i] = max(max_len_up[j] + 1, max_len_up[i]);
                }
            }
        }
        for(int i = n - 1; i >= 0; --i){
            for(int j = n - 1; j > i; --j){
                if(vec[j] < vec[i]){
                    max_len_down[i] = max(max_len_down[j] + 1, max_len_down[i]);
                }
            }
        }

        for(int i = 0; i < n; ++i){
            min_count = min(min_count, (n + 1 - max_len_up[i] - max_len_down[i]));
        }

        cout<<min_count<<endl;
    }
    return 0;
}
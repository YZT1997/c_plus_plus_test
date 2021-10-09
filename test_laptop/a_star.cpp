//
// Created by yang zhengtao on 2021/9/6.
//
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const int dir_row[4] = {-1, 1, 0, 0};
const int dir_col[4] = {0, 0, -1, 1};

struct Node{
    int row_;
    int col_;
    int from_head_cost_;
    Node():row_(0), col_(0), from_head_cost_(0){}
    Node(int row, int col, int cost):row_(row), col_(col), from_head_cost_(cost){}
};

struct my_compare{
    bool operator () (const Node& lhs, const Node& rhs) const{
        return lhs.from_head_cost_ < rhs.from_head_cost_;
    }
};


int main(){
    int m = 5, n = 5;
    vector<vector<int>> cost_vec{{1, 1, 1, 1, 1},{0, 0, 0, 0, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 0, 100},{1, 1, 1, 1, 1}};

    vector<vector<int>> is_closed(m, vector<int>(n, 0));
    vector<vector<int>> is_open(m, vector<int>(n, 0));
    vector<vector<int>> all_cost(m, vector<int>(n, INT_MAX));
    all_cost[0][0] = 0;

    queue<pair<int, int>> que;
    multiset<Node, my_compare> open_list;
    open_list.emplace(Node(0, 0, 0));

    while (!open_list.empty()){
        // 每次只输入一个
        int row = open_list.begin()->row_;
        int col = open_list.begin()->col_;
        if(row == 4 && col == 4) break;
        auto cost = all_cost[row][col];
        is_closed[row][col] = 1;
        open_list.erase(open_list.begin());
        for(int i = 0; i < 4; ++i){
            int n_row = row + dir_row[i];
            int n_col = col + dir_col[i];
            if(n_row < 0 || n_row >= m || n_col < 0 || n_col >= n || is_closed[n_row][n_col] || cost_vec[n_row][n_col] == 0) continue;
            if(!is_open[n_row][n_col]){
                int n_cost = cost + cost_vec[n_row][n_col];
                all_cost[n_row][n_col] = n_cost;
                open_list.emplace(Node(n_row, n_col, n_cost));
                is_open[n_row][n_col] = 1;
            }
            else{
                if(cost + cost_vec[n_row][n_col] < all_cost[n_row][n_col]){
                    all_cost[row][col] = cost + cost_vec[n_row][n_col];
                }
            }
        }
    }

    for(auto row : all_cost){
        for(auto num : row){
            if(num == INT_MAX) cout<<"* ";
            else cout<<num<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

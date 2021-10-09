//
// Created by yang zhengtao on 2021/9/11.
//
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int row = 0, col = 0;
    int curr_num = 1;
    int direction_ind = 0;
    const int dir_row[4] = {0, 1, 0, -1};
    const int dir_col[4] = {1, 0, -1, 0};

    vector<vector<int>> vec(n, vector<int>(n, 0));
    while(curr_num <= n * n){
        vec[row][col] = curr_num;

        int n_row = row + dir_row[direction_ind];
        int n_col = col + dir_col[direction_ind];

        if(n_row < 0 || n_row >= n || n_col < 0 || n_col >= n || vec[n_row][n_col] != 0){
            direction_ind = direction_ind % 4;// 顺时针旋转
        }

        row = row + dir_row[direction_ind];
        col + dir_col[direction_ind];

        curr_num++;
    }

    return vec;

}

int main(){

}

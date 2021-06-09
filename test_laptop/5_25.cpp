//
// Created by yang zhengtao on 2021/5/25.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 * 如果矩阵元素为1，则将其标记为area_id(大于 1 的一个整数)
 * 同时对其8个方向的元素进行递归调用，继承area_id
 * 跳出循环条件：数组越界 || 数组元素 ！= 1
 * */
void infect(vector<vector<int>>& vec, int row, int col, int area_id){
    if(row < 0 || row >= vec.size() || col < 0 || col >= vec[0].size() || vec[row][col] != 1) return;

    vec[row][col] = area_id;
    for (int i = -1; i <= 1; ++i){
        for(int j = -1; j <= 1; ++j){
            if(i == 0 && j == 0) continue;
            infect(vec, row + i, col + j, area_id);
        }
    }
}

void func(vector<vector<int>>& vec){
    if(vec.empty()) return;
    int rows = vec.size();
    int cols = vec[0].size();
    int area_id = 2;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(vec[i][j] == 1) {
                infect(vec, i, j, area_id);
                area_id++;
            }
        }
    }
}

int main(){
    vector<vector<int>> vec(4, vector<int>(5, 0));
    vec[0][0] = 1;
    vec[1][1] = 1;
    vec[0][4] = 1;
    vec[2][1] = 1;
    vec[3][0] = 1;
    vec[3][1] = 1;
    vec[3][4] = 1;
    func(vec);
    for(auto row : vec){
        for(auto val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}


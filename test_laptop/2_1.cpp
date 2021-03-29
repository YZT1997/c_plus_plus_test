//
// Created by yang zhengtao on 2021/2/1.
//
#include "iostream"
#include "stdio.h"
#include "stack"
#include <vector>

using namespace std;
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m = matrix.size();      //获取矩阵行数
    int n = matrix.at(0).size();   //获取矩阵列数
    vector<vector<int>> result;
    vector<int> temp;
    for(int i=0;i < n;i++){
        for(int j=0;j < m;j++){
            temp.push_back(matrix.at(j).at(i));
        }
        result.push_back(temp);
        temp.clear();
    }
    return result;

}

int main(){
    vector<vector<int>> matrix, matrix_trans;
    vector<int> temp;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp.push_back(j+1);
        }
        matrix.push_back(temp);
        temp.clear();
    }
    matrix_trans = transpose(matrix);
    matrix.at(0).at(0) = 2;

    for (int i = 0; i < matrix.size(); ++i) {
        cout<<"[";
        for (int j = 0; j < matrix.at(i).size(); ++j) {
            cout<<matrix.at(i).at(j)<<",";
        }
        cout<<"]"<<endl;

    }

    return 0;
}


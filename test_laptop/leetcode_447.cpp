//
// Created by yang zhengtao on 2021/9/13.
//
#include <iostream>
#include <vector>
#include "cmath"
#include <map>

using namespace std;

int numberOfBoomerangs(vector<vector<int>>& points) {
    if(points.empty() || points.size() < 3) return 0;
    int n = points.size();

    int res = 0;
    map<int, int> dis_count;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j) continue;

            int dis = pow((points[i][0] - points[j][0]), 2) + pow((points[i][1] - points[j][1]), 2);
            dis_count[dis]++;
        }
        for(auto dis_count_pair : dis_count){
            if(dis_count_pair.second > 1){
                res += dis_count_pair.second * (dis_count_pair.second - 1);
            }
        }
        dis_count.clear();
    }
    return res;
}

int main(){
    vector<vector<int>> points{{0, 0},{1, 0}, {2, 0}};
    int res = numberOfBoomerangs(points);
    return 0;
}
//
// Created by yang zhengtao on 2021/8/22.
//
#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n, m, p;
    cin>>n>>m>>p;
    vector<int> water(n);
    for (int i = 0; i < n; ++i) {
        cin>>water[i];
    }
    vector<vector<int>> path(m, vector<int>(3));
    for(int i = 0; i < m; ++i){
        cin>>path[i][0]>>path[i][1]>>path[i][2];
    }
    vector<vector<int>> path_map(n + 1, vector<int>(n + 1, INT_MAX));

    for(int i = 0; i < m; ++i){
        path_map[path[i][0]][path[i][1]] = path[i][2];
        path_map[path[i][1]][path[i][0]] = path[i][2];
    }
    for (auto row : path_map) {
        for(auto num : row){
            cout<<num<<" ";
        }
        cout<<"\n";
    }

    int max_water = 0;
    int max_water_ind = 0;
    for(int i = 1; i <= n; ++i){
        int temp_max_water = 0;

        for(int j = 1; j <= n; ++j){
            if(path_map[i][j] == INT_MAX) continue;
            // do some dp



        }
        if(temp_max_water > max_water){
            max_water = temp_max_water;
            max_water_ind = i;
        }

    }
    cout<<max_water_ind<<" "<<max_water<<endl;
    return 0;

    return 0;
}


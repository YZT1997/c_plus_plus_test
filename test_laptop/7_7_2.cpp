//
// Created by yang zhengtao on 2021/7/7.
//
#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& dist, int curr_pos, vector<bool>& vis){
    vis[curr_pos] = true;
    int res = 0;
    for(int j = 1; j < dist[curr_pos].size(); ++j){
        if(dist[curr_pos][j] == INT_MAX) continue;
        res = max(res, dist[curr_pos][j] + dfs(dist, j, vis));
    }
    return res;
}

int main(){
    int n = 0, start = 0;
    string str;
    vector<vector<int>> vec;
    while (getline(cin, str, '\n')){
        if(str[0] != '[') break;
        str = str.erase(0, 1);
        str = str.erase(str.size() - 1, 1);
        istringstream line(str);
        string temp_str;
        vector<int> temp_vec(3);
        for(int i = 0; i < 3; ++i){
            getline(line, temp_str, ',');
            temp_vec[i] = stoi(temp_str);
        }
        vec.push_back(temp_vec);
    }
    n = stoi(str);
    cin>>start;

    // process
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
//    unordered_map<int, vector<int>> dist;
    vector<bool> vis(n + 1, false);
    for(auto num : vec){
        dist[num[0]][num[1]] = num[2];
    }
    // dfs
    int res = dfs(dist, start, vis);
    for(int i = 1; i <= n; ++i){
        if(!vis[i]) res = -1;break;
    }
    cout<<res<<endl;



    cout<<"yes"<<endl;

    return 0;

}

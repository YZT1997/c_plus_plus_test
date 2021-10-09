//
// Created by yang zhengtao on 2021/8/25.
//
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
//vector<int> track;
void dfs(vector<vector<int>>&graph, vector<int>& track,int curr_pos){
    int n = graph.size();
    track.push_back(curr_pos);
    if(curr_pos == n - 1){
        res.push_back(track);
    }

    if(!graph[curr_pos].empty()){
        for(auto target : graph[curr_pos]){
            dfs(graph, track, target);
        }
    }
    track.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    if(graph.empty()) return {};
    vector<int> track;
    dfs(graph, track, 0);
    return res;
}

int main(){
    vector<vector<int>> graph{{1, 2}, {3}, {3}, {}};
    vector<vector<int>> res;
    res = allPathsSourceTarget(graph);
    for(auto row : res){
        for(auto num : row){
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
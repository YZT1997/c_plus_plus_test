//
// Created by yang zhengtao on 2021/5/30.
//
/* 并查集思路实现
 * */
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
int count = 0;

string find(string& son, unordered_map<string, string>& parent){
    while (parent[son] != son){
        son = parent[son];
    }
    return son;
}

void union_group(string& a, string& b, unordered_map<string, string>& parent){
    string root_a = find(a, parent);
    string root_b = find(b, parent);
    if(root_a == root_b) return;

    parent[root_a] = root_b;
    count--;
}
int main(){
    cout<<"Please input the count"<<endl;
    cin>>count;
    vector<pair<string, string>> vec_input;
    unordered_map<string, string> parent;
    for(int i = 0; i < count; ++i){
        string a, b;
        cin>>a>>b;
        vec_input.push_back({a, b});
        parent[a] = a;
    }

    for(auto vec : vec_input){
        union_group(vec.first, vec.second, parent);
    }

    cout<<count<<endl;

    return 0;
}

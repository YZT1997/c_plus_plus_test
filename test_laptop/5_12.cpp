//
// Created by yang zhengtao on 2021/5/12.
//

#include<iostream>
#include <string>
#include "vector"
#include <map>
#include <unordered_map>
#include <set>
#include <memory>
using namespace std;

int longestCommonStr(string& str1, string& str2){
    if(str1.empty() || str2.empty()) return 0;

    int m = str1.length(), n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp.back().back();
}

string find(unordered_map<string, string>& umap, string& parent){
    while (umap[parent] != parent){
        parent = umap[parent];
    }
    return parent;
}

void unionFind(unordered_map<string, string>& umap, string& str1, string& str2, int count){
    string root1 = find(umap, str1);
    string root2 = find(umap, str2);
    if(root1 == root2) return;

    umap[root1] = root2;
    count--;
    return;
}

template<typename T>
struct myCompare{
    bool operator()(const T& a, const T& b) const{
        return a.second < b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    if(k > nums.size()) return {};

    unordered_map<int, int> umap;
    for(auto num : nums){
        umap[num]++;
    }

    multiset<pair<int, int>, myCompare<pair<int, int>>> maxHeap;
    for(auto iter : umap){
        if(maxHeap.size() == k) {
            auto maxVal_iter = maxHeap.begin();
            if(iter.second > maxVal_iter->second){
                maxHeap.erase(maxVal_iter);
                maxHeap.insert(iter);
            }
        }
        else{
            maxHeap.insert(iter);
        }
    }
//    for(auto u : maxHeap){
//        cout<<u.first<<" "<<u.second<<endl;
//    }

    vector<int> res;
    for(auto iter:maxHeap){
        res.push_back(iter.first);
    }
    return res;
}

int main(){
    unordered_map<string, string> m, res;
    m["a"] = "b";
    m["b"] = "c";
    m["c"] = "a";
    m["d"] = "c";
    m["e"] = "f";
    m["f"] = "e";

    vector<int> nums{1,1,1,2,2,3,2,2,2,4,5,5,4}, vec;
    vec = topKFrequent(nums, 4);
    for(auto v : vec){
        cout<<v<<" ";
    }



    return 0;
}

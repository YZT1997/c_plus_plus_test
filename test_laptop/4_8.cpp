//
// Created by yang zhengtao on 2021/4/8.
//
#include <iostream>
#include <map>
#include <vector>
#include "algorithm"

using namespace std;

void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int province, int i){
    for(int j = 0; j < province; j++){
        if(isConnected[i][j] && !visited[j]){
            visited[j] = 1;                          // 标记为已访问
            dfs(isConnected, visited, province, j);  // 对于j结点继续进行访问
        }
    }
}
vector<vector<int>> threeSum(vector<int>& nums) {
    // Exception
    if (nums.size() < 3) return {};

    // 先进行排序处理
    sort(nums.begin(), nums.end());
    if (*nums.begin() > 0) return {};

    vector<vector<int>> ans;
    /*
    while(l + 1 < r){
        for(int i = l+1; i < r; i++){
            // 保证每次枚举的数据不同
            if(i > l+1 && nums[i] == nums[i-1]) continue;
            int tmp = nums[l] + nums[i] + nums[r];
            if(tmp == 0){
                vector<int> temVec{nums[l], nums[i], nums[r]};
                ans.push_back(temVec);
            }
        }
        // 通过绝对值判断，对l, r进行操作
        if(abs(nums[l]) < abs(nums[r])) r--;
        else l++;
    }*/
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        // 双指针
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int tmp = nums[i] + nums[l] + nums[r];
            if (tmp == 0) {
                vector<int> temVec{nums[i], nums[l], nums[r]};
                ans.push_back(temVec);
                // 去重
                while (l < r && nums[l] == nums[l + 1]) {
                    l++;
                }
                while (l < r && nums[r - 1] == nums[r]){
                    r--;
                }
                l++;
                r--;
            }
            else if (tmp < 0) l++;       // 已经排序好
            else r--;
        }
    }
    return ans;
}
int main(){
//    int n;
//    cin>>n;
//    map<string, string> relationMap;
//    map<string, int> indMap;
//    vector<int> isVisited(n, 0);
//
//    string a, b;
//    for (int i = 0; i < n; ++i) {
//        cin>>a>>b;
//        relationMap[a] = b;
//        indMap[a] = i;
//    }
//
//    vector<vector<int>> isConnected;
//    int totalNum = 0;
//    for(int i = 0; i < n; i++){
//        if(!isVisited[i]){
//            dfs(isConnected, isVisited, n, i);
//            totalNum++;
//        }
//    }
    vector<int> tempVec{-2,0,0,2,2};
    vector<int> tempVec2{-2,0,1,1,2};
//    reverse(tempVec.begin(), tempVec.end());
//    swap(*tempVec.begin(), tempVec[tempVec.size() - 1]);
//    while (!tempVec.empty()){
//        cout<<*tempVec.begin()<<endl;
//        tempVec.erase(tempVec.begin());
//    }
//    tempVec.pop_back();
//    tempVec.pop_back();
    cout<<*(tempVec.end() - 1);

    return 0;
}
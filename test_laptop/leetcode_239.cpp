//
// Created by yang zhengtao on 2021/10/5.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int>> priorityQueue;
    for(int i = 0; i < k ; ++i){
        priorityQueue.push(make_pair(nums[i], i));
    }

    vector<int> ans = {priorityQueue.top().first};
    for(int i = k ; i < n; ++i){
        priorityQueue.push({nums[i], i});
        while(priorityQueue.top().second <= i - k){
            priorityQueue.pop();
        }
        ans.push_back(priorityQueue.top().first);
    }
    return ans;


}
int main(){

}

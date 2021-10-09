//
// Created by yang zhengtao on 2021/9/12.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/* bytedancing 20210912, 第一题
bool my_compare(const vector<int>& lhs, const vector<int>& rhs){
    return lhs[1] < rhs[1];
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums;
    int start= 0, delay = 0;
    for(int i = 0; i < n; ++i){
        cin>>start>>delay;
        nums.push_back({start, start + delay - 1});
    }
    sort(nums.begin(), nums.end(), my_compare);

    int last_end = nums[0][1];
    int count = 1, res = 0;
    for(int i = 0; i < n; ++i){
        last_end = nums[i][1];
        count = 1;
        for(int j = i + 1; j < n; ++j){
            if(nums[j][0] <= last_end) count++;
        }
        res = max(res, count);
    }
    cout<<last_end<<"\n";
    cout<<res<<"\n";
    return 0;
}
 */

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin>>nums[i];
    }
    int ans = 0;
    long long sum = 0;
    multiset<int, less<int>> less_heap;
    for(auto num : nums){
        sum += num;
        less_heap.insert(num);
        while (sum < 0){
            sum -= *less_heap.begin();
            less_heap.erase(less_heap.begin());
        }
        int size = less_heap.size();
        ans = max(size, ans);
    }
    cout<<ans<<"\n";
    return 0;
}



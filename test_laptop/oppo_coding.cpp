//
// Created by yang zhengtao on 2021/9/17.
//
/*
 * 第一道题
#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    getline(cin, str);

    string res;
    int right = str.size() - 1;
    while(right >= 0){
        while (right >= 0 && str[right] == ' ') right--;
        if(right < 0) break;
        int left = right;
        while(left >= 0 && str[left] != ' ')left--;
        res += str.substr(left + 1, right - left);
        res += ' ';
        right = left;
    }
    cout<<res<<"\n";
    return 0;
}
 */

/*
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param intArray int整型vector 整数数组
     * @param startIndex int整型 起始索引
     * @return bool布尔型
     */
/*
    bool checkReach(vector<int>& intArray, int startIndex) {
        // write code here
        if(intArray.empty()) return false;
        int n = intArray.size();
        vector<bool> is_vis(n, false);
        bool res = dfs(intArray, startIndex, is_vis);
        return res;
    }
    bool dfs(const vector<int>& array, int curr_ind, vector<bool>& is_vis){
        int n = array.size();
        if(curr_ind < 0){
            curr_ind %= n;
            curr_ind += n;
        }
        else if(curr_ind >= n){
            curr_ind %= n;
        }
        if(array[curr_ind] == 0) return true;
        if(is_vis[curr_ind]) return false;
        is_vis[curr_ind] = true;
        if(dfs(array, curr_ind + array[curr_ind], is_vis) || dfs(array, curr_ind - array[curr_ind], is_vis)){
            return true;
        }
        else{
            is_vis[curr_ind] = false;
            return false;
        }
    }
};
*/
#include <iostream>
#include <vector>
using namespace std;
int findNumberOfLIS(vector<int>& nums) {
    if(nums.empty()) return 0;

    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = 1;

    int max_len = 0, max_len_count = 0;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        if(dp[i] > max_len){
            max_len = dp[i];
            max_len_count = 1;
        }
        else if(dp[i] == max_len){
            max_len_count++;
        }
        else{
            continue;
        }
    }
    return max_len_count;
}
int main(){
    vector<int> nums{1, 3, 5, 4, 7};
    int res = findNumberOfLIS(nums);
    return 0;



}
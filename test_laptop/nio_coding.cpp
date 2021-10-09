//
// Created by yang zhengtao on 2021/9/25.
//
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    // write code here
    if(s.empty()) return 0;
    int n = s.length();

    vector<int> prev_ind(26, -1);
    int curr_len = 0, max_len = 0;
    for(int i = 0; i < n; ++i){
        int temp_ind = s[i] - 'a';
        if(prev_ind[temp_ind] != -1){
            curr_len = i - prev_ind[temp_ind];
        }
        else{
            curr_len++;
        }
        max_len = max(max_len, curr_len);
        prev_ind[temp_ind] = i;
    }
    return max_len;

}

int main(){
    string s = "nioisbest";
    int ans = lengthOfLongestSubstring(s);
    cout<<ans;
    return 0;
}

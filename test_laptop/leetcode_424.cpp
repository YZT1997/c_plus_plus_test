//
// Created by yang zhengtao on 2021/10/6.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int thirdMax(vector<int>& nums) {

    set<int, less<int>> max_heap;
    for(auto num : nums){
        if(max_heap.count(num)) continue;
        if(max_heap.size() < 3) max_heap.insert(num);
        else{
            if(num > *max_heap.begin()){
                max_heap.erase(max_heap.begin());
                max_heap.insert(num);
            }
        }
    }
    if(max_heap.size() == 2) return max(*max_heap.begin(), *(++max_heap.begin()));

    return *max_heap.begin();
}
int characterReplacement(string s, int k) {
    vector<int> char_count(26, 0);
    int left = 0, max_count = 0, res = 0;

    int n = s.length();
    for(int i = 0; i < n; ++i){
        char_count[s[i] - 'A']++;
        max_count = max(max_count, char_count[s[i] - 'A']);

        while(i + 1 - left  - max_count > k){
            char_count[s[left] - 'A']--;
            left++;
        }
        res = max(res, i + 1 - left);
    }
    return max_count;
}

int main(){
    int res = characterReplacement("AABABBA", 1);
    return 0;
}
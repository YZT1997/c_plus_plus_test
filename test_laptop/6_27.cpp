//
// Created by yang zhengtao on 2021/6/27.
//
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

void backtrack(queue<int> &que, stack<int> &st){
    if(que.empty()) return;

    st.push(que.front());
    que.pop();
    backtrack(que, st);
}

int lengthOfLongestSubstring(string s) {
    if(s.empty()) return 0;

    int l = 0, r = 0, max_len = 0;
    set<char> window;
    for(; r < s.size(); ++r){
        char c = s[r];
        while(window.count(c)){
            window.erase(s[l]);
            l++;
        }
        window.insert(c);
        max_len = max(r - l + 1, max_len);
    }
    return max_len;

}

int main(){
    string a = "Joyn", b = "Jon";
    if(a < b) cout<<"True";
    return 0;
}

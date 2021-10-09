//
// Created by yang zhengtao on 2021/9/3.
//
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

map<pair<int, int>, bool> memo;

bool dp(const string& s, const string& p, int i, int j){
    if(memo.count(make_pair(i, j))) return memo[make_pair(i, j)];

    if(j == p.length()) return i == s.length();

    bool first_match = i < s.length() && (p[j] == s[i] || p[j] == '.');

    bool is_match = false;
    if(j < p.length() - 2 && p[j] == '*'){
        is_match = (first_match && dp(s, p, i + 1, j + 1)) || dp(s, p, i, j + 2);
    }

    memo[make_pair(i, j)] = is_match;

    return is_match;
}
bool isMatch(string s, string p) {
    bool ans = dp(s, p, 0, 0);
    return memo[make_pair(0, 0)];

}

int main(){
    string s = "ab", p = ".*";
    bool res = isMatch(s, p);
    if(res) cout<<"True";
    return 0;
}

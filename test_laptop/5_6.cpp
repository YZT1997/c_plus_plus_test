//
// Created by yang zhengtao on 2021/5/6.
//
#include <iostream>
#include <string>
#include "vector"
#include <unordered_map>
#include <map>
#include <HeapSort.h>
#include <set>
#include <ctype.h>
//#define pi 3.14159
const double pi = 3.1415926;
using namespace std;
string removeDuplicateLetters(string s) {
    vector<int> pos(26, -1);
    for(char c : s){
        int currPos = c - 'a';
        if(pos[currPos] != -1) continue;
        pos[currPos] = 1;
    }
    string res;
    for(int i = 0; i < 26; ++i){
        if(pos[i] == -1) continue;
        res += ('a' + i);
    }
    return res;
}
bool isSameStruct(string& s, string& t){
    if(s.length() != t.length()) return false;
    unordered_map<char, char> s_t, t_s;
    for(int i = 0; i < s.length(); ++i){
        char c_s = s[i], c_t = t[i];
        if((s_t.count(c_s) && s_t[c_s] != c_t)||(t_s.count(c_t) && t_s[c_t] != c_s))
            return false;
        s_t[c_s] = c_t;
        t_s[c_t] = c_s;
    }
    return true;
}
int findMin(vector<int>& nums) {
    if(nums.size() == 1) return *nums.begin();

    int n = nums.size();
    for(int i = 0; i < n - 1; ++i){
        if(nums[i] > nums[i + 1]) return nums[i + 1];
    }
    return *nums.begin();

}
int compareVersion(const string version1, const string version2) {
    int i = 0, j = 0;
    while(i < version1.length() || j < version2.length()){
        int a = 0, b = 0;
        while(i < version1.length() && version1[i] != '.'){
            a = 10 * a + version1[++i];
        }
        while(j < version2.length() && version2[j] != '.'){
            b = 10 * b + version2[++j];
        }
        if(a > b) return 1;
        else if(a < b) return -1;
        i++;
        j++;
    }
    return 0;
}
static bool compareVec(const vector<int>& a, const vector<int>& b){
    return a[0] > b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()) return {};
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), compareVec);
    for(int i = 0; i < intervals.size(); ++i){
        if(i == 0) res.push_back(intervals[i]);

        // 判断
        if(res.back()[1] < intervals[i][0]) res.push_back(intervals[i]);
        else if(res.back()[1] < intervals[i][1]) res.back()[1] = intervals[i][1];
        else continue;
    }
}

int main(){
    char c = '1';
    char c_new = c + 256;
    cout<<c<<" "<<c_new;

    return 0;
}
//
// Created by yang zhengtao on 2021/7/21.
//
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, set<int>> umap;
set<int> corner_index{0, 2, 6, 8};
int entryTime(string& s, string& keypad, int index_next, int curr_pos){
    if(index_next == s.size()) return 0;

    int curr_time = 0;
    int next_pos = keypad.find(s[index_next]);
    if(next_pos == curr_pos) curr_time = 0;
    else if(curr_pos == 4) curr_time = 1;
    else if(corner_index.count(curr_pos)){
        if(umap[curr_pos].count(next_pos)) curr_time = 1;
        else curr_time = 2;
    }


    return curr_time + entryTime(s, keypad, ++index_next, next_pos);
//    return 0;
}

int entryTime(string s, string keypad){
    int len = s.length();
//    return entryTime(s, keypad, 0);

}
int main(){
    string s = "423692";
    string  keypad = "923857614";

    int pos = keypad.find(s[0]);
    cout<<pos;
    return 0;

}

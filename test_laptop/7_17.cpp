//
// Created by yang zhengtao on 2021/7/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
bool my_compare(const string& lhs, const string& rhs){
    return lhs.length() > rhs.length() || (lhs.length() == rhs.length() && lhs < rhs);
}

bool is_composed_str(const set<string>& group, string str){
    if(str.empty()) return true;

    int n = str.length();
    for(int i = 0; i < n; ++i){
        if(group.count(str.substr(0, i + 1)) && is_composed_str(group, str.substr(i + 1))){
            return true;
        }
    }
    return false;
}

int main(){
    vector<string> vec = {"cat","banana","dog","nana","walk","walker","bananacat","dogwalker"};
    sort(vec.begin(), vec.end(), my_compare);

//    int max_len = vec[-1].length();
    set<string> res;

    for(auto str : vec){
        res.insert(str);
    }

    for(auto str: vec){
        res.erase(str);
        if(is_composed_str(res, str)){
            cout<<str<<endl;
            break;
        }
        res.insert(str);
    }
    cout<<"End\n";
    return 0;
}

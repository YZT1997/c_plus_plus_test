#include <bits/stdc++.h>

using namespace std;

inline void get_line(string& str){
    getline(cin>>ws, str);
}

const int max_len = 101;
vector<vector<pair<int, int>>> m(max_len);
vector<int> is_visited(max_len, 0);
int n, start;

bool is_digits(const char c){
    if('0' <= c && c <= '9') return true;
    return false;
}

vector<int> split_str(const string & str){
    int len = str.size(), start = 0;
    vector<int> res;
    while(start < n && res.size() < 3){
        while(start < n && !is_digits(str[start])) start++;
        if(start < len){
            int curr_num = 0;
            while(start < n && is_digits(str[start])){
                curr_num = curr_num * 10 + str[start] - '0';
                ++start;
            }
            res.push_back(curr_num);
        }
    }
    return res;
}

int dfs(int curr_pos){
    int res = 0;
    for(auto [v, dist] : m[curr_pos]){
        res = max(res, dist + dfs(v));
    }
    return res;

}

int main(){
    for(int i = 0; i < max_len; ++i){
        m.resize(0);
    }
    while(true){
        string str;
        get_line(str);
        if(str[0] == '['){
            vector<int> res = split_str(str);
            m[res[0]].emplace_back(res[1], res[2]);
        }
        else{
            n = atoi(str.c_str());
            get_line(str);
            start = atoi(str.c_str());
            break;
        }
    }

    int res = dfs(start);
    for(int i = 0; i <= n; ++i){
        if(!is_visited[i]){
            res = -1;
            break;
        }

    }
    cout<<res<<endl;
    return 0;
}
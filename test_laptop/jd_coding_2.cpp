//
// Created by yang zhengtao on 2021/9/11.
//
#include <bits/stdc++.h>

using namespace std;

const int k_max_len = 1000;

vector<int> depends[k_max_len];// up
vector<int> depended[k_max_len];// down

vector<int> status(k_max_len, 0);
set<int> is_opened;

void start(int curr_ind){
    if(!status[curr_ind]){
        for(int i = 0; i < depends[curr_ind].size(); ++i){
            start(depends[curr_ind][i]);
        }
        status[curr_ind] = 1;
        is_opened.insert(curr_ind);
    }
}

void close(int curr_ind){
    if(status[curr_ind]){
        for(int i = 0; i < depended[curr_ind].size(); ++i){
            close(depended[curr_ind][i]);
        }
        status[curr_ind] = 0;
        is_opened.erase(curr_ind);
    }
}

int main(){
    int n, q;
    cin>>n>>q;
    int c;
    for(int i = 0; i < n; ++i){
        cin>>c;
        int son;
        for(int j = 0; j < c; ++j){
            cin>>son;
            depends[i + 1].push_back(son);
            depended[son].push_back(i + 1);
        }
    }
    int x, y;
    for(int i = 0; i < q; ++i){
        cin>>x>>y;
        if(x == 1){
            start(y);
        }
        else if(x == 0){
            close(y);
        }
        cout<<is_opened.size();
    }
    return 0;
}

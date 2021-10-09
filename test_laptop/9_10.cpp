//
// Created by yang zhengtao on 2021/9/10.

#include <bits/stdc++.h>
using namespace std;

int get_index(const int num){
    int i = 1;
    while(2 * i < num){
        i = 2 * i;
    }
    return i;
}

int get_res(const vector<int>& vec, int row, int col){
    if(1 <= row && row <= 2 && 1 <= col && col <= 2){
        if(row == 1 && col == 1) return vec[0];
        else if(row == 1 && col == 2) return vec[1];
        else if(row == 2 && col == 2) return vec[2];
        else return vec[3];
    }

    int n_row = get_index(row) ;
    int n_col = get_index(col) ;
    int res = 0;
    if(row > n_col && col > n_row){
        res = vec[2] + get_res(vec, row - n_row, col - n_col);
    }
    else if(row <= n_col && col > n_row){
        res = vec[1] + get_res(vec, row, col - n_col);
    }
    else if(row > n_col && col <= n_row){
        res = vec[3] + get_res(vec, row - n_row, col);
    }
    return res;
}

void solve(){
//    (4, 0);
//    for(int i = 0; i < 4; ++i){
//        cin>>coov[i];
//    }
    vector<int> coov = {1, 2, 3, 4};

//    int n = 0;
//    cin>>n;
    int res = 0;
    for(int row = 1; row <= 8; ++row){
        for(int col = 1; col <= 8; ++col){
            res = get_res(coov, row, col);
            cout<<res<<" ";
        }
        cout<<endl;
    }
}

int main(){
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(1);
    s.erase(1);
    for(auto num : s){
        cout<<num<<" ";
    }

    return 0;

}

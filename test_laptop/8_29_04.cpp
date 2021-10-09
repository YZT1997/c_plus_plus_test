//
// Created by yang zhengtao on 2021/8/29.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<int>> grass(n + 1, vector<int>(m + 1, 0));
    long long res = 0;

    int x, y, r;
    for(int day = 1; day <= k; ++day){
        cin>>x>>y>>r;
        for(int i = x - r; i <= x+ r; ++i){
            for(int j = y-r; j <= y + r; ++j){
                if(sqrt((i - x)*(i - x) + (j - y)*(j - y)) <= r){
                    grass[i][j] = day;
                }
//                if((abs(x - i) + abs(y - j)) <= r){
//                    grass[i][j] = day;
//                }
            }
        }
    }
    for(int i = 1; i<= n; ++i){
        for(int j = 1; j <= m; ++j){
            res += k - grass[i][j];
        }
    }
    cout<<res<<endl;
    return 0;
}

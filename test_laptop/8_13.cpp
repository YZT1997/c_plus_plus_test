//
// Created by yang zhengtao on 2021/8/13.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n = 0, l = 0, r = 0;
    cin>>n>>l>>r;
    vector<int> vec(n + 1, 0);
    for(int i = 1; i <= n - 1; ++i){
        int last_len = n % i;
        for(int j = n; j > n - last_len; --j){
            vec[j]++;
        }
    }
    for(int i = l; i <= r; ++i){
        cout<<vec[i]<<" ";
    }
    return 0;
}

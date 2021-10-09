//
// Created by yang zhengtao on 2021/8/29.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i) {
        cin>>vec[i];
    }

    vector<int> dp(31, 0);
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < vec[i]; ++j){
            if(dp[j]) ++res;
        }
        dp[vec[i]]++;
    }
    cout<<res<<endl;
    return 0;

}

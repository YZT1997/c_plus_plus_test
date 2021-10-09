//
// Created by yang zhengtao on 2021/8/29.
//
#include <bits/stdc++.h>

using namespace std;
const long long max_len = 1000000007;

int main(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
    for(int i = 0; i < n; ++i){
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long res = 1;
    for(int i = n - 1; i >= 0; --i){
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        res *= (i + 1 - pos);
        res %= max_len;
    }
    cout<<res % max_len<<endl;
    return 0;

}

//
// Created by yang zhengtao on 2021/6/14.
//
#include<iostream>
#include<vector>
#include <set>
#include <algorithm>

using namespace std;
int res = 0;    // 总喝的瓶数
int num_a = 0;    // 换地的瓶数
int num_b = 0;    // 交换之后剩下的空瓶数
int max_bottle(int n){
    if(n <= 1) return res;
    else if(n == 2) return res += 1;
    else if(n >= 3){
        num_a = n / 3;
        num_b = n % 3;
        res += num_a;
        num_b += num_a;
        return max_bottle(num_b);
    }
}
int main(){
    int n = 0;
    while(cin>>n){
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            int val;
            cin>>val;
            vec.push_back(val);
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); ++i){
            if(vec[i] == vec[i + 1]) continue;
            cout<<vec[i]<<endl;
        }
    }

    return 0;
}

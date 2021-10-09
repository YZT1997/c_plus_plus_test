//
// Created by yang zhengtao on 2021/8/30.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int factorial(int n){
    if(n < 0) return -1;
    else if(n == 0) return 1;

    int res = 1;
    while (n >= 1){
        res *= n;
        n--;
    }
    return res;
}
int trap(vector<int>& height) {
    if(height.empty()) return 0;

    int n = height.size();
    vector<int> left(n, 0), right(n, 0);
    for(int i = 1; i < n; ++i){
        left[i] = max(left[i - 1], height[i - 1]);
    }
    for(int i = n - 2; i >= 0; --i){
        right[i] = max(right[i + 1], height[i + 1]);
    }

    int res = 0;
    for(int i = 0; i < n; ++i){
        if(min(left[i], right[i]) <= height[i]) continue;
        res += (min(left[i], right[i]) - height[i]);
    }
    return res;

}

int main(){
//    int n, m;
//    cin>>n>>m;
//    int count = 0;
//    int min_a_1 = 1, max_a_m = n / 7;
//
//    for(int i = min_a_1; i * 3 <= n; ++i){
//        for(int j = max_a_m; 7 * j - 3 * i >= m - 1;--j){
//            int mid_len = 7 * j - 3 * i - 1;
//            count += factorial(mid_len) / (factorial(m - 2) * factorial(mid_len - m + 2));
//        }
//    }
//    cout<<count;
//    return 0;
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    int res = trap(height);
    cout<<res;
    return 0;


}


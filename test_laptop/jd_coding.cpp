//
// Created by yang zhengtao on 2021/9/11.
//
#include <bits/stdc++.h>

using namespace std;

//void solve(){
//    int n, q;
//    cin>>n>>q;
//
//}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; ++i){
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end(), greater<int>());

    int max_num = nums[0], min_num = nums[n - 1];
    int next_max_ind = 1, next_min_ind = n - 1 -1;
    int sum = max_num - min_num;

    while(next_max_ind < next_min_ind){
        int curr_sum = max_num - nums[next_min_ind] + nums[next_max_ind] - min_num;
        sum += curr_sum;
        max_num = nums[next_max_ind++];
        min_num = nums[next_min_ind--];
    }
    if(max_num - nums[next_min_ind] > nums[next_max_ind] - min_num){
        sum += (max_num - nums[next_min_ind]);
    } else{
        sum += (nums[next_max_ind] - min_num);
    }
    cout<<sum<<endl;
    return 0;

}

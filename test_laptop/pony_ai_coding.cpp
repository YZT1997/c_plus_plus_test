//
// Created by yang zhengtao on 2021/9/26.
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//int main(){
//    int n;
//    cin>>n;
//    vector<int> nums(n, 0);
//    for(int i = 0; i < n; ++i){
//        cin>>nums[i];
//    }
//    sort(nums.begin(), nums.end());
//    long long res = 0;
//    for(int i = 1; i < n; ++i){
//        res += pow((nums[i] - nums[i - 1]), 2);
//    }
//    cout<<res<<"\n";
//    return 0;
//}
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(){
//    string str;
//    cin>>str;
//
//    int size = str.length();
//    vector<int> prev_ind(26, -1);
//    vector<int> max_gap(26, 0);
//
//    for(int i = 0; i < size; ++i){
//        int curr_len = i - prev_ind[str[i] - 'a'];
//        max_gap[str[i] - 'a'] = max(curr_len, max_gap[str[i] - 'a']);
//        prev_ind[str[i] - 'a'] = i;
//    }
//
//    int min_len = size;
//    for(int i = 0; i < 0; ++i){
//        max_gap[i] = max(max_gap[i], size - prev_ind[i]);
//        min_len = min(min_len, max_gap[i]);
//    }
//    cout<<min_len;
//    return 0;
//}
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> parent(100001, 0);
//vector<int> min_cost(100001, INT_MAX);
//
//int find_parent(const int son){
//    if(son == parent[son]){
//        return son;
//    }
//    return find_parent(parent[son]);
//}
//
//void union_group(const int a, const int b){
//    int parent_a = find_parent(a), parent_b = find_parent(b);
//    if(parent_a != parent_b){
//        if(min_cost[parent_a] > min_cost[parent_b]) swap(parent_a, parent_b);
//        parent[parent_b] = parent_a;
//        min_cost[parent_a] = min(min_cost[parent_a], min_cost[parent_b]);
//        min_cost[parent_b] = min_cost[parent_a];
//    }
//}
//
//
//int main(){
//    int n, m;
//    cin>>n>>m;
//    vector<int> cost(n + 1, 0);
//    vector<bool> is_vis(n + 1, false);
//    for(int i = 1; i <= n; ++i){
//        cin>>cost[i];
//        parent[i] = i;
//        min_cost[i] = cost[i];
//    }
//    int x, y;
//    for(int i = 0; i < m; ++i){
//        cin>>x>>y;
//        union_group(x, y);
//    }
//
//    long long res = 0;
//    for(int i = 1; i <= n; ++i){
//        int curr_parent = find_parent(i);
//        if(!is_vis[curr_parent]){
//            res += min_cost[curr_parent];
//            is_vis[curr_parent] = true;
//        }
//    }
//    cout<<res<<"\n";
//    return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin>>nums[i];
    }
    vector<int> dp(n, 0);
    for(int i = n - 2; i >= 0; --i){
        if(nums[i] <= 0) continue;
        if(nums[i] == 1) dp[i] += (n - 1 - i);
        for(int j = i + 1; j < n; ++j){
            if(nums[i] == nums[j] + 1){
                dp[i] += (dp[j] % 998244353);
            }
        }
    }
    long long res = 0;
    for(auto num : dp){
        res += num;
    }
    cout<<res<<"\n";
    return 0;
}
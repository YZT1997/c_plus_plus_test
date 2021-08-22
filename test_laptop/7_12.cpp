//
// Created by yang zhengtao on 2021/7/12.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int search_copy(vector<int>& arr, int target) {
    // error case
    if(arr.empty()) return -1;

    int left = 0, right = arr.size() - 1;   // 查找区间[0, arrSize - 1]
    while (left <= right) {                //  维持在区间 [left, right] 中查找，循环不变量
        int mid = left + (right - left) / 2;     //  防止整型溢出
        if (arr[left] < arr[mid]) {
            if (arr[left] <= target && target <= arr[mid]) {    //  目标元素在[left, mid] 区间，缩小右边界
                right = mid;
            } else {                                         //  目标元素在（mid, right] 区间
                left = mid + 1;
            }
        } else if (arr[left] > arr[mid]) {
            if ((arr[mid] < target) && ((target <= arr[right]) && (arr[left] > arr[right]) || target < arr[right])) {  //  目标元素在（mid, right] 区间
                left = mid + 1;
            } else {                      //  目标元素在[left, mid] 区间
                right = mid;
            }
        } else if (arr[left] == arr[mid]) {  // 存在重复的元素
            if (arr[left] != target) {
                left++;
            } else {
                return left;
            }
        }
    }
    return -1;


}
int search(vector<int>& arr, int target) {
    // error case
    if(arr.empty()) return -1;

    int left = 0, right = arr.size() - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[left] < arr[mid]){
            if(arr[left] <= target && target <= arr[right]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        else if(arr[left] > arr[mid]){
            if((arr[mid] < target) && ((target <= arr[right]) && (arr[left] > arr[right]) || target < arr[right])) {
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        else if(arr[left] == arr[mid]){
            if(arr[left] != target){
                left++;
            }
            else{
                return left;
            }
        }
    }
    return -1;
}
int waysToChange(int n) {
    if(n < 0) return 0;
    vector<int> dp(n + 1, 0);
    vector<int> coins{1, 5, 25, 50};
    dp[0] = 1;

    for(auto coin : coins){
        for(int i = coin; i <= n; ++i){
            dp[i] += dp[i - coin];
        }
    }

    return dp[n] % 1000000007;
}

int main(){
    stack<int> stk ;
    stk.top();
    return 0;
}

//
// Created by yang zhengtao on 2021/5/3.
//
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
template<typename T>
bool isEven(const T& num){
    return (num % 2) == 0;
}
template<typename T>
bool compare(const T& a, const T& b){
    return a  > b;
}

template<typename T>
void display(const T& container){
    for(auto iter = container.cbegin(); iter != container.cend(); ++iter){
        std::cout<<*iter<<" ";
    }
    std::cout<<"\n";
}
using namespace std;

int search(vector<int>& nums, int target) {
    // 变种的二分查找，需要比较left, mid
    if(nums.size() == 1){
        return (nums[0] == target)?0 : -1;
    }

    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target) return mid;

            // 判断哪一侧为顺序
        else if(nums[left] < nums[mid]){
            if(nums[left] <= target && target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }

        }
    }
    return -1;

}

class Fish{
public:
    Fish(){cout<<"Fish constructed"<<endl;}
    ~Fish(){cout<<"Fish Destructed"<<endl;}

    void Swim() const{cout<<"Fish swims in water"<<endl;}
};

void MakeFishSwim(const unique_ptr<Fish>& inFish){
    inFish->Swim();
}
int maxProfit(vector<int>& prices) {
    // dp[i][j][k] = 赚的的钱数,0 <= i < prices.size(), 1 <= j <= maxBusinessCount, k = 0(持有股票)，1(无股票)

    int n = prices.size();
    int maxBusinessCount = 2;
//    int dp[n][maxBusinessCount + 1][2];
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxBusinessCount + 1, vector<int>(2, 0)));
    for (int j = 0; j <= maxBusinessCount; ++j) {
        dp[0][j][1] = -prices[0];
        dp[0][j][0] = 0;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= maxBusinessCount; ++j){
            if(i == 0){
                dp[0][j][1] = -prices[0];
                dp[0][j][0] = 0;
                continue;
            }
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);    // 第 i + 1 天没有持有股票，最大收益
        }
    }
    return dp[n - 1][maxBusinessCount][0];


}
int main(){
    vector<int> vec{7,6,4,3,1};

    cout<<maxProfit(vec);
    return 0;
}
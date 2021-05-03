//
// Created by yang zhengtao on 2021/4/13.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
class Cup{
public:
    explicit Cup(int r = 0, int h = 0);
    static int num;
    int CalVolume(){
        return radius_ * height_;
    }
private:
    int radius_ = 0;
    int height_ = 0;
};
Cup::Cup(int r, int h):radius_(r), height_(h) {

}
int Cup::num = 0;

using namespace std;
int main(){
    vector<int> nums{0, 2, 0, 2, 0, 3, 2, 1, 1, 1};
//    unordered_map<int, int> umap;
//
//    for(int i = 1; i < nums.size(); i++){
//        umap[nums[i]]++;
//    }
//    int a = 0;
//
//    for(auto iter = umap.begin(); iter != umap.end(); iter++){
//        if(iter->second == 1){
//            a =  iter->first;
//            break;
//        }
//    }
//    cout<<a;
//    int ones = 0, twos = 0;
//    for(int num : nums){
//        ones = ones ^ num & ~twos;
//        twos = twos ^ num & ~ones;
//    }
//    cout<<ones;
//    cout<<1 ^ 0 & ~1;

    return 0;
}
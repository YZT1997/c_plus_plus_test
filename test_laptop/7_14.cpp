//
// Created by yang zhengtao on 2021/7/14.
//
#include <iostream>
#include <vector>

using namespace std;

bool is_valid(int n){
    //
    if(n == 1) return false;
    else if(n == 2) return true;
    else if(n == 3) return true;

//    vector<bool> vec(n + 1, 0);
    for(int i = 2; i * i <= n; ++i){
        //
        for(int j = 2; i * j <= n; ++j){
            // 只判断n
            if(i * j == n) return false;
//            if(vec[i * j] == true) continue;
//            vec[j] = true;
        }
    }

    return true;
}

int main(){
    // 判断
    bool is_sushu = is_valid(111);

    // print
    int n = 100;
    vector<bool> vec(n + 1, true);
    // 1, 2,
    vec[1] = false;
    vec[2] = true;
    vec[3] = true;

    for(int i = 2; i * i <= n; ++i){
        //
        for(int j = 2; i * j <= n; ++j){
            //
            if(vec[i * j] == false) continue;
            vec[i * j] = false;
        }
    }
    for(int i = 1; i <= n; ++i){
        if(vec[i] == true){
            cout<<i<<endl;
        }
    }

    return 0;

}
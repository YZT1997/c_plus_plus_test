//
// Created by yang zhengtao on 2021/8/21.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    vector<int> vec;
    stringstream sstr(str);
    while(getline(sstr, str,' ')){
        vec.push_back(stoi(str));
    }
    vec.push_back(vec[0]);
    int n = vec.size();

    vector<int> left_vec(n, 0);
    for(int i = 0; i < n; ++i){
        if(i > 0 && vec[i] > vec[i - 1]){
            left_vec[i] = left_vec[i - 1] + 1;
        }
        else{
            left_vec[i] = 1;
        }
    }
    int res = 0;
    int right = 0;
    for(int i = n - 1; i >= 1; --i){
        if(i < n - 1 && vec[i] > vec[i + 1]){
            right++;
        }
        else{
            right = 1;
        }
        res += max(left_vec[i], right);
    }
    cout<<res;
}

//
// Created by yang zhengtao on 2021/7/14.
//
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool is_valid(string str){
    int len = str.length();
    int point_count = 0;
    int prev_point = 0;

//    vector<int> vec;
    for(int i = 0; i < len; ++i){
        if(str[i] == '.'){
//            string str_temp = str.substr(prev_point, i - prev_point);
            if(i - prev_point > 4 || i - prev_point <= 1){
//                cout<<i<<" "<<prev_point;
                return false;
            }
//            vec.push_back(stoi(str_temp));
            prev_point = i;
            point_count++;
        }
    }
    if(point_count > 3) return false;
    if(len - prev_point > 4) return false;
    return true;

}

int main(){
    string str = "172.0.0.1";
//    cin>>str;
    bool res = is_valid(str);
    return 0;


}

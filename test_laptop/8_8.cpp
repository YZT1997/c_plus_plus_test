//
// Created by yang zhengtao on 2021/8/8.
//
#include <iostream>
#include <string>

using namespace std;
bool is_valid_input(const char c){
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
int main(){
    string str;
    getline(cin, str);

    string res;
    for(auto c : str){
        if(is_valid_input(c) && c != res.back()){
            res += c;
        }
    }
    cout<<res<<endl;
    return 0;
}


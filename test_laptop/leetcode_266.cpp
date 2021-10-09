//
// Created by yang zhengtao on 2021/8/27.
//
#include <iostream>
#include <string>

using namespace std;

int main(){
    string str="aab", str2 = "carefrac";

    int b = 0;
    for(auto c : str2){
        b = b ^ c;
    }
    cout<<b<<endl;
    cout<<(int)'a'<<" "<<(int)'z'<<endl;
    return 0;
}

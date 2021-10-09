//
// Created by yang zhengtao on 2021/9/5.
//
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkValidString(string s){
    stack<int> left_stk, star_stk;
    int n = s.length();
    for(int i = 0; i < n; ++i){
        // 记录索引号，以实现左括号必须在右括号之前的正确性验证
        auto c = s[i];
        if(c == '(') left_stk.push(i);
        else if(c == '*') star_stk.push(i);
        else if(c == ')'){
            if(left_stk.empty() && star_stk.empty()) return false;
            if(!left_stk.empty()) left_stk.pop();
            else star_stk.pop();
        }
    }

    while (!left_stk.empty() && !star_stk.empty()){
        if(star_stk.top() < left_stk.top()) return false;
        left_stk.pop();
        star_stk.pop();
    }
    return left_stk.empty();
}
int main(){
    char c = '*';
    printf("%d",c);

    return 0;
}

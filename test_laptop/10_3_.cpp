//
// Created by yang zhengtao on 2021/10/3.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    string str;

    long num = (long )numerator;
    long dem = (long) denominator;
    if((num < 0 && dem > 0) || (num > 0 && dem < 0)) str += "-";

    num = abs(num);
    dem = abs(dem);

    str += to_string(num / dem);
    if(num % dem == 0) return str;

    str.push_back('.');

    map<int, int> index_pos;
    while((num = (num % dem) * 10) > 0 && !index_pos.count(num)){
        index_pos[num] = str.length();
        str += to_string(num / dem);
    }
    if(num == 0) return str;

    str.insert(str.begin() + index_pos[num], 1, '(');
    str.insert(str.end(), 1, ')');
    return str;
}

int main(){
    string res = fractionToDecimal(-50, 8);
    cout<<res;
    return 0;
}

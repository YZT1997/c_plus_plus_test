//
// Created by yang zhengtao on 2021/8/30.
//
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int num;
    cin>>num;
    double x = 1.0;
    while (abs(x * x * x - num) > 1e-7){
        x = x - (1.0 / 3.0) * x + (double )num / (3.0 * x * x);
    }
    cout<<x;
    return 0;
}

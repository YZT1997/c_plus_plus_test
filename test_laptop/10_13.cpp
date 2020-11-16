//
// Created by yang zhengtao on 2020/11/16.
//
// Use ordinary function to define function class
#include "iostream"
#include "numeric"
#include "functional"
#include "vector"
#include "algorithm"
using namespace std;

int mult(int x, int y){ return x * y;}
int main(){
    int a[5] = {2, 4, 6, 8, 10};
    const int N = sizeof(a) / sizeof(int );
//    cout<<"The result of multiplying all elements in a is "<<accumulate(a, a + 1, 1, mult)<<endl;
    cout<<"The result of multiplying all elements in a is "
    <<accumulate(a, a + N, 1, multiplies<int>())<<endl;

    return 0;
}

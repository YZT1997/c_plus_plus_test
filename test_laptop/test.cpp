//
// Created by yang zhengtao on 2020/10/23.
//
#include "iostream"
#include "BinaryTree.h"
using namespace std;

template <class T>
void swap2(T &x, T &y){
    T temp = x;
    x = y;
    y = temp;
}

int fib(int n){
    if (n < 2)
        return n;

    int value = fib(n - 1) + fib( n - 2);
    return value;
}

int fib2(int n){
    int f = 0, g = 1;
    while (0 < n--){
        g = g + f;
        f = g - f;
    }

    return g;
}

int *sum1(int &x1, int &x2){
    x1 = x1 + x2;
}
int main(){
    int x1 = 10, x2 = 20, sum;
    int *ptr = nullptr;
    ptr = sum1(x1, x2);
    cout<<sum1<<endl;
    return 0;
}

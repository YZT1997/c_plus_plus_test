//
// Created by yang zhengtao on 2021/2/1.
//
#include "iostream"
#include "stdio.h"
#include "vector"
#include "stack"


using namespace std;

int main(){
    int a = 10;
    int *ptr = &a;
    int **pPtr = &ptr;
    cout<<ptr<<" "<<pPtr<<endl;

    return 0;
}


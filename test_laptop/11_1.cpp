//
// Created by yang zhengtao on 2020/11/29.
//
#include "iostream"
#include "iomanip"
#include "string"
using namespace std;

int main(){
    double values[] = {1.23, 35.36, 653.7, 4358.24};
    string names[] = {"Hello", "My", "Pleasure", "Last"};
    for (int i = 0; i < 4; ++i) {
        cout<<setw(8)<<names[i]<<setw(10)<<values[i]<<endl;
    }
    return 0;
}

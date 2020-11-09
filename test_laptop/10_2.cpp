//
// Created by yang zhengtao on 2020/11/8.
//
#include "iterator"
#include "iostream"
#include "algorithm"

using namespace std;

double square(double x){
    return x * x;
}

void swap(double &x, double &y){
    double temp = x;
    x = y;
    y = temp;
}

int main(){
    transform(istream_iterator<double>(cin), istream_iterator<double>(), ostream_iterator<double>(cout,"\t"), square);
    cout<<endl;
    return 0;
}

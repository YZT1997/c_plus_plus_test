//
// Created by yang zhengtao on 2020/10/18.
//
#include "iostream"
#include "iomanip"
#include "Array.h"
using namespace std;

int main(){
    Array<int> a(5);
    int count = 0;

    int n;
    cout<<"Enter a thresh value >= 2";
    cin>>n;

    for (int i = 2; i < n; ++i) {
        bool isPrime = true;
        for (int j = 0; j < count; ++j) {
            if (a[j] % i == 0){
                isPrime = false;
                break;
            }
        }

        // put i in the array
        if (isPrime){
            // if the space is full, double it
            if (count == a.getSize()){
                a.resize(count + 1);
            }
            a[count++] = i;
        }
    }

    // print the prime number
    for (int i = 0; i < count; ++i) {
        cout<<setw(2)<<a[i];
    }
    cout<<endl;

    //copy
    Array<int> b(a);
    for (int i = 0; i < b.getSize(); ++i) {
        cout<<setw(2)<<b[i];
    }

    return 0;
}

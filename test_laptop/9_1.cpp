//
// Created by yang zhengtao on 2020/10/18.
//
#include "iostream"
using namespace std;

template <class T>
void outputArray(const T *array, int count){
    for (int i = 0; i < count; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    const int A_COUNT = 5, B_COUNT = 5;
    int aArray[A_COUNT] = {1, 2, 3, 5, 10};
    double bArray[B_COUNT] = {-0.9, 2.10, 9.2, 10.2, 3.2};
    char cArray[B_COUNT] = "hell";
    outputArray(aArray, A_COUNT);
    outputArray(cArray, B_COUNT);

    return 0;
}
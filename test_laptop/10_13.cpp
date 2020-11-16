//
// Created by yang zhengtao on 2020/11/16.
//
// Use ordinary function to define function class
#include "iostream"
#include "numeric"
#include "functional"
#include "vector"
#include "algorithm"
#include "iterator"
using namespace std;

int mult(int x, int y){ return x * y;}
int main(){
    int a[5] = {200, 14, 36, 81, 130};
    const int N = sizeof(a) / sizeof(int );
    vector<int> array(a, a + N);
    cout<<"Before sorting"<<endl;
    copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;

    sort(array.begin(), array.end(), less<int>());

    cout<<"After sorting"<<endl;
    copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}

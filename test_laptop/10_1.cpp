//
// Created by yang zhengtao on 2020/11/8.
//
#include "iostream"
#include "vector"
#include "iterator"
#include "algorithm"
#include "functional"

using  namespace std;

int main(){
    const int N = 10;
    vector<int> s(N);

    cout<<"Please enter 10 numbers";
    for (int i = 0; i < N; ++i) {
        cin>>s[i];
    }
    transform(s.begin(), s.end(), ostream_iterator<int>(cout, " "), negate<int>());
    cout<<endl;
    return 0;
}
//
// Created by yang zhengtao on 2020/11/9.
//
#include "iostream"
#include "deque"
#include "algorithm"
#include "vector"
#include "iterator"

using namespace std;

int main(){
    istream_iterator<int> i1(cin), i2;
    vector<int>s1(i1, i2);
    sort(s1.begin(), s1.end());
    deque<int>s2;

    //遍历s1
    for (vector<int>::iterator iterator = s1.begin(); iterator != s1.end() ; ++iterator) {
        if (* iterator%2 == 0)
            s2.push_back(*iterator);
        else
            s1.push_back(*iterator);
    }

    //output
    copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}
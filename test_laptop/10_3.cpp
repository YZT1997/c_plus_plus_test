//
// Created by yang zhengtao on 2020/11/8.
//
#include "iostream"
#include "iterator"
#include "vector"
#include "algorithm"

using namespace std;

template<class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result){
    // use InputIterator p to put input data in container s
    vector<T> s;
    for (;first != last; ++first) {
        s.push_back(*first);
    }
    sort(s.begin(), s.end());       // sort s
    copy(s.begin(), s.end(), result);
}

int main(){
    // Sort s and output
    double a[5] = {1.2, 3.0, 10.8, 3.4, 100.9};
    mySort<double>(a, a+5, ostream_iterator<double>(cout, " "));
    cout<<endl;

    cout<<"Please enter 5 integers"<<endl;
    mySort<double>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<double>(cout, " "));
    cout<<endl;
    return 0;

}

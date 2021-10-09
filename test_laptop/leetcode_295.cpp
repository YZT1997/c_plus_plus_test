//
// Created by yang zhengtao on 2021/8/27.
//
#include <iostream>
#include <set>

using namespace std;

class MedianFinder{
public:
    MedianFinder(){}

    void addNum(int num){
        if(max_heap_.empty() || num >= *max_heap_.begin() ){
            max_heap_.emplace(num);
            if(max_heap_.size() > min_heap_.size() + 1){
                min_heap_.insert(*max_heap_.begin());
                max_heap_.erase(max_heap_.begin());
            }
        }

        else{
            min_heap_.insert(num);
            if(min_heap_.size() > max_heap_.size()){
                max_heap_.insert(*min_heap_.begin());
                min_heap_.erase(min_heap_.begin());
            }
        }

    }

    double findMedian(){
        if(max_heap_.size() == min_heap_.size()){
             long long res = *max_heap_.begin() + *min_heap_.begin();
             return (double ) res / 2;
        }
        return (double )*max_heap_.begin();
    }

private:
    set<int, less<int>> max_heap_;
    set<int, greater<int>> min_heap_;
};

int main(){
    MedianFinder medianFinder;
    medianFinder.addNum(5);
    medianFinder.addNum(10);
    medianFinder.addNum(-1);
    medianFinder.addNum(4);
    cout<<medianFinder.findMedian();

    return 0;
}


//
// Created by yang zhengtao on 2021/8/22.
//
#include "PrototypeWork.h"
#include <queue>
#include <set>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> p_queue;

    p_queue.emplace(10);
    p_queue.emplace(5);
    p_queue.emplace(1);

    while(!p_queue.empty()){
        printf("%d \n", p_queue.top());
        p_queue.pop();
    }

    return 0;
}

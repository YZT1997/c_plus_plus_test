//
// Created by yang zhengtao on 2020/10/23.
//
#include "iostream"
#include "Stack.h"
#include "Queue.h"
using namespace std;


int main(){
    Stack<int> stack;
    Queue<int> queue;
    for (int i = 0; i < 10; ++i) {
        stack.push(i+1);
        queue.insert(i+1);

    }
    cout<<"Peek"<<stack.peek()<<endl;
    while (!stack.isEmpty()){
        cout<<stack.pop()<<" ";
    }
    cout<<endl;
    while (!queue.isEmpty()){
        cout<<queue.remove()<<" ";
    }
    stack.clear();
    queue.clear();
    return 0;
}

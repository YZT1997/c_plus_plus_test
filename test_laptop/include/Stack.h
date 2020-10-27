//
// Created by yang zhengtao on 2020/10/27.
//

#ifndef TEST_LAPTOP_STACK_H
#define TEST_LAPTOP_STACK_H

#include "cassert"

template <class T, int SIZE = 50>
class Stack{
private:
    T list[SIZE];
    int top;            // pos of top in the stack
public:
    Stack();
    void push(const T &item);       // push item in
    T pop();                        // pop out the top item
    void clear();                   // clear
    const T &peek() const;          // call top item(not change)
    bool isEmpty() const;
    bool isFull() const;
};

template <class T, int SIZE>
Stack<T, SIZE>::Stack():top(-1) {}  // top init = -1

template <class T, int SIZE>
void Stack<T, SIZE>::push(const T &item) {
    assert(!isFull());
    list[++top] = item;             // Not (top++), top需要先+1再赋值给数组下标
}

template <class T, int SIZE>
T Stack<T, SIZE>::pop() {
    assert(!isEmpty());
    return list[top--];
}

template <class T, int SIZE>
const T &Stack<T, SIZE>::peek() const {
    assert(!isEmpty());
    return list[top];
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const {
    return top == -1;
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isFull() const {
    return top == SIZE - 1;
}

template <class T, int SIZE>
void Stack<T, SIZE>::clear() {
    top = -1;
}
#endif //TEST_LAPTOP_STACK_H

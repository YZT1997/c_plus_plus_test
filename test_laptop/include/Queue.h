//
// Created by yang zhengtao on 2020/10/27.
//

#ifndef TEST_LAPTOP_QUEUE_H
#define TEST_LAPTOP_QUEUE_H
#include "cassert"

template <class T, int SIZE=50>
class Queue{
private:
    int front, rear, count;         // ptr of start, end; num of members
    T list[SIZE];
public:
    Queue();
    void insert(const T &item);
    T remove();
    void clear();
    const T &getFront() const;

    // Get state of queue
    int getLength() const;
    bool isEmpty() const;
    bool isFull() const;
};

template<class T, int SIZE>
Queue<T, SIZE>::Queue():front(0),rear(0),count(0) {}

template<class T, int SIZE>
void Queue<T, SIZE>::insert(const T &item) {
    assert(count!=SIZE);
    count++;
    list[rear]=item;
    rear = (rear+1)%SIZE;           // rear+1, use % to do recursion work
}

template<class T, int SIZE>
T Queue<T,SIZE>::remove() {
    assert(count!=0);
    int temp = front;
    count--;
    front = (front+1)%SIZE;
    return list[temp];
}

template<class T, int SIZE>
const T &Queue<T,SIZE>::getFront() const {
//    assert(count==0);
    return list[front];
}

template <class T, int SIZE>
int Queue<T,SIZE>::getLength() const {
    return count;
}

template<class T, int SIZE>
bool Queue<T,SIZE>::isEmpty() const {
    return count == 0;
}

template<class T, int SIZE>
bool Queue<T,SIZE>::isFull() const {
    return count == SIZE;
}

template<class T, int SIZE>
void Queue<T,SIZE>::clear() {
    front = 0;
    rear = 0;
    count = 0;
}
#endif //TEST_LAPTOP_QUEUE_H

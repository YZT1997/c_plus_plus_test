//
// Created by yang zhengtao on 2021/1/29.
//

#ifndef TEST_LAPTOP_LINKQUEUE_H
#define TEST_LAPTOP_LINKQUEUE_H

template<class T>
class LinkQueue
{
private:
    struct Node{
        T data;
        Node *next;
        Node(const T &x, Node *ptr = nullptr){data = x; next = ptr;}
        Node():next(nullptr){}
        ~Node(){}
    };
    Node *front, *rear;

public:
    LinkQueue(){front = rear = nullptr;}
    ~LinkQueue();
    bool isEmpty() const{return rear == nullptr;}
    void enQueue(const T &x);
    T deQueue();
    T getHead() const{return front->data;}
};

template<class T>
LinkQueue<T>::~LinkQueue<T>() {
    Node *tmp;
    while (front != nullptr){
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template<class T>
void LinkQueue<T>::enQueue(const T &x) {
    if (rear == nullptr){
        front = rear = new Node(x);
    } else{
        rear = rear->next = new Node(x);
    }
}

template<class T>
T LinkQueue<T>::deQueue() {
    Node *tmp;
    T value = front->data;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete tmp;
    return value;
}


#endif //TEST_LAPTOP_LINKQUEUE_H

//
// Created by yang zhengtao on 2020/10/19.
//

#ifndef TEST_LAPTOP_NODE_H
#define TEST_LAPTOP_NODE_H

// class template

template <class T>
class Node{
private:
    Node<T> *next;      // ptr to the next node
public:
    T data;             // data

    Node(const T &data, Node<T> *next = 0); // Constructor function
    void insertAfter(Node<T> *ptr);         // Insert a new same type node
    Node<T> *deleteAfter();
    Node<T> *nextNode();
    const Node<T> *nextNode() const;        // Get the address of next node
};

// Constructor function, init
template <class T>
Node<T>::Node(const T &data, Node<T> *next/* = 0*/) :data(data), next(next){}

// Return the ptr of next node
template <class T>
Node<T> *Node<T>::nextNode() {
    return next;
}

// Const return the ptr of next node
template <class T>
const Node<T> *Node<T>::nextNode() const{
    return next;
}

// Insert a node p before current node
template <class T>
void Node<T>::insertAfter(Node<T> *ptr) {
    ptr->next = next;           // ptr points to the node after the next
    next = ptr;                 // current ptr to
}

// Delete the next node after to current node
template <class T>
Node<T> *Node<T> ::deleteAfter() {
    Node<T> *tempPtr = next;        // Store the current ptr
    if (next == 0){                 // decide whether this is the end
        return 0;
    }
    next = tempPtr->next;           // point to the next node
    return tempPtr;                 // return the ptr of deleted node
}

#endif //TEST_LAPTOP_NODE_H
